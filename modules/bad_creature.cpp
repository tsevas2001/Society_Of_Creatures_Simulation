#include "../headers/bad_creature.h"

using namespace std;

Bad_Creature::Bad_Creature(int health, string name, int bad_thrsh) : Creature(name, health), thrsh(bad_thrsh) // Constructor
{
    cout << "Creating bad_creature..." << endl;
    cout << "Completed" << endl;
}

Bad_Creature::Bad_Creature(const Bad_Creature &creature) : Creature(creature) // Copy-Constructor
{
    cout << "Creating bad creature clone..." << endl;
    cout << "Bad creature clone created successfully!" << endl;
}

bool Bad_Creature::is_a_good() // Returns false cause the creature is bad
{
    return false;
}

Creature *Bad_Creature::clone() // Returns a creature with the same characteristics
{
    Bad_Creature *creature = new Bad_Creature(*this);
    return creature;
}

bool Bad_Creature::bless() // bless the Creature if itsn't zombie
{
    if (is_a_zobie() == false)
    {
        health++;
        cout << "(BAD) Creature blessed!" << endl;
        if (health > thrsh)
            return true;
        else
            return false;
    }
    else
        return false;
}

Bad_Creature::~Bad_Creature() // Destructor
{
    cout << "Destroying bad_creature..." << endl;

    cout << "Completed" << endl;
}