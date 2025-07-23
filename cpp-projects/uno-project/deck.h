#include "computer.h"

class Deck : public Hand
{
public:
    Deck();    
    virtual ~Deck();
    //create a standard deck of 52 cards
    void Populate();
    //shuffle cards
    void Shuffle();
    //deal one card to a hand
    void Deal(Hand& aHand);
};

Deck::Deck()
{ 
    m_Cards.reserve(108);
    Populate();
}

Deck::~Deck()
{}

void Deck::Populate()
{
    Clear();
    //create first half of deck
    for (int c = Card::BLUE; c <= Card::YELLOW; ++c)
            for (int f = Card::ZERO; f <= Card::DRAWTWO; ++f)
                Draw(new Card(static_cast<Card::number>(f), static_cast<Card::color>(c)));
    //create second half of deck (without zeros)           
    for (int c = Card::BLUE; c <= Card::YELLOW; ++c)
            for (int f = Card::ONE; f <= Card::DRAWTWO; ++f)
                Draw(new Card(static_cast<Card::number>(f), static_cast<Card::color>(c)));
    //create wild cards
    for (int w = 0; w < 4; w++)
        {
             Draw(new Card(WILD, WILD));
             Draw(new Card(DRAWFOUR, WILD));
        }
}

void Deck::Shuffle()
{
    random_shuffle(m_Cards.begin(), m_Cards.end());
}

void Deck::Deal(Hand& aHand)
{
    if (!m_Cards.empty())
    {
        aHand.Draw(m_Cards.back());
        m_Cards.pop_back();
    }
    else
    {
        cout << "Out of cards. Unable to deal.";
    }
}
