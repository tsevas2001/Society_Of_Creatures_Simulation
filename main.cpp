#include "headers/creature_society.h"

int main(int argc, char *argv[])
{
    srand(time(NULL));

    int n, m, l, good_thrsh, bad_thrsh;

    // checking if the user is putting the right number of arguments
    if (argc != 6)
    {
        cout << "Wrong amount of arguments!" << endl;
        return 1;
    }

    // convert arguments to integers
    n = atoi(argv[1]);
    m = atoi(argv[2]);
    l = atoi(argv[3]);
    good_thrsh = atoi(argv[4]);
    bad_thrsh = atoi(argv[5]);

    // checking if the inputs are positive
    if (n < 0 || m < 0 || l < 0 || good_thrsh < 0 || bad_thrsh < 0)
    {
        cout << "Inputs must be positive integers!" << endl;
        return 1;
    }

    Creature_Society society(n, l, good_thrsh, bad_thrsh); // creating a society

    society.print(); // printing the society on the begining 

    for (int i = 0; i < m; i++)
    {
        if (rand() % 2 == 0) // random bless or beat
            society.bless(rand() % n);
        else
            society.beat(rand() % n);
    }

    society.print(); // printing the society on the end

    // checing if the society has only good creatures or is a dead society
    if (society.no_of_good() == n)
        cout << "Good Dominates in the World!" << endl;
    else if (society.no_of_zobies() == n)
        cout << "This is a dead society" << endl;
    else
        cout << "Try again to improve the world" << endl;

    return 0;
}
