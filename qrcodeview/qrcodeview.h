#ifndef __QRCODEVIEW_H__
#define __QRCODEVIEW_H__

#include <QtWidgets/QWidget>
#include <qrencode.h>

class QRcodeView : public QWidget {
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText)
    Q_PROPERTY(QColor lightColor READ lightColor WRITE setLightColor)
    Q_PROPERTY(QColor darkColor READ darkColor WRITE setDarkColor)
    Q_PROPERTY(bool square READ isSquare WRITE setSquare)
    Q_PROPERTY(QPixmap logo READ logo WRITE setLogo)
    Q_PROPERTY(qreal logeScaleFactor READ logeScaleFactor WRITE setLogeScaleFactor)
public:
    explicit QRcodeView(QWidget *parent = nullptr);
    QRcodeView(const QString &text, QWidget *parent = nullptr);
    ~QRcodeView() override;

    const QString &text() const;
    void setText(const QString &text);

    const QColor &lightColor() const;
    void setLightColor(const QColor &color);

    const QColor &darkColor() const;
    void setDarkColor(const QColor &color);

    bool isSquare() const;
    void setSquare(bool square);

    const QPixmap &logo() const;
    void setLogo(const QPixmap &logo);

    QSize sizeHint() const override;

    qreal logoScaleFactor() const;
    void setLogoScaleFactor(qreal factor);

signals:
    void encodeFinished();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QString m_text;
    QRcode *m_qrcode = nullptr;
    QColor m_lightColor = Qt::white;
    QColor m_darkColor = Qt::black;
    QPixmap m_logo;
    qreal m_logeScaleFactor = 0.4;
    // 是否绘制为正方形
    bool m_square = false;
};

#endif // __QRCODEVIEW_H__
