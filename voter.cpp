#include "voter.h"

Voter::Voter()
{

}
void Voter::setUsername(QString username){
    this->username=username;
}
void Voter::setPassword(QString password){
    this->userpassword=password;
}
void Voter::setVotes(int votes){
    this->votes=votes;
}
QString Voter::getUsername(){
    return this->username;
}
QString Voter::getPassword(){
    return this->userpassword;
}
int Voter::getVotes(){
    return this->votes;
}
