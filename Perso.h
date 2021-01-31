#ifndef PERSO_H_INCLUDED
#define PERSO_H_INCLUDED

#include <iostream>
#include <string>
#include "Wpn.h"

class Perso
{
    public:
    Perso();
    Perso(std::string, int);
    Perso(Perso const&); //cpy
    ~Perso();
    Perso& operator=(Perso const&);
    void atk(Perso &target);
    void dmg(int);
    void heal();
    bool is_alive() const;
    void change_wpn(std::string, int);
    void show_state(std::ostream&) const;
    private:
    int m_pv;
    int m_pot;
    Wpn *m_wpn;
};

std::ostream& operator<<(std::ostream&, Perso const&);

#endif