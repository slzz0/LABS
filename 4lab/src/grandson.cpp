#include "../include/grandson.h"
#include "../include/utils.h"
#include <cstring>
#include <iostream>

Grandson::Grandson(const char *name, const char *sur) : Kid(name)
{
    surName = new char[myStrlen(sur) + 1];
    strcpy_s(surName, myStrlen(sur) + 1, sur);
}

Grandson::~Grandson() { delete[] surName; }

void Grandson::print() const { std::cout << "Grandson: " << getName() << " " << surName << "\n"; }