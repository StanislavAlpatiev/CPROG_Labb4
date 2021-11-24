// Stanislav Alpatiev stal5991@student.su.se
//  Trad.cpp
//  labb4_tree

// #include <iostream>
// #include <cassert>
// #include "Trad.h"

// template <class T>
// void Trad<T>::kopiera(const Trad<T> &t)
// {
//     //std::cout << "*** Trad::kopiera\n";
//     if (t.tomt())
//         rot = 0;
//     else
//     {
//         rot = new Nod(t.varde());
//         v_barn().kopiera(t.v_barn());
//         h_barn().kopiera(t.h_barn());
//     }
// }

// template <class T>
// Trad<T> &Trad<T>::operator=(const Trad<T> &t)
// {
//     //std::cout << "*** Trad::operator=\n";
//     if (rot != t.rot)
//     {
//         delete rot;
//         kopiera(t);
//     }
//     return *this;
// }

// template <class T>
// bool Trad<T>::operator==(const Trad<T> &t) const
// {
//     //std::cout << "*** Trad::operator==\n";
//     return (tomt() && t.tomt()) ||
//            (!tomt() && !t.tomt() && varde() == t.varde() &&
//             v_barn() == t.v_barn() && h_barn() == t.h_barn());
// }

// template <class T>
// void Trad<T>::skriv_ut() const
// {
//     // traversera igenom trädet rekursivt enligt principen "in-order"
//     if (!tomt())
//     {
//         v_barn().skriv_ut();
//         std::cout << varde() << ' ';
//         h_barn().skriv_ut();
//     }
// }

// template <class T>
// void Trad<T>::satt_in(const T &value)
// {
//     if (tomt())
//     {
//         rot = new Nod(value);
//     }
//     else
//     {
//         if (value < rot->data)
//         {
//             v_barn().satt_in(value);
//         }
//         else if (value == rot->data)
//         {
//             return;
//         }
//         else
//         {
//             h_barn().satt_in(value);
//         }
//     }
// }

// template <class T>
// T Trad<T>::sok(const T &value) const
// {
//     if (tomt())
//     {
//         return 0;
//     }
//     else if (value == rot->data)
//     {
//         return value;
//     }
//     else if (value < rot->data)
//     {
//         return v_barn().sok(value);
//     }
//     else
//     {
//         return h_barn().sok(value);
//     }
// }

// template class Trad<double>;
// template class Trad<int>;
// template class Trad<short>;