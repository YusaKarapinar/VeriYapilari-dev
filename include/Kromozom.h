#ifndef KROMOZOM_H
#define KROMOZOM_H

#include "Gen.h"
#include <fstream>


class Kromozom {
public:
    Gen* genHead;     // Kromozomun başındaki gene işaretçi
    Gen* genTail;     // Kromozomun başındaki gene işaretçi
    Kromozom* prevKromozom;
    Kromozom* nextKromozom;

    Kromozom();    // Yapıcı fonksiyon
    ~Kromozom();  // Destructor eklendi
    void addGen(char data) ;   // Gen ekleme
    void printKromozom();     // Kromozomun tüm genlerini yazdırma
     void printToFile(std::ofstream& file);
};

#endif
