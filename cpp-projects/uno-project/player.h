#include "hand.h"

class Player : public Hand
{
    friend ostream& operator<<(ostream& os, const Player& aPlayer);

public:
    Player(const string& name = "");    
    virtual ~Player();
    //bool Player::IsWinner() const;
    void Bust() const;    
    void Uno() const;

protected:
    string m_Name;
};

Player::Player(const string& name): 
    m_Name(name)
{}

Player::~Player()  
{}

/*bool Player::IsWinner() const
{ 
    if (GetScore() > 500)
    {
       cout << m_Name << " has reached 500 points and won the game!";
       return true;
       }
}*/

void Player::Bust() const
{
    cout << m_Name << " wins the round.\n";
}

void Player::Uno() const
{
     cout << m_Name << " yells UNO!\n";
}
