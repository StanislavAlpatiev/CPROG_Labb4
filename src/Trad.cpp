// Stanislav Alpatiev stal5991@student.su.se
//  Trad.cpp
//  labb4_tree

#include <iostream>
#include "Trad.h"

void Trad::kopiera(const Trad &t)
{
    //std::cout << "*** Trad::kopiera\n";
    if (t.tomt())
        rot = 0;
    else
    {
        rot = new Nod(t.varde());
        v_barn().kopiera(t.v_barn());
        h_barn().kopiera(t.h_barn());
    }
}

Trad &Trad::operator=(const Trad &t)
{
    //std::cout << "*** Trad::operator=\n";
    if (rot != t.rot)
    {
        delete rot;
        kopiera(t);
    }
    return *this;
}

bool Trad::operator==(const Trad &t) const
{
    //std::cout << "*** Trad::operator==\n";
    return (tomt() && t.tomt()) ||
           (!tomt() && !t.tomt() && varde() == t.varde() &&
            v_barn() == t.v_barn() && h_barn() == t.h_barn());
}

void Trad::skriv_ut() const
{
    // traversera igenom trädet rekursivt enligt principen "in-order"
    if (!tomt())
    {
        v_barn().skriv_ut();
        std::cout << varde() << ' ';
        h_barn().skriv_ut();
    }
}

void Trad::satt_in(const int &value)
{
    if (tomt)
    {
        Trad(value);
    }
    else
    {
        if (sok(value))
        {
            navigateDownTree(value);
        }
    }
}

void Trad::navigateDownTree(const int &value)
{
    if (value < rot->data && rot->vanster->rot->data == 0)
    {
        rot->vanster->rot->data = value;
    }
    else if (value > rot->data && rot->hoger->rot->data == 0)
    {
        rot->hoger->rot->data = value;
    }
    else if (value != rot->data && value < rot->data)
    {
        rot->vanster->navigateDownTree(value);
    }
    else if (value != rot->data && value > rot->data)
    {
        rot->hoger->navigateDownTree(value);
    }
    else
    {
        std::cout << "Value is eaqual to existing node!" << std::endl;
    }
}

bool Trad::sok(const int &value)
{
    if (rot->vanster->rot->data == 0 && rot->vanster->rot->data == 0 && value != rot->data)
    {
        return 0;
    }
    else if (value == rot->data)
    {
        return 1;
    }
    else if (value != rot->data && rot->vanster && value < rot->data)
    {
        rot->vanster->sok(value);
    }
    else if (value != rot->data && rot->hoger != 0 && value > rot->data)
    {
        rot->hoger->sok(value);
    }
}
