#include "WyrazenieZesp.hh"
#include <iostream>

LZespolona Utworz(double x, double y)
{
    LZespolona liczba_zesp;
    liczba_zesp.re = x;
    liczba_zesp.im = y;

    return liczba_zesp;
}

void Wyswietl(WyrazenieZesp WyrZ)
{
    LZespolona Zesp1;
    LZespolona Zesp2;
    Operator Oper;
    Oper = WyrZ.Op;
    Zesp1 = WyrZ.Arg1;
    Zesp2 = WyrZ.Arg2;

    std::cout << "(" << Zesp1.re << std::showpos << Zesp1.im << std::noshowpos << "i)"
    << Oper 
    << "(" << Zesp2.re << std::showpos << Zesp2.im << std::noshowpos << "i)" << std::endl;
}

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