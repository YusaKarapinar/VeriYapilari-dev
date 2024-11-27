/**
* gen.h 
* genle alakalı değişkenlerin ve fonksiyonların bulundugu header dosyası
* 2. öğretim A grubu
* 1. ödev
* 25.11.2024
* Yuşa Karapınar yusa.karapinar@ogr.sakarya.edu.tr
*/
#ifndef GEN_H
#define GEN_H

class Gen {
public:
    char data;      // gen
    Gen* genNext;     
    Gen* genPrew;     

    Gen(char d);    // constructor
};

#endif
