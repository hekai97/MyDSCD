#ifndef ENCRYPTION_H
#define ENCRYPTION_H
#include <QString>
#include <QtSql/QSqlQuery>
#include <QCryptographicHash>

class Encryption
{
public:
    Encryption();

    /**
    检查用户名和密码，根据返回值不同生成不同的错误信息
    返回值：0           代表用户名与密码校验成功
    返回值：1           代表用户名校验成功，密码错误
    返回值：2           代表用户名校验不成功
    */
    int checkUserAndPassword(QString user,QString password);
    int checkAdminUserAndPassword(QString user,QString password);
    QString passwordToMD5(QString password);
private:
    bool checkPassword(QString password,QString md5);                           //将密码加密为MD5字符串，然后与数据库中的密码进行比较
};

#endif // ENCRYPTION_H
