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
void Kromozom::addGen(char data) {
    Gen* newGen = new Gen(data);
    if (!genHead) {
        genHead = genTail = newGen;
    } else {
        genTail->genNext=newGen;
        newGen->genPrew = genTail; // Yeni kromozomun prev işaretçisi eski sonu gösterir
        genTail=newGen;
        
    }
}

void  Kromozom::printKromozom() {
    Gen* temp = genHead;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->genNext;
    }
    std::cout << std::endl;
}
