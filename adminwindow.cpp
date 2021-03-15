#include "adminwindow.h"
#include "ui_adminwindow.h"

AdminWindow::AdminWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("主页");
    connecttoMysql();
}

AdminWindow::~AdminWindow()
{
    delete ui;
}
void AdminWindow::connecttoMysql(){
    QSqlDatabase dbcon=QSqlDatabase::addDatabase("QMYSQL");
    dbcon.setHostName("127.0.0.1");
    dbcon.setPort(3306);
    dbcon.setDatabaseName("dscd");
    dbcon.setUserName("root");
    dbcon.setPassword("hk19990707");
    if(dbcon.open()){
        qDebug()<<"connected";
    }
    else
    {
        qDebug()<<"error";
    }
}
void AdminWindow::on_pushButton_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(0);
    setCandidateTable();
}

void AdminWindow::on_pushButton_2_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(1);
    setVoterTable();
}

void AdminWindow::on_pushButton_3_clicked()
{
    this->close();
}
void AdminWindow::setCandidateTable(){
    QSqlQuery query;
    query.exec("select * from person");
    MyArray* array=new MyArray();
    PersonArray* personarray=nullptr;
    array->initMyArray(query,personarray);
    Tree* root=nullptr;
    BinaryTreeSort* bts=new BinaryTreeSort();
    bts->initBTS(root,personarray);
    bts->getSortedArray(root,personarray);
    bts->deleteTree(root);
    model=new QStandardItemModel(personarray->length,7);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("编号"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("姓名"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("性别"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("年龄"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("所得票数"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("介绍"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("详细简介"));
    int row=0;
    while(row<personarray->length){
        QStandardItem *item=new QStandardItem(QString::fromLocal8Bit(personarray->data[row].getNumber()));
        QStandardItem *item1=new QStandardItem(QString::fromLocal8Bit(personarray->data[row].getName()));
        QStandardItem *item2=new QStandardItem(QString::fromLocal8Bit(personarray->data[row].getSex()));
        QStandardItem *item3=new QStandardItem(QString::number(personarray->data[row].getAge()));
        QStandardItem *item4=new QStandardItem(QString::number(personarray->data[row].getVoted()));
        QStandardItem *item5=new QStandardItem(QString::fromLocal8Bit(personarray->data[row].getIntroduction()));
        QStandardItem *item6=new QStandardItem(QString::fromLocal8Bit(personarray->data[row].getDescribe()));
        model->setItem(row,0,item);
        model->setItem(row,1,item1);
        model->setItem(row,2,item2);
        model->setItem(row,3,item3);
        model->setItem(row,4,item4);
        model->setItem(row,5,item5);
        model->setItem(row,6,item6);
        ++row;
    }

    this->ui->tableView->setModel(model);
}



void AdminWindow::setVoterTable(){
    QSqlQuery query;
    query.exec("select * from users");
    model=new QStandardItemModel(query.size(),3);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("用户名"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("密码"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("剩余投票次数"));
    int row=0;
    while(query.next()){
        QStandardItem *item=new QStandardItem(query.value(0).toString());
        QStandardItem *item1=new QStandardItem(query.value(1).toString());
        QStandardItem *item2=new QStandardItem(query.value(2).toString());
        model->setItem(row,0,item);
        model->setItem(row,1,item1);
        model->setItem(row,2,item2);
        ++row;
    }

    this->ui->tableView_2->setModel(model);
}

void AdminWindow::on_pushButton_4_clicked()             //新建一行
{
//    QStandardItem *item=new QStandardItem(" ");
//    model->appendRow(item);
//    QDialog insertdialog;
//    insertdialog.setWindowTitle("提示");
//    insertdialog.exec();
    InsertPersonDialog insertdialog;
    insertdialog.exec();
}

void AdminWindow::on_pushButton_6_clicked()             //清楚投票结果
{
    QMessageBox msgbox;
    QMessageBox::StandardButton selected=msgbox.information(nullptr,"提示","确定清除候选人的投票结果吗？",QMessageBox::Yes | QMessageBox::No,QMessageBox::Yes);
    if(selected==QMessageBox::Yes){
        QSqlQuery query;
        query.exec("update person set Pvoted=0");
        QMessageBox::information(nullptr,"提示","清除成功",QMessageBox::Yes);
        emit this->ui->pushButton->clicked();
    }
}

void AdminWindow::on_pushButton_5_clicked()             //删除候选人
{
    int row=this->ui->tableView->currentIndex().row();
    auto res=this->model->index(row,0);
    QString s=res.data().toString();
    QMessageBox msgbox;
    QMessageBox::StandardButton selected=msgbox.information(nullptr,"提示","你确定要删除候选人:"+this->model->index(row,1).data().toString()+"？",QMessageBox::Yes | QMessageBox::No,QMessageBox::Yes);
    if(selected==QMessageBox::Yes){
        QSqlQuery query;
        query.exec("delete from person where Pno="+s);
        QMessageBox::information(nullptr,"提示","删除成功",QMessageBox::Yes);
        emit this->ui->pushButton->clicked();
    }
}

void AdminWindow::on_pushButton_7_clicked()//添加投票人
{
    InsertVoterDialog insertdialog;
    insertdialog.exec();
}

void AdminWindow::on_pushButton_9_clicked()
{
    int row=this->ui->tableView_2->currentIndex().row();
    auto res=this->model->index(row,0);
    QString s=res.data().toString();
    QMessageBox msgbox;
    QMessageBox::StandardButton selected=msgbox.information(nullptr,"提示","你确定要删除:"+s+"用户吗？",QMessageBox::Yes | QMessageBox::No,QMessageBox::Yes);
    if(selected==QMessageBox::Yes){
        QSqlQuery query;
        query.exec("delete from users where username="+s);
        QMessageBox::information(nullptr,"提示","删除成功",QMessageBox::Yes);
        emit this->ui->pushButton_2->clicked();
    }
}

void AdminWindow::on_pushButton_10_clicked()
{
    int row=this->ui->tableView_2->currentIndex().row();
    auto res=this->model->index(row,0);
    QString username=res.data().toString();
    QString password=this->model->index(row,1).data().toString();
    QMessageBox msgbox;
    QMessageBox::StandardButton selected=msgbox.information(nullptr,"提示","你确定将:"+username+"用户提升为管理员吗？",QMessageBox::Yes | QMessageBox::No,QMessageBox::Yes);
    if(selected==QMessageBox::Yes)
    {
        QSqlQuery query;
        query.exec("insert into adminuser values('"+username+"','"+password+"')");
        query.exec("delete from users where username="+username);
        QMessageBox::information(nullptr,"提示","提升权限成功,现在"+username+"用户可以以管理员身份登录");
        emit this->ui->pushButton_2->clicked();
    }
}
