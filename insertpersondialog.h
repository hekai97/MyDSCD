#ifndef INSERTPERSONDIALOG_H
#define INSERTPERSONDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
namespace Ui {
class InsertPersonDialog;
}

class InsertPersonDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InsertPersonDialog(QWidget *parent = nullptr);
    ~InsertPersonDialog();

private slots:
    void on_buttonBox_accepted();

    void on_radioButton_2_toggled(bool checked);

    void on_radioButton_toggled(bool checked);

private:
    QString sex=nullptr;
    Ui::InsertPersonDialog *ui;
};

#endif // INSERTPERSONDIALOG_H
