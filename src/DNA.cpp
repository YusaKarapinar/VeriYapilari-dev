#include "DNA.h"
#include <fstream>
#include <iostream>
#include <sstream>

DNA::~DNA()
{
    Kromozom *current = kromozomHead;
    while (current)
    {
        Kromozom *toDelete = current;
        current = current->nextKromozom;
        delete toDelete;
    }
}

void Kromozom::printToFile(std::ofstream &file)
{
    Gen *temp = genHead;
    while (temp)
    {
        file << temp->data << " ";
        temp = temp->genNext;
    }
}

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
                kromozom->addGen(gen);
            }
        }

        // Yeni kromozomu DNA'ya ekle
        addKromozom(kromozom);
    }

    file.close();
}

void DNA::addKromozom(Kromozom *yeniKromozom)
{
    if (kromozomHead == nullptr)
    {
        kromozomHead = kromozomTail = yeniKromozom; // Liste boşsa, yeni kromozom başa ve sona eklenir
    }
    else
    {
        kromozomTail->nextKromozom = yeniKromozom; // Son kromozomun next işaretçisi yeni kromozomu gösterir
        yeniKromozom->prevKromozom = kromozomTail; // Yeni kromozomun prev işaretçisi eski sonu gösterir
        kromozomTail = yeniKromozom;               // Yeni kromozom, yeni son kromozom olur
    }
}

void DNA::displayDNA()
{
    Kromozom *current = kromozomHead;
    int index = 0;

    while (current != nullptr)
    {
        std::cout << "Kromozom " << index++ << ": ";
        current->printKromozom(); // Kromozomun genlerini yazdır
        current = current->nextKromozom;
    }
}
void DNA::mutasyon(int kromozomIndex, int genIndex)
{
    Kromozom *chrom = kromozomHead;
    int count = 0;

    // Kromozomu bul
    while (chrom && count < kromozomIndex)
    {
        chrom = chrom->nextKromozom;
        count++;
    }

    if (!chrom)
    {
        std::cout << "Geçersiz kromozom indeksi!" << std::endl;
        return;
    }

    // Geni bul
    Gen *gen = chrom->genHead;
    count = 0;
    while (gen && count < genIndex)
    {
        gen = gen->genNext;
        count++;
    }

    if (!gen)
    {
        std::cout << "Geçersiz gen indeksi!" << std::endl;
        return;
    }

    // Mutasyonu gerçekleştir
    gen->data = 'X';

    // Dosyada değişikliği yap
    std::ifstream fileIn("dna.txt");
    if (!fileIn.is_open())
    {
        std::cerr << "Dosya açılamadı!" << std::endl;
        return;
    }

    std::ofstream fileOut("temp.txt");
    if (!fileOut.is_open())
    {
        std::cerr << "Geçici dosya oluşturulamadı!" << std::endl;
        fileIn.close();
        return;
    }

    // Satır bazında dosyayı okuyup yazma
    std::string line;
    int currentKromozom = 0;
    while (std::getline(fileIn, line))
    {
        if (currentKromozom == kromozomIndex)
        {
            std::istringstream lineStream(line);
            std::ostringstream newLineStream;
            std::string genData;
            int currentGen = 0;

            while (lineStream >> genData)
            {
                if (currentGen == genIndex)
                    newLineStream << "X "; // Mutasyon
                else
                    newLineStream << genData << " ";
                currentGen++;
            }
            fileOut << newLineStream.str() << "\n";
        }
        else
        {
            fileOut << line << "\n"; // Diğer kromozomlar aynı kalır
        }
        currentKromozom++;
    }

    fileIn.close();
    fileOut.close();

    // Geçici dosyayı orijinal dosyayla değiştir
    std::remove("dna.txt");
    std::rename("temp.txt", "dna.txt");

    std::cout << "Mutasyon tamamlandı ve dosyaya yansıtıldı!" << std::endl;
}


void DNA::caprazlama(int idx1, int idx2) {
    // Kromozomları bul
    Kromozom *chrom1 = kromozomHead;
    Kromozom *chrom2 = kromozomHead;
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
    Gen *temp = chrom1->genHead;
    while (temp) {
        size1++;
        temp = temp->genNext;
    }

    temp = chrom2->genHead;
    while (temp) {
        size2++;
        temp = temp->genNext;
    }

    // Orta noktaları belirle
    float midpoint1 = size1 / 2.0;
    float midpoint2 = size2 / 2.0;
    std::cout<<midpoint1<<" "<<midpoint2<<std::endl;


    // Eğer gen sayısı tek ise orta gen çaprazlamaya dahil edilmez

    // Yeni kromozomları oluştur
    Kromozom *newChrom1 = new Kromozom();
    Kromozom *newChrom2 = new Kromozom();

    // Yeni Kromozom 1: Chrom1'in sol tarafı + Chrom2'nin sağ tarafı
    temp = chrom1->genHead;
    for (int i = 1; i < midpoint1; i++) {
        printf("i=%d,midpoint1=%f,Gen=%c\n",i,midpoint1,temp->data);
        newChrom1->addGen(temp->data);
        temp = temp->genNext;
    }
    temp = chrom2->genHead;
    for (int i = 0; i < midpoint2; i++) {
                

        temp = temp->genNext; // Orta noktayı atla
    }
    while (temp) {
printf("i=-,midpoint1=%f,Gen=%c\n",midpoint2,temp->data);
        newChrom1->addGen(temp->data);
        temp = temp->genNext;
    }

    // Yeni Kromozom 2: Chrom2'nin sol tarafı + Chrom1'in sağ tarafı
    temp = chrom2->genHead;
    for (int i = 1; i < midpoint2; i++) {
        printf("i=%d,midpoint1=%f,Gen=%c\n",i,midpoint2,temp->data);

        newChrom2->addGen(temp->data);
        temp = temp->genNext;
    }
    temp = chrom1->genHead;
    for (int i = 0; i < midpoint1; i++) {
        temp = temp->genNext; // Orta noktayı atla
    }
    while (temp) {
        printf("i=-,midpoint1=%f,Gen=%c\n",midpoint1,temp->data);

        newChrom2->addGen(temp->data);
        temp = temp->genNext;
    }

    // Yeni kromozomları DNA'ya ekle
    addKromozom(newChrom1);
    addKromozom(newChrom2);

    // Yeni kromozomları dosyaya ekle
    std::ofstream file("dna.txt", std::ios::app);
    if (file.is_open()) {
        file << std::endl;
        newChrom1->printToFile(file);
        file << std::endl;
        newChrom2->printToFile(file);
        file.close();
    } else {
        std::cerr << "Dosya açılamadı!" << std::endl;
    }

    std::cout << "Çaprazlama tamamlandı ve dosyaya eklendi!" << std::endl;
}


void DNA::automaticOperations(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Islemler.txt dosyası açılamadı!" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        char operation;
        int idx1, idx2;

        iss >> operation;

        if (operation == 'C') { // Çaprazlama
            iss >> idx1 >> idx2;
            caprazlama(idx1, idx2);
        } else if (operation == 'M') { // Mutasyon
            int genIndex;
            iss >> idx1 >> genIndex;
            mutasyon(idx1, genIndex);
        } else {
            std::cerr << "Geçersiz işlem: " << operation << std::endl;
        }
    }

    file.close();
    std::cout << "Otomatik işlemler tamamlandı!" << std::endl;
}



void DNA::printSmallestGenes() {
    Kromozom *current = kromozomHead;
    while (current) {
        Gen *gen = current->genHead;
        Gen *smallest = gen; // İlk geni varsayılan olarak al
        while (gen) {
            if (gen->data < smallest->data) {
                smallest = gen; // Daha küçük bir gen bulundu
            }
            gen = gen->genNext;
        }
        // Eğer küçük gen bulunamadıysa ilk geni yazdır
        std::cout << (smallest ? smallest->data : current->genHead->data) << " ";
        current = current->nextKromozom;
    }
    std::cout << std::endl;
}
