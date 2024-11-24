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
    int index = 0;
    
    while (current != nullptr) {
        std::cout << "Kromozom " << index++ << ": ";
        current->printKromozom(); // Kromozomun genlerini yazdır
        current = current->nextKromozom;
    }
}


void DNA::mutasyon(int kromozomIndex, int genIndex) {
    Kromozom* chrom = kromozomHead;
    int count = 0;

    // Find chromosome by index
    while (chrom && count < kromozomIndex) {
        chrom = chrom->nextKromozom;
        count++;
    }

    if (!chrom) {
        std::cout << "Geçersiz kromozom indeksi!" << std::endl;
        return;
    }

    // Find gen by index
    Gen* gen = chrom->genHead;
    count = 0;
    while (gen && count < genIndex) {
        gen = gen->genNext;
        count++;
    }

    if (!gen) {
        std::cout << "Geçersiz gen indeksi!" << std::endl;
        return;
    }

    // Mutate the gen
    gen->data = 'X';
    std::cout << "Mutasyon tamamlandı!" << std::endl;
}

void DNA::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Dosya açılamadı: " << filename << std::endl;
        return;
    }

    Kromozom* current = kromozomHead;
    while (current) {
        Gen* gen = current->genHead;
        while (gen) {
            file << gen->data;
            if (gen->genNext) {
                file << " "; // Genler arasında boşluk bırak
            }
            gen = gen->genNext;
        }
        file << "\n"; // Her kromozom için yeni bir satır
        current = current->nextKromozom;
    }

    file.close();
    std::cout << "DNA başarıyla " << filename << " dosyasına kaydedildi." << std::endl;
}


void DNA::caprazlama(int idx1, int idx2) {
    // Kromozomları bul
    Kromozom* chrom1 = kromozomHead;
    Kromozom* chrom2 = kromozomHead;
    int count = 0;

    while (chrom1 && count < idx1) {
        chrom1 = chrom1->nextKromozom;
        count++;
    }

    count = 0;
    while (chrom2 && count < idx2) {
        chrom2 = chrom2->nextKromozom;
        count++;
    }

    if (!chrom1 || !chrom2) {
        std::cout << "Geçersiz kromozom indeksleri!" << std::endl;
        return;
    }

    // Kromozomların gen sayılarını hesapla
    int size1 = 0, size2 = 0;
    Gen* temp = chrom1->genHead;
    while (temp) {
        size1++;
        temp = temp->genNext;
    }

    temp = chrom2->genHead;
    while (temp) {
        size2++;
        temp = temp->genNext;
    }

    int midpoint1 = size1 / 2;
    int midpoint2 = size2 / 2;

    // Yeni kromozomları oluştur
    Kromozom* newChrom1 = new Kromozom();
    Kromozom* newChrom2 = new Kromozom();

    // İlk kromozomun ilk yarısı ve ikinci kromozomun ikinci yarısını birleştir
    temp = chrom1->genHead;
    for (int i = 0; i < midpoint1; i++) {
        newChrom1->addGen(temp->data);
        temp = temp->genNext;
    }
    temp = chrom2->genHead;
    for (int i = 0; i < midpoint2; i++) {
        temp = temp->genNext; // Orta noktaya kadar ilerle
    }
    while (temp) {
        newChrom1->addGen(temp->data);
        temp = temp->genNext;
    }

    // İkinci kromozomun ilk yarısı ve birinci kromozomun ikinci yarısını birleştir
    temp = chrom2->genHead;
    for (int i = 0; i < midpoint2; i++) {
        newChrom2->addGen(temp->data);
        temp = temp->genNext;
    }
    temp = chrom1->genHead;
    for (int i = 0; i < midpoint1; i++) {
        temp = temp->genNext; // Orta noktaya kadar ilerle
    }
    while (temp) {
        newChrom2->addGen(temp->data);
        temp = temp->genNext;
    }

    // Yeni kromozomları DNA'ya ekle
    addKromozom(newChrom1);
    addKromozom(newChrom2);

    std::cout << "Çaprazlama tamamlandı!" << std::endl;
}
