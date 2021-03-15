#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    this->setWindowTitle("登录");
}

LoginWindow::~LoginWindow()
{
    delete ui;
}


void LoginWindow::on_pushButton_clicked()
{
    if(ui->comboBox->currentIndex()==0){                            //如果是用户
        int res=encryption.checkUserAndPassword(ui->lineEdit->text(),ui->lineEdit_2->text());
        if(res==0){
            userwindow.setUsername(ui->lineEdit->text());
            userwindow.show();
            this->close();
        }
        else if(res==1){
            QMessageBox::critical(nullptr,"提示","密码错误!",QMessageBox::Yes);
        }
        else {
            QMessageBox::critical(nullptr,"提示","无此用户!",QMessageBox::Yes);
        }
    }
    else if(ui->comboBox->currentIndex()==1){                       //如果是管理员
        int res=encryption.checkAdminUserAndPassword(ui->lineEdit->text(),ui->lineEdit_2->text());
        if(res==0){
            adminwindow.show();
            this->close();
        }
        else if(res==1){
            QMessageBox::critical(nullptr,"提示","密码错误!",QMessageBox::Yes);
        }
        else {
            QMessageBox::critical(nullptr,"提示","无此用户!",QMessageBox::Yes);
        }
    }
}
