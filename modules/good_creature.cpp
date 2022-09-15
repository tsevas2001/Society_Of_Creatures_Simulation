#include "../headers/good_creature.h"

using namespace std;

Good_Creature::Good_Creature(int health, string name, int good_thrsh) : Creature(name, health), thrsh{good_thrsh} // Constructor
{
    cout << "Creating good_creature..." << endl;
    cout << "Completed" << endl;
}

Good_Creature::Good_Creature(const Good_Creature &creature) : Creature(creature) // Copy-Constructor
{
    cout << "Creating good creature clone..." << endl;
    cout << "Good creature clone created successfully!" << endl;
}

bool Good_Creature::is_a_good() // Returns true cause the creature is good
{
    return true;
}

Creature *Good_Creature::clone() // Returns a creature with the same characteristics
{
    Good_Creature *creature = new Good_Creature(*this);

    return creature;
}

bool Good_Creature::bless() // bless the Creature if itsn't zombie
{
    if (is_a_zobie() == false)
    {
        health++;
        cout << "Creature blessed!" << endl;
        if (health > thrsh)
            return true;
        else
            return false;
    }
    else
        return false;
}

Good_Creature::~Good_Creature() // Destructor
{
    cout << "Destroying good_creature..." << endl;

    cout << "Completed" << endl;
}