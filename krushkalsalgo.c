#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 100



// Function prototypes
int find(int parent[], int i);
void Union(int parent[], int x, int y);
void KruskalMST(int graph[][3], int V, int E);

int main() {
    int V = 4;  // Number of vertices in the graph
    int E = 5;  // Number of edges in the graph
    int graph[MAX_EDGES][3] = {
        // src, dest, weight
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    KruskalMST(graph, V, E);

    return 0;
}

// Find set of an element i 
int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void Union(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}



// Kruskal's algorithm to find MST
void KruskalMST(int graph[][3], int V, int E) {
    int parent[V];
    int a,b,temp1,temp2,temp3;
    for (int i = 0; i < V; ++i)
        parent[i] = -1;

    int i = 0, e = 0; // Index variable for sorted edges and result[]

    // Sort all the edges in increasing order of their weight
    for(a=0;a<E-1;a++)
    {
        for(b=0;b<E-1;b++)
        {
            if (graph[b][2]>graph[b+1][2])
            {
                temp1=graph[b][0];
                temp2=graph[b][1];
                temp3=graph[b][2];
                graph[b][0]=graph[b+1][0];
                graph[b][1]=graph[b+1][1];
                graph[b][2]=graph[b+1][2];
                graph[b+1][0]=temp1;
                graph[b+1][1]=temp2;
                graph[b+1][2]=temp3;
            }
        }
    }

    printf("Edges of the MST:\n");

    // Number of edges to be taken is V-1
    while (e < V - 1 && i < E) {
        // Pick the smallest edge
        int src = graph[i][0];
        int dest = graph[i][1];
        int weight = graph[i][2];
        i++;

        int x = find(parent, src);
        int y = find(parent, dest);

        // If including this edge does not form a cycle, include it in the result and increment the index of result for next edge
        if (x != y) {
            printf("%d -- %d == %d\n", src, dest, weight);
            Union(parent, x, y);
            e++;
        }
    }
}
