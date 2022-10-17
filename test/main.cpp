#include "qrcodeview.h"
#include <QtWidgets/QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QRcodeView view;
    view.setText("hell oworld");
    view.setSquare(true);
    view.resize(200, 200);
    view.setLogo(QPixmap(R"(D:/logo.png)"));
    view.show();
    return app.exec();
}