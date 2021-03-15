#include "encryption.h"

Encryption::Encryption()
{

}
int Encryption::checkUserAndPassword(QString user, QString password){
    QSqlQuery query;
    query.exec("select * from users where username="+user);
    if(!query.next()){
        return 2;
    }
    if(user==query.value(0).toString()){
        if(checkPassword(password,query.value(1).toString())){
            return 0;
        }
        else
        {
            return 1;
        }
    }
    return 1;
}
int Encryption::checkAdminUserAndPassword(QString user, QString password){
    QSqlQuery query;
    query.exec("select * from adminuser where username="+user);
    if(!query.next()){
        return 2;
    }
    if(user==query.value(0).toString()){
        if(checkPassword(password,query.value(1).toString())){
            return 0;
        }
        else
        {
            return 1;
        }
    }
    return 1;
}
QString Encryption::passwordToMD5(QString password){
    return QCryptographicHash::hash(password.toLatin1(),QCryptographicHash::Md5).toHex();
}
bool Encryption::checkPassword(QString password, QString md5){
    QString temp=QCryptographicHash::hash(password.toLatin1(),QCryptographicHash::Md5).toHex();
    if(md5==temp){
        return true;
    }
    return false;
}
