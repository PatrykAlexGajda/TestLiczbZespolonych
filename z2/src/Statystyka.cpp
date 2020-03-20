#include "Statystyka.hh"
#include <iostream>

void WyswietlStat(Statystyka stat)
{
    double proc = (stat.l_pop)/(stat.l_pyt)*100;
    std::cout << "Liczba odpowiedzi poprawnych na wszystkie: " << stat.l_pop << "/" << stat.l_pyt << std::endl;
}



