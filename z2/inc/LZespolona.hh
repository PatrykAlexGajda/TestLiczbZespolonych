#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include "Statystyka.hh"
#include <iostream>

/*!  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze. */

/*! Modeluje pojecie liczby zespolonej */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};


/* Naglowki funkcji dzialajacych na liczbach zespolonych
lub liczacych je na podstawie zawartosci struktury LZespolona */

LZespolona Utworz(double x, double y);
LZespolona ZespPrzezRzecz (LZespolona Skl, double r);
LZespolona Sprzezenie (LZespolona Skl);
double Modul(LZespolona Skl);

/* Naglowki przeciazen operatorow ktore pozwalaja im operowac na strukturze
liczb zespolonych */

std::ostream &operator<<(std::ostream &str, const LZespolona &zesp);
std::istream &operator>>(std::istream &str, LZespolona &zesp);

/* Naglowki przeciazen operatorow ktore pozwalaja im obliczac wyniki
  wyrazen zespolonych. */

LZespolona operator + (LZespolona Skl1, LZespolona Skl2);
LZespolona operator - (LZespolona Skl1, LZespolona Skl2);
LZespolona operator * (LZespolona Skl1, LZespolona Skl2);
LZespolona operator / (LZespolona Skl1, LZespolona Skl2);

/* Naglowki przeciazen operatorow porownujacych liczby zespolone. */

bool operator == (LZespolona Skl1, LZespolona Skl2);
bool operator != (LZespolona Skl1, LZespolona Skl2);


#endif
