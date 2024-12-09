#include "DNA.h"
#include <fstream>
#include <iostream>

void DNA::loadFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line))
    {
        Kromozom *kromozom = new Kromozom();

        // Gen ekleme
        for (char gen : line)
        {
            if (gen != ' ')
            {
                kromozom->addGen(gen,kromozom);
            }
        }

        // Yeni kromozomu DNA'ya ekle
        addKromozom(kromozom);
    }

    file.close();
}

void DNA::addKromozom(Kromozom *yeniKromozom)
{
    if (KromozomHead == nullptr)
    {
        KromozomHead = KromozomTail = yeniKromozom; // Liste boşsa, yeni kromozom başa ve sona eklenir
    }
    else
    {
        KromozomTail->nextKromozom = yeniKromozom; // Son kromozomun next işaretçisi yeni kromozomu gösterir
        KromozomTail = yeniKromozom;               // Yeni kromozom, yeni son kromozom olur
    }
}

void DNA::displayDNA()
{
    Kromozom *current = KromozomHead;
    int index = 1;

    while (current != nullptr)
    {
        std::cout << "Kromozom " << index++ << ": ";
        current->printKromozom(); // Kromozomun genlerini yazdır
        current = current->nextKromozom;
    }
}

void DNA::caprazlama(int idx1, int idx2)
{

    return;
}
