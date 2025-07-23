#include "deck.h"

class Game
{
public:
    Game(const vector<string>& names);    
    ~Game();    
    //plays the game of blackjack    
    void Play();
    void Advance();
    void Reverse();

private:
    Deck m_Deck;
    Hand m_DiscardPile;
    vector<Player> m_Players;
    int m_CurrentPlayer;
    bool m_Forward;
      
};

Game::Game(const vector<string>& names)
{
    m_Forward=true;
    //create a vector of players from a vector of names       
    vector<string>::const_iterator pName;
    string name;
    
    for (pName = names.begin(); pName != names.end(); ++pName)      
        m_Players.push_back(Computer(*pName));
        
    cout << "Enter your name: ";
    cin >> name;
    
    m_Players.push_back(Human(name));
    
    m_CurrentPlayer = m_Players.begin();

    srand(time(0));    //seed the random number generator
    m_Deck.Populate();
    m_Deck.Shuffle();
}

Game::~Game()
{}

void Game::Play()
{         
    //deal initial 7 cards to everyone
    vector<Player>::iterator pPlayer;
    for (int i = 0; i < 7; ++i)
    {
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)      
            m_Deck.Deal(*pPlayer);
    }
    
    //start discard pile
    m_Deck.Deal(m_DiscardPile)    
    
    bool GameOver = false;
    while(!GameOver)
    
    Player* CurrentPlayer = (*m_CurrentPlayer);
    Card* CardPlayed;
    while (true)
    {
    CardPlayed = CurrentPlayer->Discard(m_DiscardPile.back());

    while (CardPlayed == NULL)
    {
         m_Deck.Deal(CurrentPlayer)
         CardPlayed = CurrentPlayer->Discard(m_DiscardPile.back());
    }
    //check that play was valid
    if (m_DiscardPile.back()->ValidPlay(CardPlayed))
        break;
    else
    {
        CurrentPlayer->Draw(CardPlayed);
        cout << "You can't play that card. Try again." << endl;
    }
    }
           
    m_DiscardPile.push_back(CardPlayed);
    cout << "Played a " << *CardPlayed << endl;
    
    switch (CardPlayed->GetFace())
    {
           case SKIP: Advance();
           break;
           case REVERSE: Reverse();
           break;
           case DRAWTWO:
                Advance();
                for (int i = 0; i < 2; i++)
                    m_Deck.Deal(CurrentPlayer));
                break;
           case DRAWFOUR:
                Advance();
                for (int i = 0; i < 4; i++)
                    m_Deck.Deal(CurrentPlayer));
                break;
    }
    
    if (CurrentPlayer->GetHandSize() == 0)
       {
       CurrentPlayer->Bust();
       /*for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
           CurrentPlayer->GetScore(*pPlayer);*/
       }
    else if (CurrentPlayer->GetHandSize() == 1)
       CurrentPlayer->Uno();
    else
       cout << CurrentPlayer << endl;
       
    
    /*if (CurrentPlayer->IsWinner)
       GameOver=true
    else*/
        Advance();
    }

    //remove everyone's cards
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)      
        pPlayer->Clear();
    m_House.Clear();
}

void Game::Advance()
{
     if (m_Forward)
     {
                   m_CurrentPlayer++;
                   if(m_CurrentPlayer == m_Players.end())
                       m_CurrentPlayer = m_Players.begin();
     }
     else
     {
         if(m_CurrentPlayer == m_Players.begin()
             m_CurrentPlayer = m_Players.end();
             m_CurrentPlayer--;
     }
}

void Game::Reverse()
{
     m_Forward = !m_Forward;
}
