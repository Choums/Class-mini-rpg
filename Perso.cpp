#include "Perso.h"

using namespace std;

Perso::Perso(string name) : m_pv(100), m_name(name), m_pot(3), m_wpn(NULL)
{
    m_wpn = new Wpn();
}

Perso::Perso(string name, string n_wpn, int wpn_dmg) : m_pv(100), m_name(name), m_wpn(NULL), m_pot(3)
{
    m_wpn = new Wpn(n_wpn, wpn_dmg);
}

Perso::Perso(Perso const& cpy_perso) : m_pv(cpy_perso.m_pv), m_name(cpy_perso.m_name), m_pot(cpy_perso.m_pot), m_wpn(NULL)
{
    m_wpn = new Wpn(*(cpy_perso.m_wpn)); //Le constru. de copie de Wpn reçoit un obj. hors m_wpn est un pointeur donc * avant pour envoyer l'abj.
}

Perso::~Perso()
{
    delete m_wpn;
}

Perso& Perso::operator=(Perso const& cpy_perso)
{
    if(this != &cpy_perso) //Vérifie que les 2 obj. soient diff.
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
        cout << "Vous avez tue " << target.m_name << " !" << endl;
}
                
void Perso::dmg(int nbr_dmg)
{
    m_pv -= nbr_dmg;
    
    cout << "Vous avez inflige " << nbr_dmg << " degats"  << endl;
}

void Perso::heal()
{
    m_pv += 15;
    m_pot--;

    cout << "Vous avez  bu une potion, vous avez recupere 5 pv." << endl;
    cout << "Il vous reste " << m_pot << " potions." << endl;

    if(m_pv > 100)
        m_pv = 100;
}

bool Perso::is_alive() const
{
    return(m_pv);
}

void Perso::change_wpn(string new_n_wpn, int new_wpn_dmg)
{
    m_wpn->change(new_n_wpn, new_wpn_dmg);
}

void Perso::show_state(ostream& flux) const
{
    flux << m_name << endl;
    flux << "Pv : " << m_pv << endl;
    flux << "Potions : " << m_pot << endl;
    m_wpn->show_wpn(flux);
}

ostream& operator<<(ostream& flux, Perso const& p1)
{
    p1.show_state(flux);
    return(flux);
}

ostream& operator<<(ostream& flux, Mage const& p1)
{
    p1.show_state(flux);
    return(flux);
}

ostream& operator<<(ostream& flux, Warrior const& p1)
{
    p1.show_state(flux);
    return(flux);
}