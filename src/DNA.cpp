/**
* dna.cpp 
* istenen tüm genel sistem kodlarının bulundugu dosya 
* 2. öğretim A grubu
* 1. ödev
* 25.11.2024
* Yuşa Karapınar yusa.karapinar@ogr.sakarya.edu.tr
*/
#include "DNA.h"
#include <fstream>
#include <iostream>
#include <sstream>
//destructor fonksiyonu
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

//dosyaya yazdırma fonksiyonu
void Kromozom::printToFile(std::ofstream &file)
{
    Gen *temp = genHead;
    while (temp)
    {
        file << temp->data << " ";
        temp = temp->genNext;
    }
}
//dosyadan okuma fonksiyonu
void DNA::loadFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line))
    {
        Kromozom *kromozom = new Kromozom();

        // gen ekleme kısmı
        for (char gen : line)
        {
            if (gen != ' ' && gen !='\n')
            {
                kromozom->addGen(gen);
            }
        }

        // kromozomu dna ya ekliyor
        addKromozom(kromozom);
    }

    file.close();
}

//dna ya kromozom ekleme fonksiyonu
void DNA::addKromozom(Kromozom *newCromosom)
{
    if (kromozomHead == nullptr)
    {
        kromozomHead = kromozomTail = newCromosom; // liste boşsa ilk ve son kromozom olur
    }
    else
    {
        kromozomTail->nextKromozom = newCromosom;
        newCromosom->prevKromozom = kromozomTail;
        kromozomTail = newCromosom; // son kromozom olur
    }
    
}
//veri parsellememiz doğru mu diye tüm linked listlerde gezerek yazdırıyoruz
void DNA::displayDNA() {
    Kromozom* current = kromozomHead;
    int index = 0;
    while (current != nullptr) {
        std::cout << " Kromozom " << index++ << ": ";
        
        current->printKromozom(); // kromozomdaki herşeyi yazdırıyor
        current = current->nextKromozom;
    }
}




void DNA::mutation(int kromozomIndex, int genIndex)
{
    Kromozom *chrom = kromozomHead;
    int count = 0;

    // cromozomubul
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

    // geni bul
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

    // mutationu yap
    gen->data = 'X';

    // dosyayı değiştir
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

    // satır bazında bak
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
                    newLineStream << "X "; // mutation
                else
                    newLineStream << genData << " ";
                currentGen++;
            }
            fileOut << newLineStream.str() << "\n";
        }
        else
        {
            fileOut << line << "\n"; // diğerlerine elleme
        }
        currentKromozom++;
    }

    fileIn.close();
    fileOut.close();

    // dosya işlemi
    std::remove("dna.txt");
    std::rename("temp.txt", "dna.txt");

    std::cout << "mutation tamamlandı ve dosyaya yansıtıldı!" << std::endl;
}

void DNA::crossover(int idx1, int idx2)
{
    // indexlerine göre kromozomları bul
    Kromozom *chrom1 = kromozomHead;
    Kromozom *chrom2 = kromozomHead;
    int count = 0;

    while (chrom1 && count < idx1)
    {
        chrom1 = chrom1->nextKromozom;
        count++;
    }

    count = 0;
    while (chrom2 && count < idx2)
    {
        chrom2 = chrom2->nextKromozom;
        count++;
    }

    if (!chrom1 || !chrom2)
    {
        std::cout << "Geçersiz kromozom indeksleri!" << std::endl;
        return;
    }

    // genleri hesapla
    int size1 = 0, size2 = 0;
    Gen *temp = chrom1->genHead;
    while (temp)
    {
        size1++;
        temp = temp->genNext;
    }

    temp = chrom2->genHead;
    while (temp)
    {
        size2++;
        temp = temp->genNext;
    }

    // orta noktaları bul
    int mid1 = size1 / 2;
    int mid2 = size2 / 2;

    // yeni kromozom nesnelerini yap
    Kromozom *newChrom1 = new Kromozom();
    Kromozom *newChrom2 = new Kromozom();

    // kromozom=kromozom1 sol + kromozom 2 sağ 
    temp = chrom1->genHead;
    int index = 0;
    while (temp && index < mid1)
    {
        newChrom1->addGen(temp->data); // sol tarafı ekle
        temp = temp->genNext;
        index++;
    }

    temp = chrom2->genHead;
    index = 0;

    //orta varsa çıkar
    while (index < mid2)
    {
        temp = temp->genNext;
        index++;
    }
     if (size2 % 2 != 0)
    {
        temp =temp->genNext;
    }

    while (temp && index >= mid2)
    {
        newChrom1->addGen(temp->data); // sağ tarafı ekle
        temp = temp->genNext;
        index++;
    }

    //  kromozom=kromozom2 sol + kromozom 1 sağ 
    temp = chrom2->genHead;
    index = 0;
    while (temp && index < mid2)
    {
        newChrom2->addGen(temp->data); // sol taraf
        temp = temp->genNext;
        index++;
    }

    temp = chrom1->genHead;
    index = 0;
    while (index < mid1)
    {
        temp = temp->genNext;
        index++;
    }
     if (size1 % 2 != 0)
    {
        temp =temp->genNext;
    }

    while (temp && index >= mid1)
    {
        newChrom2->addGen(temp->data); // sağ taraf
        temp = temp->genNext;
        index++;
    }

    // dna ya ekle
    addKromozom(newChrom1);
    addKromozom(newChrom2);

    // dosyaya ekle
    std::ofstream file("dna.txt", std::ios::app);
    if (file.is_open())
    {
        file << std::endl;
        newChrom1->printToFile(file);
        file << std::endl;
        newChrom2->printToFile(file);
        file.close();
    }
    else
    {
        std::cerr << "Dosya açılamadı!" << std::endl;
    }

    std::cout << "Çaprazlama tamamlandı ve dosyaya eklendi!" << std::endl;
}

void DNA::automaticOperations(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Islemler.txt dosyası açılamadı!" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        char operation;
        int idx1, idx2;

        iss >> operation;

        if (operation == 'C')
        { // Çaprazlama
            iss >> idx1 >> idx2;
            crossover(idx1, idx2);
        }
        else if (operation == 'M')
        { // mutation
            int genIndex;
            iss >> idx1 >> genIndex;
            mutation(idx1, genIndex);
        }
        else
        {
            std::cerr << "Geçersiz işlem: " << operation << std::endl;
        }
    }

    file.close();
    std::cout << "Otomatik işlemler tamamlandı!" << std::endl;
}

void DNA::printSmallestGenes()
{
   
    Kromozom *current = kromozomHead; 
    if (!current) {
        std::cerr << "No chromosomes available.\n";
        return;
    }

    while (current) // tüm kromozomlardan dön
    {
        Gen *gen = current->genHead;
        if (!gen) { 
            std::cerr << "Chromosome has no genes.\n";
            current = current->nextKromozom; 
            continue;
        }

        Gen *smallest = gen; // ilkini en küçük varsayıyoruz
        while (gen) { 
            if (gen->data < smallest->data) {
                smallest = gen; // daha kücük bulunursa en kücük o
            }
            gen = gen->genNext; 
        }

       
        std::cout << smallest->data << " "<<std::endl;
        current = current->nextKromozom; // yeni kromozoma geç
    }
    std::cout << std::endl; 
}
