#include <stdio.h>
#include<limits.h>

#define V 12

int findMinDist(int[], int[]);
void dijkstra(int[][V], int);
void printResult(int[]);

int findMinDist(int minDist[], int exploredVertex[]){
    /* minDist[k]: store minumimum distance from source to
    vertex k
    explodedVertex[k]: 1 if vertex k is exploded, 0 otherwise*/
    int min = INT_MAX, min_vertex;
    for (int v = 0; v < V; v++)
    {
        if(exploredVertex[v] == 0 && minDist[v] < min)
            min = minDist[v], min_vertex = v;
    }
    
    return min_vertex;
}

void printResult(int minDist[]){
    printf("vertex \t\t distance from source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t\t %d\n", i, minDist[i]);
}

void dijkstra(int graph[][V], int source){
    int minDist[V];// minDist[i] store minimum distance from source to i
    int explodedVertex[V]; // 1 if vertex k is exploded, 0 otherwise

    for (int v = 0; v < V; v++)
    {
        minDist[v] = INT_MAX;
        explodedVertex[v] = 0;
    }

    minDist[source] = 0;
    
    for (int count = 0; count < V - 1; count++)
    {
        int next_vertex = findMinDist(minDist, explodedVertex);
        explodedVertex[next_vertex] = 1;
        //update distance
        for (int v = 0; v < V; v++)
            if (graph[next_vertex][v] && explodedVertex[v] == 0 && 
                minDist[next_vertex] != INT_MAX && minDist[next_vertex] + graph[next_vertex][v] < minDist[v])
                /* Update minDist[v] only if is not in sptSet, there's an edge from next_vertex to v, total
                weight of path from source to v through next_vertex smaller than current value of minDist[v] */
                minDist[v] = minDist[next_vertex] + graph[next_vertex][v];
    }
    printResult(minDist);
}
int main(int argc, char *argv[])
{
    int graph[V][V] = {{0, 3, 5, 4, 0, 0, 0, 0, 0, 0, 0, 0},
                       {3, 0, 0, 0, 3, 6, 0, 0, 0, 0, 0, 0},
                       {5, 0, 0, 2, 0, 0, 4, 0, 0, 0, 0, 0},
                       {4, 0, 2, 0, 1, 0, 0, 5, 0, 0, 0, 0},
                       {0, 3, 0, 1, 0, 2, 0, 0, 4, 0, 0, 0},
                       {0, 6, 0, 0, 2, 0, 0, 0, 0, 5, 0, 0},
                       {0, 0, 4, 0, 0, 0, 0, 3, 0, 0, 6, 0},
                       {0, 0, 0, 5, 0, 0, 3, 0, 6, 0, 7, 0},
                       {0, 0, 0, 0, 4, 0, 0, 6, 0, 3, 0, 5},
                       {0, 0, 0, 0, 0, 5, 0, 0, 3, 0, 0, 9},
                       {0, 0, 0, 0, 0, 0, 6, 7, 0, 0, 0, 8},
                       {0, 0, 0, 0, 0, 0, 0, 0, 5, 9, 8, 0}};

    dijkstra(graph, 0);
    return 0;
}
