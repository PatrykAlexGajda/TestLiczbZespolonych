#include "LZespolona.hh"
#include <iostream>
#include <math.h>


void WyswietlZesp(LZespolona Skl)
{
    std::cout << "(" << Skl.re << std::showpos << Skl.im << std::noshowpos << "i)" << std::endl;
}

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

LZespolona operator - (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

LZespolona operator * (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = (Skl1.re * Skl2.re) - (Skl1.im * Skl2.im);
  Wynik.im = (Skl1.re * Skl2.im) + (Skl1.im * Skl2.re);
  return Wynik;
}

LZespolona ZespPrzezRzecz (LZespolona Skl, double r)
{
  LZespolona Wynik;

  Wynik.re = Skl.re/r;
  Wynik.im = Skl.im/r;
  return Wynik;
}

LZespolona Sprzezenie (LZespolona Skl)
{
  LZespolona Wynik;
  
  Wynik.re = Skl.re;
  Wynik.im = Skl.im;
  return Wynik;
}

double Modul(LZespolona Skl)
{
  double Wynik;
  Wynik = sqrt((Skl.re * Skl.re) + (Skl.im * Skl.im));
  return Wynik;
}

LZespolona operator / (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;
  LZespolona Licznik = Skl1 *Sprzezenie(Skl2);
  double Mianownik = pow(Modul(Skl2), 2);
  Wynik = ZespPrzezRzecz(Licznik, Mianownik);
  return Wynik;
}

bool operator == (LZespolona Skl1, LZespolona Skl2)
{
  bool same;

  if((Skl1.re == Skl2.re) && (Skl1.im == Skl2.im))
  {
    same = true;
  } 
    else 
  {
    same = false;
  }
  return same;
}

bool operator != (LZespolona Skl1, LZespolona Skl2){

  bool notsame;

  if((Skl1.re != Skl2.re) || (Skl1.im != Skl2.im))
  {
    notsame = true;
  }
    else
  {
    notsame = false;
  }
  return notsame;
}

