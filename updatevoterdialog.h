#ifndef UPDATEVOTERDIALOG_H
#define UPDATEVOTERDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QtSql/QSqlQuery>
#include "encryption.h"

namespace Ui {
class UpdateVoterDialog;
}

class UpdateVoterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateVoterDialog(QWidget *parent = nullptr);
    ~UpdateVoterDialog();

    void setUserText(QString name,QString password,QString votes);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::UpdateVoterDialog *ui;
};

#endif // UPDATEVOTERDIALOG_H
