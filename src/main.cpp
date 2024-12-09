#include "DNA.h"
#include <chrono>
#include <iostream>

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    DNA dna;
    dna.loadFromFile("Dna.txt"); // Dna.txt dosyasından DNA yükle
    //dna.displayDNA();            // Kromozomları ekrana yazdır
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start); //süre hesabı

    std::cout << duration.count() <<"ms----toplam"<<std::endl;

    int secim, idx1, idx2, genIndex;
    do {
        std::cout << "1- Çaprazlama\n2- Mutasyon\n3- Ekrana Yaz\n4- Çıkış\n";
        std::cout << "Seçiminiz: ";
        std::cin >> secim;

        switch (secim) {
            case 1:
                std::cout << "Çaprazlamak için iki kromozom numarası girin: ";
                std::cin >> idx1 >> idx2;
                //dna.caprazlama(idx1, idx2);
                break;
            case 2:
                std::cout << "Mutasyon için kromozom ve gen numarası girin: ";
                std::cin >> idx1 >> genIndex;
                //dna.mutasyon(idx1, genIndex);
                break;
            case 3:
                dna.displayDNA();
                break;
            case 4:
                std::cout << "Çıkış yapılıyor...\n";
                break;
            default:
                std::cout << "Geçersiz seçim!\n";
                break;
        }
    } while (secim != 4);


    return 0;
}
