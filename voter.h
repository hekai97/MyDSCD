#ifndef VOTER_H
#define VOTER_H

#include <QString>
class Voter
{
public:
    Voter();
    void setUsername(QString username);
    void setPassword(QString password);
    void setVotes(int votes);
    QString getUsername();
    QString getPassword();
    int getVotes();
private:
    QString username;
    QString userpassword;
    int votes;
};

#endif // VOTER_H
