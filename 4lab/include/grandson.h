#pragma once
#include "../include/kid.h"

class Grandson : public Kid {
   private:
    char* surName = nullptr;

   public:
    Grandson(const char* name, const char* sur);
    ~Grandson() override;
    void print() const override;
};