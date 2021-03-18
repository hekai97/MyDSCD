#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <QDialog>
#include "personarray.h"
#include "myarray.h"
#include "binarytreesort.h"
#include "voter.h"
#include "insertpersondialog.h"
#include "insertvoterdialog.h"
#include "updatepersondialog.h"
#include "updatevoterdialog.h"

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();


    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_tableView_2_doubleClicked(const QModelIndex &index);

private:
    MyArray* array;
    PersonArray* personarray;
    Tree* root;
    BinaryTreeSort* bts;
    void setMyArray();
    void setMyTree();


    void connecttoMysql();
    Ui::AdminWindow *ui;
    QStandardItemModel *model;
    void setCandidateTable();       //设置候选人的表格
    void setVoterTable();           //设置投票人的信息
};

#endif // ADMINWINDOW_H
