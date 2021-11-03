//
// Zac's Monster Game: a game where you fight monsters
//                     that's all you really need to know
// Made with C++
// Written by Zac2211
//

// Include needed headers
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

int main()
{

    // Introduce beginning variables
    int devmodeOn;
    int playerHealth;
    int monsterHealth;
    int monsterDamage;
    int playerDamage;
    int cookieAmount;
    int runDieRoll;
    string monsterName;
    string playerChoice;
    string playerName;
    string playerWeapon;
    string playerWeaponLetter;

    // Seed the random function
    srand(time(NULL));

    // Give starting variables values
    devmodeOn = 0;
    playerHealth = 100;
    monsterHealth = 100;
    cookieAmount = rand() % 2387 + 389492;

    // Determine player name
    cout << "What is your name? Please no spaces. $ ";
    cin >> playerName;
    cout << "You have chosen " << playerName << " as your name" << endl;

    // Enable devmode (a lot of player health)
    if (playerName == "zac2211")
    {
        cout << "Devmode activated!" << endl;
        devmodeOn = 1;
    }
    else
    {
        cout << "Not devmode. Begin game!" << endl;
    }

    // Give intro and get monster name
    cout << "You are in a room. There is a monster." << endl;
    cout << "What do you want to name the monster? $";
    cin >> monsterName;

    // Give extra health for devmode
    if (devmodeOn == 1)
    {
        playerHealth = 1000000003;
    }

    // Game main loop, ends when either monster or player has no health left
    while(monsterHealth > 0)
    {

        // Give info about current health
        cout << monsterName << " has " << monsterHealth << " health" << endl;
        cout << playerName << " has " << playerHealth << " health" << endl;

        // Get player choice
        cout << "What do you do? (f for fight, r for run) $ ";
        cin >> playerChoice;

        // Do actions on player choice
        if (playerChoice == "f")
        {
            cout << playerName << " chose to fight" << endl;
            // Determine monster damage and hurt player
            monsterDamage = rand() % 16;
            cout << monsterName << " did " << monsterDamage << " damage" << endl;
            playerHealth = playerHealth - monsterDamage;
            cout << playerName << " now has " << playerHealth << " health" << endl;

            // Determine if player is dead
            if (playerHealth < 1)
            {
                cout << playerName << " lost all their health and died. Better luck next time";
                return(0);
            }

            // If not dead, ask player what weapon they would use
            cout << "Do you want to attack with sword or bow? (s for sword, b for bow.) $";
            cin >> playerWeaponLetter;
            if (playerWeaponLetter == "s")
            {
                playerWeapon = "sword";
            }
            else
            {
                playerWeapon = "bow";
            }

            // Determine damage done by player and hurt monster
            if (playerWeapon == "sword")
            {
                playerDamage = rand () % 21;
            }
            else
            {
            playerDamage = rand () % 5 + 10;
            }
            cout << playerName << " did " << playerDamage << " damage with the " << playerWeapon << endl;
            monsterHealth = monsterHealth - playerDamage;
            cout << monsterName << " now has " << monsterHealth << " health" << endl;

        }
        else
        {
            if (playerChoice == "r")
            {
                cout << playerName << " chose to run" << endl;
                runDieRoll = rand () % 6;
                if (runDieRoll == 0)
                {
                    cout << "Oh no! The monster caught you and hit you with his club!" << endl;
                    cout << playerName << " takes 50 damage" << endl;
                    playerHealth = playerHealth - 50;

                    // Determine if player is dead
                    if (playerHealth < 1)
                    {
                        cout << playerName << " lost all their health and died. Better luck next time";
                        return(0);
                    }
                }
                else
                {
                    cout << "Good job! You ran from the monster and will take no damage!" << endl;
                    cout << "Whoops! The monster accidentally pokes himself in the eye!" << endl;
                    cout << "He takes 10 damage, but he's mad and he finds you again!" << endl;
                    monsterHealth = monsterHealth - 10;
                }
            }

            // Stop people from choosing things other than f or r
            else
            {
                cout << "That's not a choice. Try again";
            }
        }

        // Seperate turns with a endl
        cout << " " << endl;
    }

    // Give the player congrats for winning and some cookies
    cout << "Wow! You defeated the great monster " << monsterName << " and saved the day!" << endl;
    cout << "You win " << cookieAmount << " cookies! Thanks for playing!";
    return(0);
}

//
// Todo:
// Give monster different attacks
// Add a score system
// Some lore?
// Treasure system?
// Add attack with magic
//
