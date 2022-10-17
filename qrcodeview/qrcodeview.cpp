#include "qrcodeview.h"
#include <QtGui/QPainter>
#include <iostream>

QRcodeView::QRcodeView(const QString &text, QWidget *parent)
    : QWidget(parent)
{
    setText(text);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    resize(sizeHint());
}

QRcodeView::QRcodeView(QWidget *parent)
    : QRcodeView("", parent)
{
}

QRcodeView::~QRcodeView()
{
    if (m_qrcode) {
        QRcode_free(m_qrcode);
    }
}

const QString &QRcodeView::text() const
{
    return m_text;
}
void QRcodeView::setText(const QString &text)
{
    m_text = text;
    if (m_qrcode != nullptr) {
        QRcode_free(m_qrcode);
    }
    m_qrcode = QRcode_encodeData(m_text.size(), reinterpret_cast<const unsigned char *>(m_text.toStdString().c_str()), 0, QR_ECLEVEL_H);
    update();
}

const QColor &QRcodeView::lightColor() const
{
    return m_lightColor;
}

void QRcodeView::setLightColor(const QColor &color)
{
    m_lightColor = color;
    update();
}

const QColor &QRcodeView::darkColor() const
{
    return m_darkColor;
}

void QRcodeView::setDarkColor(const QColor &color)
{
    m_darkColor = color;
    update();
}

bool QRcodeView::isSquare() const
{
    return m_square;
}

void QRcodeView::setSquare(bool square)
{
    m_square = square;
    update();
}

const QPixmap &QRcodeView::logo() const
{
    return m_logo;
}

void QRcodeView::setLogo(const QPixmap &logo)
{
    m_logo = logo;
    update();
}

qreal QRcodeView::logoScaleFactor() const
{
    return m_logeScaleFactor;
}

void QRcodeView::setLogoScaleFactor(qreal factor)
{
    if (factor > 0.5) {
        return;
    }
    m_logeScaleFactor = factor;
    update();
}

/**
 * @brief
 *
 * @note qrcode->data编码
 *    MSB 76543210 LSB
       |||||||`- 1=black/0=white
       ||||||`-- 1=ecc/0=data code area
       |||||`--- format information
       ||||`---- version information
       |||`----- timing pattern
       ||`------ alignment pattern
       |`------- finder pattern and separator
       `-------- non-data modules (format, timing, etc.)
 */
void QRcodeView::paintEvent(QPaintEvent *event)
{
    if (m_qrcode == nullptr || m_qrcode->width == 0) {
        return;
    }

    int w = 0;
    int h = 0;
    int dw = 0;
    int dh = 0;

    if (m_square) {
        w = h = qMin(width(), height());
    } else {
        w = width();
        h = height();
    }
    // 二维码每个子像素块的宽度
    dw = w / m_qrcode->width;
    // 二维码每个子像素块的高度
    dh = h / m_qrcode->width;

    QPainter painter(this);

    // 亮色
    QPen lightPen(m_lightColor);
    QBrush lightBrush(m_lightColor);
    // 暗色
    QPen darkPen(m_darkColor);
    QBrush darkBrush(m_darkColor);
    for (int i = 0; i < m_qrcode->width; i++) {
        for (int j = 0; j < m_qrcode->width; j++) {
            if (m_qrcode->data[i * m_qrcode->width + j] & 0x01) {
                // 绘制dark块
                painter.setPen(darkPen);
                painter.setBrush(darkBrush);
                painter.drawRect(j * dw, i * dh, dw, dh);
            } else {
                // 绘制light块
                painter.setPen(lightPen);
                painter.setBrush(lightBrush);
                painter.drawRect(j * dw, i * dh, dw, dh);
            }
        }
    }

    if (!m_logo.isNull()) {
        // 该参数与二维码的纠错率相关
        constexpr qreal errorCorrectionRate = 0.4;
        // 根据纠错率计算pixmap的缩放比例
        constexpr qreal scaleFactor = errorCorrectionRate * errorCorrectionRate;
        // 生成的二维码宽度
        int qw = dw * m_qrcode->width;
        // 生成的二维码高度
        int qh = dh * m_qrcode->width;

        // 缩放后的pixmap宽度
        int pw = w * scaleFactor;
        // 缩放后的pixmap高度
        int ph = h * scaleFactor;
        // 在二维码的中间绘制logo
        painter.drawPixmap((qw - pw) / 2, (qh - ph) / 2, m_logo.scaled(pw, ph));
    }
}

QSize QRcodeView::sizeHint() const
{
    // 设置二维码Widget的推荐大小
    return { 100, 100 };
}