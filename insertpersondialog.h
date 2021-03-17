#ifndef INSERTPERSONDIALOG_H
#define INSERTPERSONDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include "person.h"
namespace Ui {
class InsertPersonDialog;
}

class InsertPersonDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InsertPersonDialog(QWidget *parent = nullptr);
    ~InsertPersonDialog();

    Person getNewPerson();

private slots:

    void on_radioButton_2_toggled(bool checked);

    void on_radioButton_toggled(bool checked);


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    QString sex=nullptr;
    Ui::InsertPersonDialog *ui;
    Person person;
};

#endif // INSERTPERSONDIALOG_H
