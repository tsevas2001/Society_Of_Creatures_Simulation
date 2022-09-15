#ifndef CREATURE_SOCIETY_H
#define CREATURE_SOCIETY_H

#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>    
#include "../headers/creature.h"
#include "../headers/good_creature.h"
#include "../headers/bad_creature.h"

using namespace std;


class Creature_Society
{
    private:
        int NumOfCreatures;
        Creature **Creatures;
    public:
        Creature_Society(int, int, int, int);
        void print();
        void bless(int);
        void beat(int);
        void clone_next(int);
        void clone_zombies(int);
        int no_of_good();
        int no_of_zobies();
        ~Creature_Society();
};

#endif