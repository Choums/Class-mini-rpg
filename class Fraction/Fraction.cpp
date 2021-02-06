#include <iostream>
#include "Fraction.h"

using namespace std;

fract::fract(int num, int den) : m_num(num), m_den(den)
{}

void fract::simp()
{
    int div = PGCD(m_den, m_num);
    m_num /= div;
    m_den /= div;
}

int PGCD(int a, int b)
{
    while(b) //cf. Algo. d'Euclide.
    {
        int i = b;
        b = a % b;
        a = i;
    }
    return(a);
}

bool fract::is_equal(fract const& fr) const
{
    if(m_den == fr.m_den)
        return(true);
    else
        return(false);
}

void fract::show(ostream& flux) const
{
    flux << m_num << '/' << m_den << ' ';
}

bool fract::inf(fract const& fr) const
{
    return(m_den < fr.m_den);
}

bool operator==(fract const& fr1, fract const& fr2)
{
    return(fr1.is_equal(fr2));
}

bool operator<(fract const& fr1, fract const& fr2)
{
    return(fr1.inf(fr2));
}

bool operator>(fract const& fr1, fract const& fr2)
{
    return!(fr1 < fr2);
}

ostream& operator<<(ostream& flux, fract const& fr)
{
    fr.show(flux);
    return(flux);
}

void fract::operator+=(fract const& fr)
{
    fract b(fr); //fr ne peut être multiplier, b sert de substitution.
    if(m_den == fr.m_den) //Vérifie si les dénominateurs sont égaux et additionne les numérateurs. a/D + b/D => a+b/D.
        m_num += fr.m_num;
    else if(!((m_den % fr.m_den) || (fr.m_den % m_den))) //vérifie si les 2 dénominateurs sont des multiples et les additionne.
    {
        int q(0); //Quotient pour multiplier le déno. et le numé.

        if(m_den < fr.m_den)//Trouve le multiple et multiplie le numérateur et le dénominateur par le quotient.
        {
            q = fr.m_den / m_den;
            m_den *= q;
            m_num *= q;
        }
        else
        {
            q = m_den / fr.m_den;
            b.m_den *= q;
            b.m_num *= q;
        }
        m_num += b.m_num; //Add. les numérateurs.
    }
    else //Pour dénominateurs diff. et non multiple.  a/b + c/d => a*d/b*d + c*b/d*b.
    {
        b.m_num *= m_den;
        b.m_den *= m_den;
        
        m_num *= fr.m_den;
        m_den *= fr.m_den;

        m_num += b.m_num;
    }
}

void fract::operator-=(fract const& fr) //Même code qu'operator+= sauf que les + sont des -.
{
    fract b(fr);
    if(m_den == fr.m_den)
        m_num -= fr.m_num;
    else if(!((m_den % fr.m_den) || (fr.m_den % m_den)))
    {
        int q(0);

        if(m_den < fr.m_den)
        {
            q = fr.m_den / m_den;
            m_den *= q;
            m_num *= q;
        }
        else
        {
            q = m_den / fr.m_den;
            b.m_den *= q;
            b.m_num *= q;
        }
        m_num -= b.m_num;
    }
    else
    {
        b.m_num *= m_den;
        b.m_den *= m_den;
        
        m_num *= fr.m_den;
        m_den *= fr.m_den;

        m_num -= b.m_num;
    }
}

void fract::operator*=(fract const& fr)
{
    m_num *= fr.m_num;
    m_den *= fr.m_den;
}

fract operator+(fract const& fr1, fract const& fr2)
{
    fract sum(fr1);
    sum += fr2;
    sum.simp();
    return(sum);
}

fract operator-(fract const& fr1, fract const& fr2)
{
    fract sub(fr1);
    sub -= fr2;
    sub.simp();
    return(sub);
}

fract operator*(fract const& fr1, fract const& fr2)
{
    //simp
    fract mul(fr1);
    mul *= fr2;
    mul.simp();
    return(mul);
}