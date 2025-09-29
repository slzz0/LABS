#include <iostream>

class Program {
   private:
    class Ancestor** familyMembers = nullptr;
    int size = 0;
    int capacity = 1;

    void ensureFamilyCapacity();
    void addMember();

   public:
    Program() = default;
    ~Program();

    Program(const Program&) = delete;
    Program& operator=(const Program&) = delete;

    void addFamilyMember();
    void showAllMembers() const;
    void clear();
    void start();
};