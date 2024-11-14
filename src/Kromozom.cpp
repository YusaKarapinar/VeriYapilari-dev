#include "Kromozom.h"
#include <iostream>

Kromozom::Kromozom() : GenHead(nullptr) {}

void Kromozom::addGen(char data) {
    Gen* newGen = new Gen(data);
    if (!GenHead) {
        GenHead = newGen;
    } else {
        Gen* temp = GenHead;
        while (temp->GenNext) temp = temp->GenNext;
        temp->GenNext = newGen;
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
