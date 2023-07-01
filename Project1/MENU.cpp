#include "MENU.h"
//Podzia³ kodu na wiele plików
//Zapis odczyt danych z pliku
string MENU::read()
{
	string bufor;
	std::cout << "-----ODCZYT INSTRUKCJI Z PLIKU-----" << std::endl;
    std::ifstream plik("instrukcja.txt");
    std::string tekst, linia;

    if (plik.is_open()) {
        plik.seekg(0, std::ios::end); 
        std::streampos rozmiar = plik.tellg(); 
        plik.seekg(0, std::ios::beg); 
        tekst.resize(rozmiar); 
        plik.read(&tekst[0], rozmiar); 
        plik.close();
        // Wyœwietlanie wczytanego tekstu
        std::cout << "\n" << tekst << std::endl;
    }
    else {
        std::cout << "Nie mo¿na otworzyæ pliku." << std::endl;
    }
	return bufor;
}
void MENU::sortAndDisplayTop10Results(const std::string& filename)
{
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cout << "Blad podczas otwierania pliku." << std::endl;
        return;
    }
    std::vector<float> numbers;
    float number;
    while (inputFile >> number) {
        numbers.push_back(number);
    }
    inputFile.close();
    // Sortowanie liczb w porz¹dku malej¹cym
    std::sort(numbers.rbegin(), numbers.rend());
    std::cout << "10 najlepszych wynikow:" << std::endl;
    for (int i = 0; i < 10 && i < numbers.size(); i++) {
        std::cout << numbers[i] << std::endl;
    }
}
