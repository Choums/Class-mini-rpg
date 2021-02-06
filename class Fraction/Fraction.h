#ifndef FRACTION_H_INCLUDED
#define FRACTION_H_INCLUDED

#include <iostream>

class fract{
    public:
    fract(int m_num=1, int m_den=1);
    bool is_equal(fract const&) const;
    bool inf(fract const&) const;
    void show(std::ostream&) const;
    void simp();
    void operator+=(fract const&);
    void operator-=(fract const&);
    void operator*=(fract const&);
    private:
    int m_num;
    int m_den;
};

bool operator==(fract const&, fract const&);
bool operator<(fract const&, fract const&);
bool operator>(fract const&, fract const&);
std::ostream& operator<<(std::ostream&, fract const&);
fract operator+(fract const&, fract const&);
fract operator-(fract const&, fract const&);
fract operator*(fract const&, fract const&);
int PGCD(int, int);
#endif