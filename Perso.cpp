#include "Perso.h"

using namespace std;

Perso::Perso() : m_pv(100), m_pot(3), m_wpn(NULL)
{
    m_wpn = new Wpn();
}

Perso::Perso(string n_wpn, int wpn_dmg) : m_pv(100), m_wpn(NULL), m_pot(3)
{
    m_wpn = new Wpn(n_wpn, wpn_dmg);
}

Perso::Perso(Perso const& cpy_perso) : m_pv(cpy_perso.m_pv), m_pot(cpy_perso.m_pot), m_wpn(NULL)
{
    m_wpn = new Wpn(*(cpy_perso.m_wpn));
}

Perso::~Perso()
{
    delete m_wpn;
}

Perso& Perso::operator=(Perso const& cpy_perso)
{
    if(this != &cpy_perso)
    {
        m_pv = cpy_perso.m_pv;
        m_pot = cpy_perso.m_pot;
    delete m_wpn;
        m_wpn = new Wpn(*(cpy_perso.m_wpn));
    }
    return *this;
}

void Perso::atk(Perso &target)
{
    target.dmg(m_wpn->getDmg());
    
    if(target.is_alive())
        cout << "Vous avez tue votre adversaire." << endl;
}
                
void Perso::dmg(int nbr_dmg)
{
    m_pv -= nbr_dmg;
    
    cout << "Vous avez inflige " << nbr_dmg << " degats a votre adversaire."  << endl;
    
    if(m_pv < 0)
        m_pv = 0;
}

void Perso::heal()
{
    m_pv += 5;
    m_pot--;

    cout << "Vous avez  bu une potion, vous avez recupere 5 pv." << endl;
    cout << "Il vous reste " << m_pot << " potions." << endl;

    if(m_pv > 20)
        m_pv = 20;
}

bool Perso::is_alive() const
{
    if(m_pv)
        return(false);
    else
        return(true);
}

void Perso::change_wpn(string new_n_wpn, int new_wpn_dmg)
{
    m_wpn->change(new_n_wpn, new_wpn_dmg);
}

void Perso::show_state(ostream& flux) const
{
    flux << "Pv : " << m_pv << endl;
    flux << "Potions : " << m_pot << endl;
    m_wpn->show_wpn(flux);
    flux << endl;
}

ostream& operator<<(ostream& flux, Perso const& p1)
{
    p1.show_state(flux);
    return(flux);
}