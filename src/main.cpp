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

    int secim, idx1, idx2, genIndex;
    do
    {
        std::cout << "1- Çaprazlama\n2- Mutasyon\n3- Ekrana Yaz\n4- Çıkış\n";
        std::cout << "Seçiminiz: ";
        std::cin >> secim;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Satır sonunu temizle

        switch (secim)
        {
        case 1:
            std::cout << "Çaprazlamak için iki kromozom numarası girin: ";
            std::cin >> idx1 >> idx2;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            dna.caprazlama(idx1, idx2);
            dna.saveToFile("Dna.txt"); // Değişiklikleri dosyaya kaydet
            dna.saveToFile("Dna.txt"); // Değişiklikleri dosyaya kaydet
            break;
        case 2:
            std::cout << "Mutasyon için kromozom ve gen numarası girin: ";
            std::cin >> idx1 >> genIndex;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            dna.mutasyon(idx1, genIndex);
            dna.saveToFile("Dna.txt"); // Değişiklikleri dosyaya kaydet
            
            break;
        case 3:
            dna.displayDNA();
            break;
        case 4:
            dna.saveToFile("Dna.txt"); // Programdan çıkmadan önce kaydet
            std::cout << "Çıkış yapılıyor...\n";
            break;
        default:
            std::cout << "Geçersiz seçim!\n";
            break;
        }
    } while (secim != 4);

    return 0;
}
