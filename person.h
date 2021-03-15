#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <QDebug>
class Person /*: public QObject*/
{
    //    Q_OBJECT
public:
    //    explicit Person(QObject *parent = nullptr);

    //signals:

private:
    std::string number;                 //人物的编号
    std::string name;                   //人物的姓名
    std::string sex;                    //人物的性别
    int age;                            //人物的年龄
    int voted;                  //人物的被投票数
    std::string introduction;           //人物的简介，这部分是给要进行投票的人看的
    std::string describe;               //人物的描述，这部分给管理员看
public:
    Person& operator=(const Person& b);
    bool operator==(const Person& b)const;
    bool operator<(const Person& b)const;
    bool operator>(const Person& b)const;
    friend QDebug operator<<(QDebug out,Person& b);
    Person();                           //无参构造，将字符串变量设置为空，将std::size_t变量设置为0
    Person(std::string number, std::string name, std::string sex, int age, int voted, std::string introduction, std::string describe);
    ~Person();
    void setNumber(std::string number);
    void setName(std::string name);
    void setSex(std::string sex);
    void setAge(int age);
    void setVoted(int voted);
    void setIntroduction(std::string introduction);
    void setDescribe(std::string describe);
    std::string getNumber();
    std::string getName();
    std::string getSex();
    int getAge();
    int getVoted();
    std::string getIntroduction();
    std::string getDescribe();
};

#endif // PERSON_H
