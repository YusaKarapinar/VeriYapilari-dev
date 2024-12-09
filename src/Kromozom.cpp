#include "Kromozom.h"
#include <iostream>

Kromozom::Kromozom() : GenHead(nullptr) {}

void Kromozom::addGen(char data,Kromozom* kromozom) {
    Gen* newGen = new Gen(data);
    
    if (!GenHead) {
        GenHead = GenTail  = newGen;

    } else {
        GenTail->GenNext = newGen;
        GenTail=newGen;
        
    }
}


void Kromozom::printKromozom() {
    Gen* temp = GenHead;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->GenNext;
    }
    std::cout << std::endl;
}
