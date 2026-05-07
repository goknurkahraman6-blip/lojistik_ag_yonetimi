#include "graph.h"

// Yeni bir graf dügümü olustur
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    printf("[GRAF ANALIZI] Sehir %d dugumu olusturuldu. Bellek Adresi: %p\n", v, (void*)newNode);
    newNode->cityID = v;
    newNode->next = NULL;
    return newNode;
}

// Grafy olustur
Graph* createGraph(int cities) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numCities = cities;
    graph->adjLists = (Node**)malloc(cities * sizeof(Node*));
int i;
    for (i = 0; i < cities; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Bağlantı (Kenar) ekle 
void addEdge(Graph* graph, int src, int dest) {
    // Kaynaktan hedefe
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Hedef'ten kaynağa 
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
    
    printf("Sehir %d ile Sehir %d arasinda baglanti kuruldu.\n", src, dest);
}

// BFS (Breadth-First Search) Gezinme
void BFS(Graph* graph, int startCity) {
    int* queue = (int*)malloc(graph->numCities * sizeof(int));
    int head = 0, tail = 0;
    int* visited = (int*)malloc(graph->numCities * sizeof(int));
    int i;
    for (i = 0; i < graph->numCities; i++) {
        visited[i] = 0;
    }

    visited[startCity] = 1;
    queue[tail++] = startCity;

    printf("\n--- BFS Gezinme Sirasi (Baslangic: %d) ---\n", startCity);
    
    while (head < tail) {
        int currentCity = queue[head++];
        printf("%d -> ", currentCity);

        Node* temp = graph->adjLists[currentCity];
        while (temp != NULL) {
            int adjCity = temp->cityID;
            if (visited[adjCity] == 0) {
                visited[adjCity] = 1;
                queue[tail++] = adjCity;
            }
            temp = temp->next;
        }
    }
    printf("BITIS\n\n");
    
    free(queue);
    free(visited);
}

void freeGraph(Graph* graph) {
	int i;
    for (i = 0; i < graph->numCities; i++) {
        Node* temp = graph->adjLists[i];
        while (temp != NULL) {
            Node* current = temp;
            temp = temp->next;
            free(current);
        }
    }
    free(graph->adjLists);
    free(graph);
}
