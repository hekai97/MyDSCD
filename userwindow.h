#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtDebug>
#include <QtSql/QSqlTableModel>
#include <QTableView>
#include <QStandardItemModel>
#include <QMessageBox>
#include "myarray.h"
#include "binarytreesort.h"

namespace Ui {
class userWindow;
}

class userWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit userWindow(QWidget *parent = nullptr);
    ~userWindow();
    void setUsername(QString username);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();


    void on_pushButton_3_clicked();


private:
    QString username;
    Ui::userWindow *ui;
    QStandardItemModel *model;
    void connecttoMysql();
    void setTable();
    int count;                        //限制投票的次数
};

#endif // USERWINDOW_H
