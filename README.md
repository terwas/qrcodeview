# qrcodeview
A QR code control based on Qt
![image](https://user-images.githubusercontent.com/45413059/217776258-eef0b34b-66aa-4bf1-81b0-5c4c84b3a5f2.png)


## Example:

```c++
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
```
