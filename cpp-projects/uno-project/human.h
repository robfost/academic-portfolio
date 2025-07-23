#include "player.h"

class Human : public Player
{
public:
    Human(const string& name = "");
    virtual ~Human();
    
    virtual Card* Discard(Card* LastCard);
    void ShowCards();
};

Human::Human(const string& name): 
    Player(name)
{}

Human::~Human()
{}
    
Card* Human::Discard(Card* LastCard)
{
     ShowCards();
     
     Card *discard = NULL;
     
     int choice = -1;
     while (!discard)
     {
     while (choice < 0 || choice > m_Cards.size())
     {
           cout << "The card on the Discard pile is a " << *LastCard << endl;
           cout << "Choose a card to play or press 0 to draw.";
           cin >> choice;
           
           if (choice == 0)
              return NULL;
           else
              discard = m_Cards[choice-1];
              return discard;
     }
     
     m_Cards.erase(m_Cards.begin() + choice);
     return discard;
}}

void Human::ShowCards()
{
/*for(int num = 1; num < m_Cards.size(); num++);
		{
            cout << "  \n" << num << " ";
		}
		cout << endl;*/

    
    vector<Card*>::const_iterator pCard;
    if (m_Cards.empty())
    {
        for (pCard = m_Cards.begin(); 
             pCard != m_Cards.end(); ++pCard)
            cout << *(*pCard) << " \n";

        if (GetTotal() != 0)
            cout << "(" << GetTotal() << ")";
    }
    else
    {
        cout << "<empty>";
    }
