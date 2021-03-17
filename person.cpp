#include "person.h"

//Person::Person(QObject *parent) : QObject(parent)
//{

//}
Person::Person() :number(""), name(""), sex(""), age(0), voted(0), introduction(""), describe("") {

}
Person::Person(std::string number, std::string name, std::string sex, int age, int voted, std::string introduction, std::string describe) {
    this->number = number;
    this->name = name;
    this->sex = sex;
    this->age = age;
    this->voted = voted;
    this->introduction = introduction;
    this->describe = describe;
}
void Person::setNumber(std::string number) {
    this->number = number;
}
void Person::setName(std::string name) {
    this->name = name;
}
void Person::setSex(std::string sex) {
    this->sex = sex;
}
void Person::setAge(int age) {
    this->age = age;
}
void Person::setVoted(int voted) {
    this->voted = voted;
}
void Person::setIntroduction(std::string introduction) {
    this->introduction = introduction;
}
void Person::setDescribe(std::string describe) {
    this->describe = describe;
}
std::string Person::getNumber() {
    return this->number;
}
std::string Person::getName() {
    return this->name;
}
std::string Person::getSex() {
    return this->sex;
}
int Person::getAge() {
    return this->age;
}
int Person::getVoted() {
    return this->voted;
}
std::string Person::getIntroduction() {
    return this->introduction;
}
std::string Person::getDescribe() {
    return this->describe;
}


Person& Person::operator=(const Person& b) {
    this->number = b.number;
    this->name = b.name;
    this->age = b.age;
    this->sex = b.sex;
    this->voted = b.voted;
    this->introduction = b.introduction;
    this->describe = b.describe;
    return *this;
}

bool Person::operator==(const Person& b)const {
    if(this->voted!=b.voted)
    {
        return false;
    }
    else
    {
        return this->number==b.number;
    }
//    return this->voted == b.voted;
}
bool Person::operator<(const Person& b)const {
    if(this->voted!=b.voted)
    {
        return this->voted < b.voted;
    }
    else
    {
        return this->number>b.number;
    }
}
bool Person::operator>(const Person& b)const {
    if(this->voted!=b.voted)
    {
        return this->voted > b.voted;
    }
    else
    {
        //该处使用<的目的是将票数相同，编号小的往上排
        return this->number<b.number;
    }
}

//全局函数，重载QDebug中的<<运算符
QDebug operator<<(QDebug out,Person& b){
    out<<QString::fromLocal8Bit(b.getNumber())
       <<QString::fromLocal8Bit(b.getName())
       <<QString::fromLocal8Bit(b.getSex())
       <<b.getAge()
       <<b.getVoted()
       <<QString::fromLocal8Bit(b.getIntroduction())
       <<QString::fromLocal8Bit(b.getDescribe());
    return out;
}
Person::~Person() {

}
