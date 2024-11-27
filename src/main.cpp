/**
* main.cpp 
* kullanıcıdan girdi alma ve gerekli fonksiyonlara yönlendirme
* 2. öğretim A grubu
* 1. ödev
* 25.11.2024
* Yuşa Karapınar yusa.karapinar@ogr.sakarya.edu.tr
*/



#include "DNA.h"
#include <iostream>
#include <chrono>


int main()
{
    DNA dna;
    dna.loadFromFile("Dna.txt");
    dna.displayDNA();
    int secim, idx1, idx2, genIndex, kromozomIndex;
    do
    {
        std::cout << "1- Çaprazlama\n2- mutation\n3- Ekrana Yaz\n4- Otomatik İşlemler\n5- Çıkış\n";
        std::cout << "Seçiminiz: ";
        std::cin >> secim;

        switch (secim)
        {
        case 1:
            std::cout << "Çaprazlamak için iki kromozom numarası girin: ";
            std::cin >> idx1 >> idx2;
            dna.crossover(idx1, idx2);
            break;
        case 2:
            std::cout << "mutation için kromozom ve gen numarası girin: ";
            std::cin >> kromozomIndex >> genIndex;
            dna.mutation(kromozomIndex, genIndex);
            break;
        case 3:
            dna.printSmallestGenes();
            break;
        case 4:
            dna.automaticOperations("Islemler.txt");
            break;
        case 5:
            std::cout << "Çıkış yapılıyor...\n";
            break;
        case 6:
            dna.displayDNA();
            break;
        default:
            std::cout << "Geçersiz seçim!\n";
            break;
        }
    } while (secim != 6);
    return 0;
}
