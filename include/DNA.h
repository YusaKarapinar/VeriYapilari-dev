#ifndef DNA_H
#define DNA_H

#include <string>
#include "Kromozom.h"

class DNA {
public:
    Kromozom* KromozomHead;   // DNA'daki ilk kromozom
    Kromozom* KromozomTail;   // DNA'daki son kromozom
    
    DNA() : KromozomHead(nullptr), KromozomTail(nullptr) {} // Başlatıcı fonksiyon

    void loadFromFile(const std::string& filename);   // Dosyadan DNA yükleme
    void displayDNA();       // DNA'yı ekrana yazdırma
    void caprazlama(int idx1, int idx2); // Çaprazlama işlemi
    void mutasyon(int kromozomIndex, int genIndex); // Mutasyon işlemi
    void addKromozom(Kromozom* yeniKromozom); // Kromozom ekleme fonksiyonu
};


#endif
