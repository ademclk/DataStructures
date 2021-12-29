#include <stdio.h>
#include <stdlib.h>

#define tepe_sayisi 6

struct vertex {
    int node;
    struct vertex *nextVertex;
};
struct vertex *head[tepe_sayisi];

int indegree(int a[][tepe_sayisi], int v) {
    int i, degree = 0;
    for(i = 0; i < tepe_sayisi; i++)
        degree += a[i][v]; 
    return degree; 
}

int outdegree(int a[][tepe_sayisi], int v) {
    int i, degree = 0;
    for(i = 0; i < tepe_sayisi; i++)
        degree += a[v][i]; 
    return degree;
}

