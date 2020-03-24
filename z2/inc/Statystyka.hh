/* Modeluje pojecie Statystyka informujac o ilosci przeprowadzonych pytan
    oraz udzielonych poprawnych odpowiedzi  */ 

struct Statystyka {

    double l_pyt;
    double l_pop;
};

/* Naglowek funkcji wyswietlajacej Statystyke testu. */

void ZerujStat(Statystyka &stat);
void DodajPyt(Statystyka &stat);
void DodajPop(Statystyka &stat);
void WyswietlStat(Statystyka &stat);
