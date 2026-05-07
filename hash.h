#ifndef HASH_H
#define HASH_H

#include "common.h"

// Paket Yapýsý (Linked List Düðümü)
typedef struct Package {
    int id;
    char content[50];
    struct Package* next; // Zincirleme için pointer
} Package;

// Hash Tablosu Ýþlevleri
void initHashTable(Package** table, int size);
void insertPackage(Package** table, int size, int id, char* content);
Package* searchPackage(Package** table, int size, int id);
void displayHashTable(Package** table, int size);
void freeHashTable(Package** table, int size);

#endif
