#pragma once

#include <iostream>

class Ancestor {
   private:
    char* humanName = nullptr;

   protected:
    const char *getName() const;

   public:
    explicit Ancestor(const char* name);
    virtual ~Ancestor();
    virtual void print() const = 0;
};