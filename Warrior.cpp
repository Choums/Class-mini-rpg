#include "Perso.h"

using namespace std;

Warrior::Warrior(string name) : Perso(name), m_def(5)
{}

Warrior::Warrior(string name, string wpn, int wpn_dmg) : Perso(name, wpn, wpn_dmg), m_def(5)
{}

Warrior::Warrior(string name, string wpn, int wpn_dmg, int armor) : Perso(name, wpn, wpn_dmg), m_def(armor)
{}

void Warrior::fierce_atk(Perso &target)
{
    target.dmg(m_wpn->getDmg()*2);
    
    if(target.is_alive())
        cout << "Vous avez tue " << target.m_name << " !" << endl;
}

void Warrior::dmg(int nbr_dmg)
{
    m_pv -= nbr_dmg - m_def;
    
    cout << "Vous avez inflige " << nbr_dmg << " degats a votre adversaire."  << endl;
}

void Warrior::reinforcement()
{
    m_def += 10;
    cout << "Vous serrez les dents et absorbez plus degats !" << endl;
}

void Warrior::show_state(ostream& flux) const
{
    Perso::show_state(flux);
    flux << "Def : " << m_def << endl << endl;
}