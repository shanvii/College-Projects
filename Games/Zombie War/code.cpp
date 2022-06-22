#include <iostream> 
#include <unistd.h> 
#include <time.h> 

using namespace std; 

int createZombie() 
{ 

    if (rand() % 67 < 10) 
        return 11; 

    else 
        return rand() % 10 + 1; 

} 

void message(int zombieCount) // message from zombies 
{ 
    if (zombieCount < 5) 
        cout << endl 
             << "                         < You wish to fight only " << zombieCount << " Zombies!! SHAME SHAME COWARD >" << endl 
             << "                                       ~ We Zombies have a big army ^O^ ~" << endl; 

    else if (zombieCount < 10) 
        cout << endl 
             << "                        < HA HA HA ... You think you can win against Zombies ^O^ ^o^ ^O^ >" << endl 
             << "                                       ~ Keep Dreaming ~" << endl; 

    else 
        cout << endl 
             << "                         < Zombies ^O^ see overconfident rival!! ^O^ ^o^ ^O^ >" << endl 
             << "                               ~ So you think you can win uhh ~" << endl; 

        cout << "                          < It's the Zombies battlefield ^O^ ^o^ ^O^ >" << endl 
         << endl; 
} 

int main() 
{ 
    srand(time(NULL)); 
    char enter; 

    // initial 
    int playerAlive = true; 

    int playerSkill = 9; 

    int playerScore = 1; 

    string playerName = ""; 

    int zombieCount = 0; 

    int zombiesKilled = 0; 


    // welcome message 
    cout << endl 
         << endl 
         << "                           ^O^ ^o^ ^O^ ^o^^ ^O^ ^o^ ^O^ ^o^ ^O^ ^o^ ^O^ ^o^ ^O^ ^O^ " << endl 
         << "                                     - Welcome to Zombie War ^O^ -" << endl 
         << "                                       Press -> ENTER <- to start." << endl 
         << "                           ^O^ ^o^ ^O^ ^o^^ ^O^ ^o^ ^O^ ^o^ ^O^ ^o^ ^O^ ^o^ ^O^ ^O^ " << endl; 

    cin.get(); 

 
    // player name 
    cout << endl 
         << "Enter your name: "; 
    cin >> playerName; 

 
    // no of zombies 
    cout << "How many Zombies ^O^ do you wish to fight? "; 
    cin >> zombieCount; 

    message(zombieCount); //function 

    cout << endl 
         << "Get ready to fight for your life, " << playerName << "! Because Zombies always win" << endl 
         << endl; 


    // main game loop 
    while (playerAlive && zombiesKilled < zombieCount) 
    { 
        // create a random zombie 
        int zombieSkill = createZombie(); 

        // battle sequence 
        if (zombieSkill > 10)
        { 
            cout << endl 
                 << "Here comes a huge zombie! ^O^ " << endl << "You little you cannot win against an Ancient Zombie ^O^ " << endl; 
        } 

        else 
        { 
            cout << endl 
                 << "Here comes Zombie ^o^" << zombiesKilled + 1 << endl; 
        } 

        cout << "Fighting...*x* " << endl; 
        sleep(2); 


        // zombie killed the player 
        if (playerSkill < zombieSkill) 
        { 
            playerAlive = false; 
            cout << "Zombie killed you.... x HA HA HA" << endl; 
        } 

 
        // player killed the zombie 
        else 
        { 
            if (playerSkill - zombieSkill > 7) 
            { 
                cout << "You wasted the Zombie!!" << endl; 
                playerScore = playerScore * 2; 
            } 

            else if (playerSkill - zombieSkill > 5) 
            { 
                cout << "You decapitated the Zombie.. How dare you!! " << endl; 
                playerScore = playerScore * 2; 
            } 

            else if (playerSkill - zombieSkill > 0) 
            { 
                cout << "You killed the Zombie!!" << endl; 
                playerScore = playerScore * 2; 
            } 

            else 
            { 
                cout << "You killed the Zombie! But suffered injuries... sad:(" << endl; 
            } 

            zombiesKilled++; 
        } 

        cout << endl; 
        sleep(1); 
    } 
    

    // end game 
    if (zombiesKilled == zombieCount) 
    { 
        // victory 
        cout << "                           Congratulations!! You have survived the onslaught. " << endl 
             << "                           The battlefield now belongs to you *x* " << endl; 
    } 
    
    else 
    { 
        // lost 
        cout << "                            Aww!! You did not survive the Zombie war..." << endl 
             << "                           Told ya ~It's the Zombies battlefield ^O^ " << endl; 
    } 

 
    cout << endl 
         << endl 
         << "                            ---------------------------------------------" << endl 
         << "                                           -Score Board-            " << endl 
         << "                                        Zombies killed: " << zombiesKilled << endl 
         << "                                         Final score: " << playerScore << endl 
         << "                            ---------------------------------------------" << endl 
         << endl; 
} 
