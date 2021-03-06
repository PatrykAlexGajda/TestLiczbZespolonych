#include "WyrazenieZesp.hh"
#include <iostream>

/* Przeciazenie operatora << aby mogl wyswietlac cale wyrazenie zespolone.
    W przypadku pojawienia sie zlego operatora funkcja zwraca odpowiedni komunikat
    Jesli zapis wyrazenia jest poprawny funkcja zwroci to wyrazenie. */

std::ostream &operator<<(std::ostream &str, const WyrazenieZesp &WyrZ)
{
    Operator Oper;
    Oper = WyrZ.Op;

    if(Oper == Op_Dodaj){
    return str << WyrZ.Arg1 << "+" << WyrZ.Arg2 << std::endl;
    } else if(Oper == Op_Odejmij){
    return str << WyrZ.Arg1 << "-" << WyrZ.Arg2 << std::endl;
    } else if(Oper == Op_Mnoz){
    return str << WyrZ.Arg1 << "*" << WyrZ.Arg2 << std::endl;
    } else if(Oper == Op_Dziel){
    return str << WyrZ.Arg1 << "/" << WyrZ.Arg2 << std::endl;
    } else {
        return str << "Niepoprawny operator" << std::endl;
    }

}

/* Funkcja oblicza wyrazenie zespolone.
    Zwraca liczbe zespolona jako wynik danego wyrazenia zespolonego.
    W przypadku pojawienia sie zlego operatora arytmetycznego funkcja zwraca pierwsza
    skladowa wyrazenia i wyswietla odpowiedni komunikat. */

LZespolona Oblicz(WyrazenieZesp WyrZ)
{
    Operator Oper = WyrZ.Op;
    LZespolona Skl1 = WyrZ.Arg1;
    LZespolona Skl2 = WyrZ.Arg2;
    LZespolona Wynik;

    if(Oper == Op_Dodaj)
    {
        Wynik = Skl1 + Skl2;
        return Wynik;
    } 
    else if(Oper == Op_Odejmij)
    {
        Wynik = Skl1 - Skl2;
        return Wynik;
    }
    else if(Oper == Op_Mnoz)
    {
        Wynik = Skl1 * Skl2;
        return Wynik;
    }
    else if(Oper == Op_Dziel)
    {
        Wynik = Skl1 / Skl2;
        return Wynik;
    } 
    else
    {
        std::cerr << "Bledny operator arytmetyczny!" <<std::endl;
        return Skl1;
    }

}