#include "Statystyka.hh"
#include <iostream>

/* Funkcja wyswietla Statystyke testu tj. liczbe wszystkich pytan,
    liczbe odpowiedzi poprawnych i blednych, oraz procentowy wynik testu. */

void WyswietlStat(Statystyka stat)
{
    double proc = (stat.l_pop)/(stat.l_pyt)*100;
    std::cout << "Liczba poprawnych odpowiedzi:" << stat.l_pop << std::endl;
    std::cout << "Liczba blednych odpowiedzi:" << stat.l_pyt - stat.l_pop << std::endl;
    std::cout << "Procent poprawnych odpowiedzi: " << proc << "%\n" << std::endl;
}



