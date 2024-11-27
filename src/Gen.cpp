/**
* gen.cpp 
* gen değişkenlerinin bulundugu dosya
* 2. öğretim A grubu
* 1. ödev
* 25.11.2024
* Yuşa Karapınar yusa.karapinar@ogr.sakarya.edu.tr
*/
#include "Gen.h"

Gen::Gen(char d) {
    // data üyeye değer atama
    data = d;

    // next işaretçisini null olarak başlatma
    genNext = nullptr;
}
