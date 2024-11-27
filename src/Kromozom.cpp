/**
* Kromozom.cpp 
* kromozom sınıfının constructor deconstructor gen ekleme ve tüm genleri yazdırma fonksiyonunu bulunduran dosya
* 2. öğretim A grubu
* 1. ödev
* 25.11.2024
* Yuşa Karapınar yusa.karapinar@ogr.sakarya.edu.tr
*/


#include "Kromozom.h"
#include <iostream>

Kromozom::Kromozom() : genHead(nullptr), genTail(nullptr) {}

Kromozom::~Kromozom() {
    Gen* current = genHead;
    while (current) {
        Gen* toDelete = current;
        current = current->genNext;
        delete toDelete;
    }
}

//genlerin sonuna yeni gen ekle
void Kromozom::addGen(char data) {
    Gen* newGen = new Gen(data);
    if (!genHead) {
        genHead = genTail = newGen;
    } else {
        genTail->genNext = newGen;
        newGen->genPrew = genTail;
        genTail = newGen;
    }
}

//tüm genleri yazdır
void  Kromozom::printKromozom() {
    Gen* temp = genHead;
    while (temp) {
        std::cout << temp->data <<" ";
        temp = temp->genNext;
    }
    std::cout << std::endl;
}

