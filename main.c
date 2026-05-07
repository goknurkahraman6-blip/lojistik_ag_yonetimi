#include "graph.h"
#include "hash.h"

#define HASH_TABLE_SIZE 10
#define NUM_CITIES 5

int main() {
    // Yapýlarý Baþlat
    Package* hashTable[HASH_TABLE_SIZE];
    initHashTable(hashTable, HASH_TABLE_SIZE);
    Graph* cityGraph = createGraph(NUM_CITIES);

    int choice;
    int id, src, dest,start;
    char content[50];
    Package* found;

    while (1) {
        printf("\n--- LOJISTIK YONETIM SISTEMI ---\n");
        printf("1. Sehir Baglantisi Ekle\n");
        printf("2. BFS Calistir (Sehir Gezinmesi)\n");
        printf("3. Paket Ekle\n");
        printf("4. Paket Ara\n");
        printf("5. Hash Tabloyu Goster (Bellek Durumu)\n");
        printf("0. Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Kaynak Sehir (0-%d): ", NUM_CITIES - 1);
                scanf("%d", &src);
                printf("Hedef Sehir (0-%d): ", NUM_CITIES - 1);
                scanf("%d", &dest);
                if (src >= 0 && src < NUM_CITIES && dest >= 0 && dest < NUM_CITIES) {
                    addEdge(cityGraph, src, dest);
                } else {
                    printf("Hata: Gecersiz sehir ID!\n");
                }
                break;
            case 2:
                printf("Baslangic Sehri (0-%d): ", NUM_CITIES - 1);
                scanf("%d", &start);
                BFS(cityGraph, start);
                break;
            case 3:
                printf("Paket ID: ");
                scanf("%d", &id);
                printf("Paket Icerigi: ");
                scanf("%s", content);
                insertPackage(hashTable, HASH_TABLE_SIZE, id, content);
                break;
            case 4:
                printf("Aranacak Paket ID: ");
                scanf("%d", &id);
                found = searchPackage(hashTable, HASH_TABLE_SIZE, id);
                if (found != NULL) {
                    printf("Paket Bulundu: ID=%d, Icerik=%s, Adres=%p\n", 
                           found->id, found->content, (void*)found);
                } else {
                    printf("Paket Bulunamadi.\n");
                }
                break;
            case 5:
                displayHashTable(hashTable, HASH_TABLE_SIZE);
                break;
            case 0:
                printf("Cikiliyor...\n");
                // Bellek Temizliði
                freeHashTable(hashTable, HASH_TABLE_SIZE);
                freeGraph(cityGraph);
                return 0;
            default:
                printf("Gecersiz secim!\n");
        }
    }

    return 0;
}
