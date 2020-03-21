#include <iostream>
#include "BazaTestu.hh"


int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cout << std::endl;
    std::cout << " Brak opcji okreslajacej rodzaj testu." << std::endl;
    std::cout << " Dopuszczalne nazwy to:  latwy, trudny." << std::endl;
    std::cout << std::endl;
    return 1;
  }

  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    std::cerr << " Inicjalizacja testu nie powiodla sie." << std::endl;
    return 1;
  }

  std::cout << std::endl;
  std::cout << " Start testu arytmetyki zespolonej: " << argv[1] << std::endl;
  std::cout << std::endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  int liczbaPyt = 0;
  int popOdp = 0;

  
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {

    std::cout << "Wyrazenie: ";
    Wyswietl(WyrZ_PytanieTestowe);
    LZespolona popWynik = Oblicz(WyrZ_PytanieTestowe);

    char odp[3];
    double re, im;

    LZespolona odpowiedz;
    int i = 0;
    
    while((popWynik != odpowiedz) && (i != 3)){

    std::cout << "Podaj odpowiedz (w nawiasach): ";
    std::cin >> odp[0] >> re >> im >> odp[1] >> odp[2];

    odpowiedz = Utworz(re, im);

    if(popWynik == odpowiedz){
      std::cout << "Poprawna odpowiedz." << std::endl;
      popOdp++;
    } else if((odpowiedz != popWynik) && (i == 0)) {
      std::cout << "Niepoprawna odpowiedz, pozostaly 2 szanse." << std::endl;
      i++;
    } else if((odpowiedz != popWynik) && (i == 1)) {
      std::cout << "Niepoprawna odpowiedz, pozostala 1 szansa." << std::endl;
      i++;
    } else {
      std::cout << "Niepoprawna odpowiedz, pozostalo 0 szans." << std::endl;
      std::cout << "Poprawny wynik: ";
      WyswietlZesp(popWynik);
      i++;
    }
    }    
    liczbaPyt++;
  }

  Statystyka stat;
  stat.l_pyt = liczbaPyt;
  stat.l_pop = popOdp;

  WyswietlStat(stat);

  std::cout << std::endl;
  std::cout << "Koniec testu" << std::endl;
  std::cout << std::endl;
  }
