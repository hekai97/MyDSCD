#include "updatevoterdialog.h"
#include "ui_updatevoterdialog.h"

UpdateVoterDialog::UpdateVoterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateVoterDialog)
{
    ui->setupUi(this);
}

UpdateVoterDialog::~UpdateVoterDialog()
{
    delete ui;
}

void UpdateVoterDialog::setUserText(QString name, QString password, QString votes)
{
    this->ui->lineEdit->setText(name);
    this->ui->lineEdit_2->setText(password);
    this->ui->lineEdit_3->setText(votes);
    this->ui->lineEdit->setReadOnly(true);
}

void UpdateVoterDialog::on_pushButton_clicked()
{
    QMessageBox::StandardButton selected=QMessageBox::information(nullptr,"提示","你确定要修改用户:"+this->ui->lineEdit->text()+"吗",QMessageBox::Yes | QMessageBox::No,QMessageBox::Yes);
    if(selected==QMessageBox::Yes)
    {
        QSqlQuery query;
        QString sql="select userpassword,uservotes from users where username="+this->ui->lineEdit->text();
        query.exec(sql);
        query.first();
        if(query.value(0).toString()!=this->ui->lineEdit_2->text())
        {
            Encryption e;
            QString tp=e.passwordToMD5(this->ui->lineEdit_2->text());
            sql="update users set userpassword='"+tp+"',uservotes="+this->ui->lineEdit_3->text()+" where username="+this->ui->lineEdit->text();
            query.exec(sql);
            QMessageBox::information(nullptr,"提示","修改成功",QMessageBox::Yes);
        }
        else
        {
            if(query.value(1).toString()!=this->ui->lineEdit_3->text())
            {
                sql="update users set uservotes="+this->ui->lineEdit_3->text()+" where username="+this->ui->lineEdit->text();
                query.exec(sql);
                QMessageBox::information(nullptr,"提示","修改成功",QMessageBox::Yes);
            }
        }
        emit this->ui->pushButton_2->clicked();
    }
}

void UpdateVoterDialog::on_pushButton_2_clicked()
{
    this->close();
}
