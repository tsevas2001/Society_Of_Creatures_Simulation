#ifndef CREATURE_H
#define CREATURE_H

#pragma once
#include <iostream>

using namespace std;

class Creature
{
    protected:
        string name;
        int health;
    public:
        Creature(string, int);
        Creature(const Creature &cret);
        bool is_a_zobie();
        void beat();
        void print();
        virtual bool bless() = 0;
        virtual Creature *clone() = 0;
        virtual bool is_a_good() = 0;
        ~Creature();

};

#endif