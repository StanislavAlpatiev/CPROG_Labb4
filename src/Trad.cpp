// Stanislav Alpatiev stal5991@student.su.se
//  Trad.cpp
//  labb4_tree

#include <iostream>
#include "Trad.h"
template <typename T>
void Trad<T>::kopiera(const Trad<T> &t)
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

template <typename T>
Trad<T> &Trad<T>::operator=(const Trad<T> &t)
{
    //std::cout << "*** Trad::operator=\n";
    if (rot != t.rot)
    {
        delete rot;
        kopiera(t);
    }
    return *this;
}

template <typename T>
bool Trad<T>::operator==(const Trad<T> &t) const
{
    //std::cout << "*** Trad::operator==\n";
    return (tomt() && t.tomt()) ||
           (!tomt() && !t.tomt() && varde() == t.varde() &&
            v_barn() == t.v_barn() && h_barn() == t.h_barn());
}

template <typename T>
void Trad<T>::skriv_ut() const
{
    // traversera igenom trädet rekursivt enligt principen "in-order"
    if (!tomt())
    {
        v_barn().skriv_ut();
        std::cout << varde() << ' ';
        h_barn().skriv_ut();
    }
}

template <typename T>
void Trad<T>::satt_in(const T &value)
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

template <typename T>
void Trad<T>::navigateDownTree(const T &value)
{
    if (value < rot->data && rot->vanster->rot->data == 0)
    {
        rot->vanster = new Trad(value);
    }
    else if (value > rot->data && rot->hoger->rot->data == 0)
    {
        rot->hoger = new Trad(value);
    }
    else if (value != rot->data && value < rot->data)
    {
        rot->vanster->navigateDownTree(value);
    }
    else if (value != rot->data && value > rot->data)
    {
        rot->hoger->navigateDownTree(value);
    }
}

template <typename T>
bool Trad<T>::sok(const T &value)
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
