#ifndef WPN_H_INCLUDED 
#define WPN_H_INCLUDED

#include <iostream>
#include <string>

class Wpn
{
    public:
    Wpn();
    Wpn(std::string n_wpn, int wpn_dmg);
    int getDmg() const;
    void change(std::string, int);
    void show_wpn(std::ostream&) const;
    private:
    int m_wpn_dmg;
    std::string m_wpn;
};

std::ostream& operator<<(std::ostream&, Wpn const&);

#endif