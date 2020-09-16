#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT//

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void change_view_signal(int idx);

private slots:
    void on_grab_clicked();

    void on_reset_clicked();

    void on_pushButton_clicked();

    void bind_change_view_action(QAction *);
private:
    Ui::MainWindow *ui;
    int cur_frame;
};

#endif // MAINWINDOW_H
