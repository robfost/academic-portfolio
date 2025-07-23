class Card
{
public:
    enum face {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, REVERSE, SKIP, DRAWTWO, WILD, DRAWFOUR};           
    enum color {BLUE, GREEN, RED, YELLOW, ANYCOLOR};

    //overloading << operator so can send Card object to standard output 
    friend ostream& operator<<(ostream& os, const Card& aCard);
    
    Card(face f = ZERO, color c = BLUE); 
    
    int GetFace() const;
    //returns the value of a card, 1 - 11
    int GetValue() const;
    
    bool ValidPlay(const Card* CardPlayed) const;

    //flips a card; if face up, becomes face down and vice versa
    void Flip();
    
private:
    face m_Face;
    color m_Color;
};

Card::Card(face f, color c):  m_Face(f), m_Color(c)
{} 

int Card::GetFace() const
{
    return m_Face;
}

int Card::GetValue() const
{
    int value = m_Face;
    
    if (value > 9 && value < 13)
       value = 20;
       
    if (value > 12)
       value = 50;
       
    return value;
}

bool Card::ValidPlay(const Card* CardPlayed)const
{
		return (((CardPlayed->m_Color) & (m_Color)) || ((CardPlayed->m_Face) == (m_Face)) ||
			     (CardPlayed->m_Color == ANYCOLOR));
}

