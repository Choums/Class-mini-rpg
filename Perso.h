#ifndef PERSO_H_INCLUDED
#define PERSO_H_INCLUDED

#include <iostream>
#include <string>
#include "Wpn.h"

class Perso
{
    public:
    Perso(std::string);
    Perso(std::string ,std::string, int);
    Perso(Perso const&); //cosntru. cpy
    ~Perso();
    Perso& operator=(Perso const&); //cpy.
    void atk(Perso &target);
    void dmg(int);
    void heal();
    bool is_alive() const;
    void change_wpn(std::string, int);
    void show_state(std::ostream&) const;
    protected:
    unsigned int m_pv;
    std::string m_name;
    unsigned int m_pot;
    Wpn *m_wpn;
};

class Warrior : public Perso
{
    public:
    Warrior(std::string);
    Warrior(std::string, std::string, int);
    Warrior(std::string, std::string, int, int);
    void reinforcement();
    void fierce_atk(Perso &target);
    void dmg(int);
    void show_state(std::ostream&) const;
    private:
    unsigned int m_def;
};

class Mage : public Perso
{
    public:
    Mage(std::string);
    Mage(std::string, std::string, int);
    void fireball(Perso &target);
    void healing();
    void show_state(std::ostream&) const;
    private:
    unsigned int m_mana;
};

std::ostream& operator<<(std::ostream&, Perso const&);
std::ostream& operator<<(std::ostream&, Mage const&);
std::ostream& operator<<(std::ostream&, Warrior const&);
#endif