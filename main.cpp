#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>  //语言的头文件
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    MainWindow w;
    w.setWindowTitle("智能小车双目标定程序");
    w.show();
    return a.exec();
}
