#include "hash.h"

// Tip A Hash Fonksiyonu (Modulo)
int hashFunction(int id, int size) {
    return id % size;
}

void initHashTable(Package** table, int size) {
	int i;
    for (i = 0; i < size; i++) {
        table[i] = NULL;
    }
}

// Yeni paket ekleme (Zincirleme)
void insertPackage(Package** table, int size, int id, char* content) {
    int index = hashFunction(id, size);
    Package* newPack = (Package*)malloc(sizeof(Package));
    if (newPack == NULL) {
        printf("Hata: Bellek ayrilamadi!\n");
        return;
    }
    printf("\n[BELLEK ANALIZI] Paket ID %d icin Heap'te yer ayrildi: %p\n", id, (void*)newPack);
printf("[POINTER ANALIZI] Bu paket index %d'ye baglaniyor. Onceki 'next' adresi: %p\n", index, (void*)table[index]);
    newPack->id = id;
    strcpy(newPack->content, content);
    
    // Ba?a ekleme (LIFO)
    newPack->next = table[index]; 
    table[index] = newPack;
    
    // Rapor için adresleri yazdyr
    printf("Paket %d, Bellek Adresi: %p, Sonraki: %p adresine eklendi (Index: %d).\n", 
           id, (void*)newPack, (void*)newPack->next, index);
}

Package* searchPackage(Package** table, int size, int id) {
    int index = hashFunction(id, size);
    Package* current = table[index];
    
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void displayHashTable(Package** table, int size) {
    printf("\n--- Hash Tablosu (Zincirleme) ---\n");
    int i;
    for (i = 0; i < size; i++) {
        printf("[%d]: ", i);
        Package* current = table[i];
        if (current == NULL) {
            printf("NULL\n");
        } else {
            while (current != NULL) {
                printf("(ID: %d | Adres: %p | next: %p) -> ", current->id, (void*)current, (void*)current->next);
                current = current->next;
            }
            printf("NULL\n");
        }
    }
}

void freeHashTable(Package** table, int size) {
	int i;
    for (i = 0; i < size; i++) {
        Package* current = table[i];
        while (current != NULL) {
            Package* temp = current;
            current = current->next;
            free(temp);
        }
        table[i] = NULL;
    }
}
