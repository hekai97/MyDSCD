#include "userwindow.h"
#include "ui_userwindow.h"

userWindow::userWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::userWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("投票");
    connecttoMysql();
    setTable();
}
void userWindow::setUsername(QString username){
    this->username=username;
}
void userWindow::connecttoMysql(){
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
void userWindow::setTable(){
//    model=new QSqlTableModel(this->ui->stackedWidget);
//    model->setTable("person");
//    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
//    model->select();
//    model->setHeaderData(0, Qt::Horizontal, QObject::tr("编号"));
//    model->setHeaderData(1, Qt::Horizontal, QObject::tr("姓名"));
//    model->setHeaderData(2, Qt::Horizontal, QObject::tr("性别"));
//    model->setHeaderData(3, Qt::Horizontal, QObject::tr("年龄"));
//    model->setHeaderData(4, Qt::Horizontal, QObject::tr("所得票数"));
//    model->setHeaderData(5, Qt::Horizontal, QObject::tr("介绍"));
//    model->setHeaderData(6, Qt::Horizontal, QObject::tr("详细简介"));
//    this->ui->tableView->setModel(model);
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
    qDebug()<<"用户界面删的";
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
userWindow::~userWindow()
{
    delete ui;
}

void userWindow::on_pushButton_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(0);
}

void userWindow::on_pushButton_4_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(1);
}

void userWindow::on_pushButton_2_clicked()
{
    this->close();
}


void userWindow::on_pushButton_3_clicked()
{
    QSqlQuery query;
    query.exec("select uservotes from users where username="+this->username);
    query.first();
    this->count=query.value(0).toInt();
    int row=this->ui->tableView->currentIndex().row();
    auto res=this->model->index(row,0);
    QString s=res.data().toString();
    QMessageBox msgbox;
    QMessageBox::StandardButton selected=msgbox.information(nullptr,"提示","确定投票给"+this->model->index(row,1).data().toString()+"?\n你还有"+QString::number(count)+"次投票机会！",QMessageBox::Yes | QMessageBox::No,QMessageBox::Yes);
    if(selected==QMessageBox::Yes){
        if(count==0){
            QMessageBox::critical(nullptr,"提示","你已经没有投票机会了！",QMessageBox::Yes);
        }
        else{
            QSqlQuery query;
            query.exec("update person set Pvoted=Pvoted+1 where Pno="+s);
            QMessageBox::information(nullptr,"提示","投票成功",QMessageBox::Yes);
            this->count--;
            query.exec("update users set uservotes=uservotes-1 where username="+this->username);
            this->setTable();
            //emit this->ui->pushButton_4->clicked();     //发出个点击浏览按钮的信号
        }
    }
}
