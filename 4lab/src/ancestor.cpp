#include <iostream>
#include "../include/ancestor.h"
#include "../include/utils.h"
#include <cstring>

const char *Ancestor::getName() const { return humanName; }

Ancestor::Ancestor(const char* name){
    humanName = new char[myStrlen(name) + 1];
    strcpy_s(humanName, myStrlen(name) + 1, name);
}

Ancestor::~Ancestor() { delete[] humanName;}