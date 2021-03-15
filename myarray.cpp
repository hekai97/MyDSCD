#include "myarray.h"

MyArray::MyArray()
{

}
void MyArray::initMyArray(QSqlQuery sql,PersonArray*& myarray){
    if(myarray==nullptr){
        myarray=new PersonArray();
    }
    while(sql.next())
    {
        Person data;
        data.setNumber(sql.value(0).toString().toLocal8Bit().toStdString());
        data.setName(sql.value(1).toString().toLocal8Bit().toStdString());
        data.setSex(sql.value(2).toString().toLocal8Bit().toStdString());
        data.setAge(sql.value(3).toInt());
        data.setVoted(sql.value(4).toInt());
        data.setIntroduction(sql.value(5).toString().toLocal8Bit().toStdString());
        data.setDescribe(sql.value(6).toString().toLocal8Bit().toStdString());
        insertMyArray(myarray,data);
    }
}
bool MyArray::insertMyArray(PersonArray*& myarray,Person data){
    myarray->data[myarray->length]=data;
    myarray->length++;
    return true;
}
bool MyArray::deleteMyArray(PersonArray*& myarray,Person data){
    if(myarray->length==0){
        return false;
    }
    int i=0;
    for(i=0;i<myarray->length;++i)
    {
        if(data==myarray->data[i])
        {
            for(int j=i;j<myarray->length;++i)
            {
                myarray->data[j]=myarray->data[j+1];
            }
            myarray->length--;
            return true;
        }
    }
    return false;
}
