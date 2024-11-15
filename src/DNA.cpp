#include "DNA.h"
#include <fstream>
#include <iostream>

DNA::~DNA() {
    Kromozom* current = kromozomHead;
    while (current) {
        Kromozom* toDelete = current;
        current = current->nextKromozom;
        delete toDelete;
    }
}

void DNA::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    
    while (std::getline(file, line)) {
        Kromozom* kromozom = new Kromozom();
        
        // Gen ekleme
        for (char gen : line) {
            if (gen != ' ') {
                kromozom->addGen(gen);
            }
        }
        
        // Yeni kromozomu DNA'ya ekle
        addKromozom(kromozom);
    }

    file.close();
}

void DNA::addKromozom(Kromozom* yeniKromozom) {
    if (kromozomHead == nullptr) {
        kromozomHead = kromozomTail = yeniKromozom; // Liste boşsa, yeni kromozom başa ve sona eklenir
    } else {
        kromozomTail->nextKromozom = yeniKromozom; // Son kromozomun next işaretçisi yeni kromozomu gösterir
        yeniKromozom->prevKromozom = kromozomTail; // Yeni kromozomun prev işaretçisi eski sonu gösterir
        kromozomTail = yeniKromozom; // Yeni kromozom, yeni son kromozom olur
    }
}

void DNA::displayDNA() {
    Kromozom* current = kromozomHead;
    int index = 1;
    
    while (current != nullptr) {
        std::cout << "Kromozom " << index++ << ": ";
        current->printKromozom(); // Kromozomun genlerini yazdır
        current = current->nextKromozom;
    }
}

void DNA::caprazlama(int idx1,int idx2){
    
    
    
    return;
}
