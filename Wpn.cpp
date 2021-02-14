#include "Wpn.h"

using namespace std;

Wpn::Wpn() : m_wpn("Poings"), m_wpn_dmg(12)
{}

Wpn::Wpn(std::string n_wpn, int wpn_dmg) : m_wpn(n_wpn), m_wpn_dmg(wpn_dmg)
{}

int Wpn::getDmg() const
{
    return(m_wpn_dmg);
}

void Wpn::change(string n_wpn, int wpn_dmg)
{
    cout << "Voulez-vous changer d'arme ? 1/0" << endl;
    int i(0);
    cin >> i;
    
    if(i)
    {
        m_wpn = n_wpn;
        m_wpn_dmg = wpn_dmg;
        cout << "Vous avez equipe " << n_wpn << ", elle inflige " << wpn_dmg << " de degats." << endl;
    }
}

void Wpn::show_wpn(ostream& flux) const
{
    flux << m_wpn <<  " : " << m_wpn_dmg << " degats." << endl;
}

ostream& operator<<(ostream& flux, Wpn const& wpn)
{
    wpn.show_wpn(flux);
    return(flux);
}