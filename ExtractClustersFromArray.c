#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int graph[MAX][MAX];
bool seen[MAX];

void dfsCluster(int v, int n) {
    int i;
    seen[v] = true;
    printf("%d ", v);

    for (i = 0; i < n; i++) {
        if (graph[v][i] && !seen[i]) {
            dfsCluster(i, n);
        }
    }
}

void detectClusters(int n) {
    int i;
    int id = 0;

    for (i = 0; i < n; i++)
        seen[i] = false;

    for (i = 0; i < n; i++) {
        if (!seen[i]) {
            id++;
            printf("Cluster %d: ", id);
            dfsCluster(i, n);
            printf("\n");
        }
    }
}

int main() {
    int n = 6;
    int i, j;

    int temp[6][6] = {
        {0,1,0,0,0,0},
        {1,0,0,0,0,0},
        {0,0,0,1,1,0},
        {0,0,1,0,1,0},
        {0,0,1,1,0,0},
        {0,0,0,0,0,0}
    };

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            graph[i][j] = temp[i][j];

    detectClusters(n);

    return 0;
}
