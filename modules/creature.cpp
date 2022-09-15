#include "../headers/creature.h"


Creature::Creature(string Name, int Health) : name{Name}, health{Health} // Constructor
{
    cout << "Creating creature... " << endl;
    cout << "Creature name: " << name << " created successfully!" << endl;
}

Creature::Creature(const Creature &cret) : health(cret.health), name(cret.name) // Copy-Constructor
{
    cout << "Creating a clone..." << endl;

    cout << "Creature " << name << " cloned successfully!" << endl;
}

bool Creature::is_a_zobie() // Returns true or false if it is zombie or not 
{
    if (health == 0)
        return true;
    else
        return false;
}

void Creature::beat() // Beats the creature if its not zombie
{
    if (is_a_zobie() == false)
    {
        if (health > 0)
        {
            cout << "Creature get attacked!" << endl;
            health--;
        }
    }
}

void Creature::print() // printing the creature
{
    cout << "Name: " << name << " Health: " << health << endl;
}

Creature::~Creature() // Destructor
{
    cout << "Destroying creature... " << endl;
    cout << "Creature name: " << name << " destroyed successfully!" << endl;
}