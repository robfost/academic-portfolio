#include "human.h"

class Computer : public Player
{
public:
    Computer(const string& name = "");
    virtual ~Computer();
    virtual Card* Discard(const Card* LastCard);
};

Computer::Computer(const string& name): 
    Player(name)
{}

Computer::~Computer()
{}

Card* Computer::Discard(Card* LastCard)
{
      sort(m_Cards.begin(), m_Cards.end());
      reverse(m_Cards.begin(), m_Cards.end());
      
      Card *discard = NULL;
      
      for (i=1, i < m_Cards.size(), i++)
          if (m_Cards[i].ValidPlay)
          {             
             discard = m_Cards[i];
             }
             
             m_Cards.erase(m_Cards[i]);
             return discard;
}
