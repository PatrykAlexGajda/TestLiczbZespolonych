#include <iostream>
#include "BazaTestu.hh"


int main(int argc, char **argv)
{
  if (argc < 2) {   // Sprawdzenie czy istnieje argument zawierajacy nazwe rodzaju testu
    std::cout << std::endl;
    std::cout << " Brak opcji okreslajacej rodzaj testu." << std::endl;  
    std::cout << " Dopuszczalne nazwy to:  latwy, trudny." << std::endl;
    std::cout << std::endl;
    return 1;
  }

  BazaTestu   BazaT = { nullptr, 0, 0 }; // Zainicjowanie zmiennej typu BazaTestu nie przechowujacej zadnych informacji o typie testu

  if (InicjalizujTest(&BazaT,argv[1]) == false) {   // Sprawdzenie czy zmienna BazaT zawiera wystarczajaco informacji o tescie
    std::cerr << " Inicjalizacja testu nie powiodla sie." << std::endl;
    return 1;
  }

  std::cout << std::endl;
  std::cout << " Start testu arytmetyki zespolonej: " << argv[1] << std::endl;
  std::cout << std::endl;

  WyrazenieZesp   WyrZ_PytanieTestowe; // Utworzenie zmiennej typu WyrazenieZesp do przechowywania wyrazen zespolonych

  std::cout << "INSTRUKCJA:" << std::endl;
  std::cout << "Odpowiedzi nalezy wpisywac w nawiasach, oraz wpisywac 1 i 0, np.:" << std::endl;
  std::cout << "(0+1i) - Dobrze, (i) - Zle, (13+0i) - Dobrze, (12) - Zle, (0+0i) - Dobrze." << std::endl;
  std::cout << "\n\n";

  Statystyka stat;
  ZerujStat(stat);

  // Petla pobierajaca pytania z bazy testu
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {

    std::cout << "Wyrazenie: ";
    std::cout << WyrZ_PytanieTestowe;

    LZespolona popWynik = Oblicz(WyrZ_PytanieTestowe); // Zmienna na poprawny wynik danego wyrazenia zespolonego
    LZespolona odpowiedz; // Zmienna na odpowiedz uzytkownika
    int i = 0;  
    bool blad = false;  // Zmienna dla podania zlej odpowiedzi
    bool zlyZapis = false;  // Zmienna dla blednego wprowadzenia zespolonej 

    std::cout << "Podaj odpowiedz: ";
    std::cin >> odpowiedz;

    // Petla dajaca trzy szanse na ponowne wprowadzenie poprawnego zapisu odpowiedzi
    while((std::cin.fail()) && (i < 4)){

        std::cin.clear();
        std::cin.ignore(10000, '\n');

        if(i == 0){
          std::cerr << "Bladny zapis. Trzy szanse na wprowadzenie jeszcze raz: ";
          std::cin >> odpowiedz;
          i++;
        } else if(i == 1){
          std::cerr << "Bledny zapis. Dwie szanse na wprowadzenie jeszcze raz: ";
          std::cin >> odpowiedz;
          i++;
        } else if(i == 2){
          std::cerr << "Bledny zapis. Jedna szansa na wprowadzenie jeszcze raz: ";
          std::cin >> odpowiedz;
          i++;
        } else if(i == 3){
          std::cerr << "Bledny zapis. Odpowiedz uznana za bledna." << std::endl;
          i++;
          blad = true;  // odpowiedz bledna
          zlyZapis = true;   // oraz zapis bledny
        }
    }

    if(!zlyZapis){
      std::cout << "Twoja odpowiedz: " << odpowiedz << std::endl; 
    }

    if(popWynik != odpowiedz){
      blad = true;
    }
    
    // Jesli odpowiedz poprawna
    if(popWynik == odpowiedz){
      std::cout << "Prawidlowy wynik :)" << "\n" << std::endl;
      DodajPop(stat);   // Zwiekszenie liczby poprawnych odpowiedzi
    } else if(blad){ // Jesli odpowiedz niepoprawna
      std::cout << "Blad :( Poprawna odpowiedz to: " << popWynik << "\n" << std::endl;
    }

    DodajPyt(stat);   // Zwiekszenie liczby zadanych pytan
  }

  WyswietlStat(stat);   // Wyswietlenie statystyki testu

  std::cout << std::endl;
  std::cout << "Koniec testu" << std::endl;
  std::cout << std::endl;
  }



