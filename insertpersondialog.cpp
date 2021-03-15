#include "insertpersondialog.h"
#include "ui_insertpersondialog.h"

InsertPersonDialog::InsertPersonDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertPersonDialog)
{
    ui->setupUi(this);
    sex="男";
    this->setWindowTitle("新增候选人");
}

InsertPersonDialog::~InsertPersonDialog()
{
    delete ui;
}

void InsertPersonDialog::on_buttonBox_accepted()
{
    QMessageBox msgBox;
    QMessageBox::StandardButton select=msgBox.information(nullptr,"提示","确定添加该候选人？",QMessageBox::Yes | QMessageBox::No,QMessageBox::Yes);
    if(select==QMessageBox::Yes)
    {
        QSqlQuery query;
        QString sql="insert into person values('"+this->ui->lineEdit->text()+"','"+this->ui->lineEdit_2->text()+"','"+sex+"','"+this->ui->lineEdit_4->text()+"','0','"+this->ui->textEdit->toPlainText()+"','"+this->ui->textEdit_2->toPlainText()+"')";
        int ret=query.exec(sql);
        if(ret){
            QMessageBox::information(nullptr,"提示","添加成功",QMessageBox::Yes);
        }
        else{
            QMessageBox::information(nullptr,"提示","插入失败",QMessageBox::Yes);
            qDebug()<<query.lastError();
        }
    }
}

void InsertPersonDialog::on_radioButton_2_toggled(bool checked)
{
    if(checked){
        sex="男";
    }
}

void InsertPersonDialog::on_radioButton_toggled(bool checked)
{
    if(checked){
        sex="女";
    }
}
