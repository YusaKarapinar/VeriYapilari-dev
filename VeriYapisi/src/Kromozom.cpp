#include "Kromozom.h"
#include <iostream>

Kromozom::Kromozom() : head(nullptr) {}

void Kromozom::addGen(char data) {
    Gen* newGen = new Gen(data);
    if (!head) {
        head = newGen;
    } else {
        Gen* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newGen;
    }
}

void Kromozom::printKromozom() {
    Gen* temp = head;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
