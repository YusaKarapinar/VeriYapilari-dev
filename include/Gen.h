#ifndef GEN_H
#define GEN_H

class Gen {
public:
    char data;      // Gen karakteri
    Gen* GenNext;      // Sonraki gene işaretçi

    Gen(char d);    // Yapıcı fonksiyon
};

#endif
