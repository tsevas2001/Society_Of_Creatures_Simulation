#include "../headers/creature_society.h"

Creature_Society::Creature_Society(int size, int health, int good_thrsh, int bad_thrsh) : NumOfCreatures{size} // Constructor
{
    cout << "Society of creatures is Creating... " << endl;
    Creatures = new Creature *[NumOfCreatures]; // Creating array of creatures
    string Names[] = {"Bogeyman", "Vampire", "Dybbuk", "Banshee", "Pontianak", "Hydra", "Chimera"}; // Array with the names of the array

    srand(time(NULL));
    for (int i = 0; i <  NumOfCreatures; i++) // A loop to fill the array with creatures
        if (rand() % 2 == 0) // random type of creatures
            Creatures[i] = new Good_Creature(health, Names[rand() % 7] + "_(Good)_" + to_string(i), good_thrsh);
        else
            Creatures[i] = new Bad_Creature(health, Names[rand() % 7] + "_(Bad)_" + to_string(i), bad_thrsh);
    cout << "Society of creatures created successfully!" << endl;
}

void Creature_Society::print() // Printing the creatures
{
    cout << "---------------------------" << endl;
    
    for (int i = 0; i < NumOfCreatures; i++)
        Creatures[i]->print();

    cout << "---------------------------" << endl;
}

void Creature_Society::bless(int position) // Blessing the creature
{
    if (Creatures[position]->is_a_good())  // Checking if the creature is good
    {
        if (Creatures[position]->bless()) // if the health of the creature is above from good_thrsh
            clone_next(position);  // then clone the next creature
    }
    else // then bad
    {
        if (Creatures[position]->bless()) // if the health of the creature is above from bad_thrsh
            clone_zombies(position); // then clone the zombies
    }
}

void Creature_Society::beat(int position) // Beating the creature
{
    Creatures[position]->beat();
}

void Creature_Society::clone_next(int position) // Clones the next creature
{
    if (position < NumOfCreatures - 1) // Checking if the creature is in the last position
    {
        delete Creatures[position + 1]; // Destroying the next creature
        Creatures[position + 1] = Creatures[position]->clone(); // And it clones his self 
    }
    else // then last position
    {
        delete Creatures[0]; // Destroying the creature of the first position
        Creatures[0] = Creatures[position]->clone();
    }
}

void Creature_Society::clone_zombies(int position) // Clones the zombies where are all together
{
    if (position < NumOfCreatures - 1){ // Checking if the creature is in the last position
        int tempIndex; // temporary position
        // checking the current creature if it zombie
        if (Creatures[position]->is_a_zobie() == false) // if not
            // checking if the next tow creatures are zombies and not in the last position
            if ((Creatures[position + 1]->is_a_zobie()) && (position + 2 < NumOfCreatures - 1 && Creatures[position + 2]->is_a_zobie())){
                // checking for the last zombie position
                for (int i = position + 1; i < NumOfCreatures; i++){
                    if (Creatures[i]->is_a_zobie())
                    {
                        tempIndex = i; // in the end it has the last zombie position
                    }
                    else
                        break;
                }
                // checking if the are more than one zombie together
                if (tempIndex - position > 1) // then clone
                {
                    for (int i = position + 1; i <= tempIndex; i++){
                        delete Creatures[i];
                        Creatures[i] = Creatures[position]->clone();
                    }
                }
            }
    }
}

int Creature_Society::no_of_good() // checking how many good creatures has the society
{
    int counter = 0;
    for (int i = 0; i < NumOfCreatures; i++)
        if(Creatures[i]->is_a_good())
            counter++;
    return counter;
}

int Creature_Society::no_of_zobies() // checking how many zombies has the society
{
    int counter = 0;
    for(int i = 0; i < NumOfCreatures; i++)
        if(Creatures[i]->is_a_zobie())
            counter++;
    return counter;
}

Creature_Society::~Creature_Society() // Destructor
{
    cout << "Destroying creature society... " << endl;
    // destroying every creature in the array
    for (int i = 0; i < NumOfCreatures; i++)
        delete Creatures[i];
    delete[] Creatures;

    cout << "Society of creatures destroyed successfully!" << endl;
}