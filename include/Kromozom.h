#ifndef KROMOZOM_H
#define KROMOZOM_H

#include "Gen.h"

class Kromozom {
public:
    Gen* GenHead;    // Kromozomun başındaki gene işaretçi
    Gen* GenTail; 
    Kromozom* prevKromozom;
    Kromozom* nextKromozom;

    Kromozom();    // Yapıcı fonksiyon
    void addGen(char data,Kromozom* kromozom);   // Gen ekleme
    void printKromozom();     // Kromozomun tüm genlerini yazdırma
    
};

#endif
