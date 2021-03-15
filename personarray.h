#pragma once
#include "person.h"
const int MAXSIZE = 10000;
class PersonArray
{
public:
    Person data[MAXSIZE];
    int length;
    PersonArray();
};
