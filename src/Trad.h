// Stanislav Alpatiev stal5991@student.su.se
//  Trad.h
//  labb4_tree

#ifndef TRAD_H
#define TRAD_H

#include <iostream>
#include <cassert>

template <typename T>
class Trad
{
public:
    Trad() : rot(0){}; // default konstruktor
    Trad(T d) { rot = new Nod(d); };
    Trad(const Trad &t) { kopiera(t); }; // kopieringskonstruktor
    ~Trad() { delete rot; };

    bool tomt() const { return !rot; };
    T &varde() const
    {
        koll();
        return rot->data;
    };
    Trad &v_barn() const
    {
        koll();
        return *rot->vanster;
    };
    Trad &h_barn() const
    {
        koll();
        return *rot->hoger;
    };

    Trad &operator=(const Trad &);
    bool operator==(const Trad &) const;
    void skriv_ut() const;
    void satt_in(const T &value);
    T sok(const T &value) const;

private:
    class Nod
    {
        friend class Trad<T>;
        T data;
        Trad *vanster, *hoger;
        Nod(T d) : data(d), vanster(new Trad), hoger(new Trad){};
        ~Nod()
        {
            delete vanster;
            delete hoger;
        };
    }; // end class Nod

    Nod *rot;
    void koll() const
    {
        if (tomt())
            throw std::range_error("Trad");
    }
    void kopiera(const Trad &t);
};

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
    if (tomt())
    {
        rot = new Nod(value);
    }
    else
    {
        if (value < rot->data)
        {
            v_barn().satt_in(value);
        }
        else if (value == rot->data)
        {
            return;
        }
        else
        {
            h_barn().satt_in(value);
        }
    }
}

template <typename T>
T Trad<T>::sok(const T &value) const
{
    if (tomt())
    {
        return 0;
    }
    else if (value == rot->data)
    {
        return value;
    }
    else if (value < rot->data)
    {
        return v_barn().sok(value);
    }
    else
    {
        return h_barn().sok(value);
    }
}

#endif /* Trad_h */
