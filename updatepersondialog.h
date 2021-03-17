#ifndef UPDATEPERSONDIALOG_H
#define UPDATEPERSONDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QtSql/QSqlQuery>
#include <QModelIndex>
#include "person.h"

namespace Ui {
class UpdatePersonDialog;
}

class UpdatePersonDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UpdatePersonDialog(QWidget *parent = nullptr);
    ~UpdatePersonDialog();
    void setPersonText(Person index);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::UpdatePersonDialog *ui;
};

#endif // UPDATEPERSONDIALOG_H
