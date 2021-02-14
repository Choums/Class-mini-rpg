#include "Perso.h"

using namespace std;

Mage::Mage(string name) : Perso(name), m_mana(100)
{}

Mage::Mage(string name, string n_wpn, int wpn_dmg) : Perso(name, n_wpn, wpn_dmg), m_mana(100)
{}

void Mage::fireball(Perso &target)
{
    target.dmg(20);
    m_mana =- 25;

    if(target.is_alive())
        cout << "Vous avez tue votre adversaire." << endl;
}

void Mage::healing()
{
    m_pv += 10;
    m_mana -= 20;

    cout << "Vous avez recupere 10 pv" << endl;

   if(m_pv > 100)
        m_pv = 100;
}

void Mage::show_state(ostream& flux) const
{
    Perso::show_state(flux);

    flux << "Mana : " << m_mana << endl << endl;
}