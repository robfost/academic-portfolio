#include <iostream>

using namespace std;

class Soldier
{
    public:
             static int s_Total;
             
             void Fire();
             void March(int distance);
             int GetAmmo();
             int GetFatigue();
             
             Soldier(int ammo, int fatigue);
             
    private:
             int m_Ammo;
             int m_Fatigue;
};

int Soldier::s_Total = 0;

Soldier::Soldier(int ammo, int fatigue)
{
    m_Ammo = ammo;
    m_Fatigue = fatigue;
    s_Total++;
}

void Soldier::Fire()
{
    if (m_Ammo>0)
        m_Ammo--;
}

void Soldier::March(int distance)
{    
    m_Fatigue = distance * 10;
}

int Soldier::GetAmmo()
{
    return m_Ammo;
}

int Soldier::GetFatigue()
{
    return m_Fatigue;
}

int main()
{
    Soldier soldier1(50, 0);
    Soldier soldier2(50, 0);
    Soldier soldier3(40, 0);
    
    int input;
    int distance;
    
    cout << "Welcome General. You have " << Soldier::s_Total << " soldiers in your command.\n\n";
    
    while(true)
    {
    cout << "Press 1 to have your soldiers fire.\n"
    << "Press 2 to have your soldiers march.\n"
    << "Press 3 to have your soldiers report their ammo.\n"
    << "Press 4 to have your soldiers report their fatigue.\n"
    << "Press 5 to quit.\n\n"
    << "What are your orders? ";
    
    cin >> input;
    
    switch (input)
    {
           case 1:
                system("CLS");
                cout << "Firing!\n\n";
                soldier1.Fire();
                soldier2.Fire();
                soldier3.Fire();
                break;
           case 2:
                system("CLS");
                cout << "How far would you like the soldiers to travel (miles)? ";
                cin >> distance;
                cout << "Moving!\n\n";
                soldier1.March(distance);
                soldier2.March(distance);
                soldier3.March(distance);
                break;
           case 3:
                system("CLS");
                cout << "Report: \n\n"
                << "Soldier 1 ammo: " << soldier1.GetAmmo()
                << "\nSoldier 2 ammo: " << soldier2.GetAmmo()
                << "\nSoldier 3 ammo: " << soldier3.GetAmmo() << "\n\n";
                break;
           case 4:
                system("CLS");
                cout << "Report: \n\n"
                << "Soldier 1 fatigue: " << soldier1.GetFatigue()
                << "\nSoldier 2 fatigue: " << soldier2.GetFatigue()
                << "\nSoldier 3 fatigue: " << soldier3.GetFatigue() << "\n\n";
                break;
           case 5:
                system("CLS");
                cout << "Aborting...\n\n";
                system("PAUSE");
                return 0;
           default:
                system("CLS");
                cout << "Invalid command.\n\n";
                break;
    }}
}
