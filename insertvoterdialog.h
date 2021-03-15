#ifndef INSERTVOTERDIALOG_H
#define INSERTVOTERDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QtSql/QSqlQuery>
#include "encryption.h"
namespace Ui {
class InsertVoterDialog;
}

class InsertVoterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InsertVoterDialog(QWidget *parent = nullptr);
    ~InsertVoterDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::InsertVoterDialog *ui;
};

#endif // INSERTVOTERDIALOG_H
