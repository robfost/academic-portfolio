#include "card.h"

class Hand
{
public:
    Hand();    
    virtual ~Hand();
    void Draw(Card* pCard); 
    void Clear();  
    int GetHandSize() const; 
    int GetTotal() const;
    //int Hand::GetScore(Player& aPlayer);

protected:
    static int m_Score;
    vector<Card*> m_Cards;
};

Hand::Hand()
{}

Hand::~Hand()  
{
    Clear();
}

void Hand::Draw(Card* pCard)
{
    m_Cards.push_back(pCard);
}

void Hand::Clear()
{
    //iterate through vector, freeing all memory on the heap
    vector<Card*>::iterator iter = m_Cards.begin();
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
    {
        delete *iter;
        *iter = 0;
    }
    //clear vector of pointers
    m_Cards.clear();
}

int Hand::GetHandSize() const
{
    return m_Cards.size();
}

int Hand::GetTotal() const
{
    //if no cards in hand, return 0
    if (m_Cards.empty())
        return 0;
        
    int total = 0;
    vector<Card*>::const_iterator iter;
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
        total += (*iter)->GetValue(); 
            
    return total;
}

/*int Hand::GetScore(Player& aPlayer)
{
    m_Score += GetTotal(aPlayer);
    
    int score = m_score;
    
    return score;
}*/
