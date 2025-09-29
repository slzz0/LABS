#pragma once

#include "../include/ancestor.h"

class Kid : public Ancestor {
   public:
    explicit Kid(const char* name);
    void print() const override;
};