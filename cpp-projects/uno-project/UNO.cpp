#include "main.h"
#include "game.h"

//function prototypes
ostream& operator<<(ostream& os, const Card& aCard);
ostream& operator<<(ostream& os, const Player& aPlayer);

int main()
{
    cout << "\t\tUNO!\n\n";
    
    int numOpponents = 3;
    
    vector<string> names;
    string name;
    for (int i = 0; i < numOpponents; ++i)
    {
        cout << "Enter opponent #" << (int+1) << "'s name: ";
        cin >> name;
        names.push_back(name);
    }
    cout << endl;

    //the game loop        
    Game aGame(names);
    char again = 'y';
    while (again != 'n' && again != 'N')
    {
        aGame.Play();
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> again;
    } 

    return 0;
}

//overloads << operator so Card object can be sent to cout
ostream& operator<<(ostream& os, const Card& aCard)
{
    const string FACES[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", 
                            "R", "S", "D2", "W", "D4"};
    const string COLORS[] = {"b", "g", "r", "y", "w"};

    os << FACES[aCard.m_Face] << COLORS[aCard.m_Color];
    
    return os;
}

//overloads << operator so a GenericPlayer object can be sent to cout
ostream& operator<<(ostream& os, const Player& aPlayer)
{
    os << aPlayer.m_Name << "has"
        
    << aPlayer.GetHandSize() << " cards remaining and a current score of "
    
    << aPlayer.m_Score << endl;
    
    return os;
}
}}
