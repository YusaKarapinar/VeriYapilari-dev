/**
* Kromozom.h 
* genle alakalı değişkenlerin ve fonksiyonların bulundugu header dosyası
* 2. öğretim A grubu
* 1. ödev
* 25.11.2024
* Yuşa Karapınar yusa.karapinar@ogr.sakarya.edu.tr
*/


#ifndef KROMOZOM_H
#define KROMOZOM_H

#include "Gen.h"
#include <fstream>


class Kromozom {
public:
    Gen* genHead;     // Head pointer
    Gen* genTail;     // tail pointer
    Kromozom* prevKromozom;
    Kromozom* nextKromozom;

    Kromozom();    // constructor function
    ~Kromozom();  // Destructor 
    void addGen(char data) ;   // gen ekleme
    void printKromozom();     // kromozomun tüm genlerini yazdırma
    void printToFile(std::ofstream& file);
};

#endif
