#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    cur_frame = 0;
    ui->setupUi(this);
    ui->actionjz->setText("打开标定界面");
    ui->actionbd->setText("打开矫正界面");
    QObject::connect(ui->menuBar,SIGNAL(triggered(QAction *)),this,SLOT(bind_change_view_action(QAction *)));
    QObject::connect(this,SIGNAL(change_view_signal(int)),
                     ui->stackedWidget,SLOT(setCurrentIndex(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_grab_clicked()
{
    cur_frame++;
    ui->lcdNumber->display(cur_frame);
}

void MainWindow::on_reset_clicked()
{
    cur_frame = 0;
    ui->lcdNumber->display(cur_frame);
}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::bind_change_view_action(QAction * action){
    if(action == ui->actionbd){
        emit change_view_signal(1);
    }else if(action == ui->actionjz){
        emit change_view_signal(0);
    }
}

