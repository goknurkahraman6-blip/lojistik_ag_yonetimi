#ifndef GRAPH_H
#define GRAPH_H

#include "common.h"

// Graf Düðümü (Komþuluk Listesi)
typedef struct Node {
    int cityID;
    struct Node* next;
} Node;

// Þehir Listesi (Graf)
typedef struct Graph {
    int numCities;
    Node** adjLists;
} Graph;

// Graf Ýþlevleri
Graph* createGraph(int cities);
void addEdge(Graph* graph, int src, int dest);
void BFS(Graph* graph, int startCity);
void freeGraph(Graph* graph);

#endif
