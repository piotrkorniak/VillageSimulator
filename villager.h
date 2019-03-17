#ifndef VILLAGER_H
#define VILLAGER_H
#include "globals.h"

class Villager
{
    string _name;
    unsigned int _age;
    unsigned int _maxAge;
    bool _isMan;
public:
    Villager();

    Villager(string name, unsigned int age, unsigned int maxAge, bool isMan);
    ~Villager();
    void incrementAge();
    bool isAlive();

    unsigned int age() const;
    bool isMan() const;
    string name();
};

#endif // VILLAGER_H
