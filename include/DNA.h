#ifndef DNA_H
#define DNA_H

#include <string>
#include "Kromozom.h"

class DNA {
public:
    Kromozom* kromozomHead;   // DNA'daki ilk kromozom
    Kromozom* kromozomTail;   // DNA'daki son kromozom
    
    DNA() : kromozomHead(nullptr), kromozomTail(nullptr) {} // Başlatıcı fonksiyon
    ~DNA();  // Destructor eklendi

    void loadFromFile(const std::string& filename);   // Dosyadan DNA yükleme
    void displayDNA();       // DNA'yı ekrana yazdırma
    void caprazlama(int idx1, int idx2); // Çaprazlama işlemi
    void mutasyon(int kromozomIndex, int genIndex); // Mutasyon işlemi
    void addKromozom(Kromozom* yeniKromozom); // Kromozom ekleme fonksiyonu
    void automaticOperations(const std::string &filename);
    void printSmallestGenes();
};

#endif
