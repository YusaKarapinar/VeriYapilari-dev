#include "DNA.h"
#include <iostream>
#include <chrono>

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    DNA dna;
    dna.loadFromFile("Dna.txt"); // Dna.txt dosyasından DNA yükle
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start); // süre hesabı

    std::cout << duration.count() << "ms" << std::endl;

    int secim, idx1, idx2, genIndex,kromozomIndex;
    do {
        std::cout << "1- Çaprazlama\n2- Mutasyon\n3- Ekrana Yaz\n4- Otomatik İşlemler\n5- Çıkış\n";
        std::cout << "Seçiminiz: ";
        std::cin >> secim;

        switch (secim) {
        case 1:
            
            std::cout << "Çaprazlamak için iki kromozom numarası girin: ";
            std::cin >> idx1 >> idx2;
            dna.caprazlama(idx1, idx2);
            break;
        case 2:
            std::cout << "Mutasyon için kromozom ve gen numarası girin: ";
            std::cin >> kromozomIndex >> genIndex;
            dna.mutasyon(kromozomIndex, genIndex);
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
        default:
            std::cout << "Geçersiz seçim!\n";
            break;
        }
    } while (secim != 5);
    return 0;
}
