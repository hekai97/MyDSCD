#include "updatepersondialog.h"
#include "ui_updatepersondialog.h"

UpdatePersonDialog::UpdatePersonDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdatePersonDialog)
{
    ui->setupUi(this);
}

UpdatePersonDialog::~UpdatePersonDialog()
{
    delete ui;
}

void UpdatePersonDialog::setPersonText(Person index)
{
    this->ui->lineEdit->setText(QString::fromLocal8Bit(index.getNumber()));
    this->ui->lineEdit_2->setText(QString::fromLocal8Bit(index.getName()));
    this->ui->lineEdit_3->setText(QString::fromLocal8Bit(index.getSex()));
    this->ui->lineEdit_4->setText(QString::number(index.getAge()));
    this->ui->lineEdit_5->setText(QString::number(index.getVoted()));
    this->ui->textEdit->setText(QString::fromLocal8Bit(index.getIntroduction()));
    this->ui->textEdit_2->setText(QString::fromLocal8Bit(index.getDescribe()));
    this->ui->lineEdit->setReadOnly(true);
    this->ui->lineEdit_5->setReadOnly(true);
}


void UpdatePersonDialog::on_pushButton_clicked()
{
    QString name=this->ui->lineEdit->text();
    QMessageBox msgbox;
    QMessageBox::StandardButton selected=msgbox.information(nullptr,"提示","你确定对"+name+"进行修改吗?",QMessageBox::Yes | QMessageBox::No,QMessageBox::Yes);
    if(selected==QMessageBox::Yes)
    {
        QString sql="update Person set Pname='"+this->ui->lineEdit_2->text()+"',Psex='"+this->ui->lineEdit_3->text()+"',Peage='"+this->ui->lineEdit_4->text()+"',Pintroduction='"+this->ui->textEdit->toPlainText()+"',Pdescribe='"+this->ui->textEdit_2->toPlainText()+"' where Pno="+this->ui->lineEdit->text();
        QSqlQuery query;
        query.exec(sql);
        QMessageBox::StandardButton res=QMessageBox::information(nullptr,"提示","修改成功",QMessageBox::Ok);
        if(res==QMessageBox::Ok)
        {
            this->close();
        }
    }
}

void UpdatePersonDialog::on_pushButton_2_clicked()
{
    this->close();
}
