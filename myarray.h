#ifndef MYARRAY_H
#define MYARRAY_H
#include "personarray.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtDebug>
class MyArray
{
public:
    PersonArray *array;
    MyArray();
    void initMyArray(QSqlQuery sql,PersonArray*& myarray);
    bool insertMyArray(PersonArray*& myarray,Person data);
    bool deleteMyArray(PersonArray*& myarray,Person data);
    Person findPerson(PersonArray*& myarray,QString name);
};

#endif // MYARRAY_H
