#include <stdio.h>
#include<limits.h>

#define V 16

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
    int graph[V][V] = { {0, 99, 49, 83, 31, 50, 130, 87, 63, 192, 24, 108, 96, 189, 108, 89},
                        {99, 0, 104, 103, 80, 146, 119, 109, 147, 64, 118, 76, 101, 62, 143, 67},
                        {49, 104, 0, 107, 146, 91, 159, 65, 93, 41, 130, 79, 61, 4, 148, 11},
                        {83, 103, 107, 0, 125, 129, 130, 68, 17, 85, 11, 35, 111, 54, 33, 86},
                        {31, 80, 146, 125, 0, 96, 128, 157, 117, 81, 125, 80, 72, 100, 42, 13},
                        {50, 146, 91, 129, 96, 0, 118, 159, 125, 90, 26, 161, 120, 56, 163, 157},
                        {130, 119, 159, 130, 128, 118, 0, 55, 99, 26, 18, 19, 37, 126, 69, 95},
                        {87, 109, 65, 68, 157, 159, 55, 0, 129, 91, 108, 157, 53, 48, 128, 46},
                        {63, 147, 93, 17, 117, 125, 99, 129, 0, 140, 66, 73, 130, 82, 142, 102},
                        {192, 64, 41, 85, 81, 90, 26, 91, 140, 0, 55, 27, 127, 97, 131, 134},
                        {24, 118, 130, 11, 125, 26, 18, 108, 66, 55, 0, 117, 128, 116, 49, 83},
                        {108, 76, 79, 35, 80, 161, 19, 157, 73, 27, 117, 0, 80, 102, 110, 97},
                        {96, 101, 61, 111, 72, 120, 37, 53, 130, 127, 128, 80, 0, 74, 113, 109},
                        {189, 62, 4, 54, 100, 56, 126, 48, 82, 97, 116, 102, 74, 0, 42, 88},
                        {108, 143, 148, 33, 42, 163, 69, 128, 142, 131, 49, 110, 113, 42, 0, 140},
                        {89, 67, 11, 86, 13, 157, 95, 46, 102, 134, 83, 97, 109, 88, 140, 0} };

    dijkstra(graph, 0);
    return 0;
}
