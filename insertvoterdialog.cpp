#include "insertvoterdialog.h"
#include "ui_insertvoterdialog.h"

InsertVoterDialog::InsertVoterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertVoterDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("新增投票人");
}

InsertVoterDialog::~InsertVoterDialog()
{
    delete ui;
}

void InsertVoterDialog::on_buttonBox_accepted()
{
    QMessageBox msgBox;
    QMessageBox::StandardButton selected=msgBox.information(nullptr,"提示","确定新增该用户？",QMessageBox::Yes | QMessageBox::No,QMessageBox::Yes);
    if(selected==QMessageBox::Yes)
    {
        QSqlQuery query;
        Encryption encryption;
        QString password=encryption.passwordToMD5(this->ui->lineEdit_2->text());
        QString sql="insert into users values('"+this->ui->lineEdit->text()+"','"+password+"','"+this->ui->lineEdit_3->text()+"')";
        int ret=query.exec(sql);
        if(ret){
            QMessageBox::information(nullptr,"提示","插入成功",QMessageBox::Yes);
        }
        else
        {
            QMessageBox::information(nullptr,"提示","插入失败",QMessageBox::Yes);
        }
    }
}
