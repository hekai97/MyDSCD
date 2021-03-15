#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include "userwindow.h"
#include "adminwindow.h"
#include "encryption.h"
QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_pushButton_clicked();

private:
    Encryption encryption;
    Ui::LoginWindow *ui;
    userWindow userwindow;
    AdminWindow adminwindow;
};
#endif // LOGINWINDOW_H
