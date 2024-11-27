/**
* dna.cpp 
* genel sistem değişken ve fonksiyonların bulundugu header dosyası
* 2. öğretim A grubu
* 1. ödev
* 25.11.2024
* Yuşa Karapınar yusa.karapinar@ogr.sakarya.edu.tr
*/
#ifndef DNA_H
#define DNA_H

#include <string>
#include "Kromozom.h"

class DNA {
public:
    Kromozom* kromozomHead;   // head
    Kromozom* kromozomTail;   // tail
    
    DNA() : kromozomHead(nullptr), kromozomTail(nullptr) {} 
    ~DNA();  

    void loadFromFile(const std::string& filename);   // dosya okuma
    void displayDNA();       // herşeyi yazdır
    void crossover(int idx1, int idx2); // çaprazlama
    void mutation(int kromozomIndex, int genIndex); // mutation
    void addKromozom(Kromozom* yeniKromozom); // kromozom ekleme fonksiyonu
    void automaticOperations(const std::string &filename);//otomatik işlemler
    void printSmallestGenes();// ekrana yazdır
};

#endif
