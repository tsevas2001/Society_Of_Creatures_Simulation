#ifndef GOOD_CREATURE_H
#define GOOD_CREATURE_H

#pragma once
#include <iostream>
#include "creature.h"

using namespace std;

class Good_Creature : public Creature
{
    private:
        int thrsh;
    public:
        Good_Creature(int, string, int);
        Good_Creature(const Good_Creature &creature);
        bool is_a_good() override;
        bool bless() override;
        Creature *clone() override;
        ~Good_Creature();
};

#endif