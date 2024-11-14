#ifndef KROMOZOM_H
#define KROMOZOM_H

#include "Gen.h"

class Kromozom {
public:
    Gen* head;     // Kromozomun başındaki gene işaretçi
    Kromozom* prevKromozom;
    Kromozom* nextKromozom;

    Kromozom();    // Yapıcı fonksiyon
    void addGen(char data);   // Gen ekleme
    void printKromozom();     // Kromozomun tüm genlerini yazdırma
};

#endif
