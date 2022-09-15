#ifndef BAD_CREATURE_H
#define BAD_CREATURE_H

#pragma once
#include <iostream>
#include "creature.h"

using namespace std;

class Bad_Creature : public Creature
{
    private:
        int thrsh;
    public:
        Bad_Creature(int, string, int);
        Bad_Creature(const Bad_Creature &creature);
        bool is_a_good() override;
        bool bless() override;
        Creature *clone() override;
        ~Bad_Creature();
};

#endif