#include <stdio.h>
#include <limits.h>

#define V 16

void prim_MST(int[][V]);
int find_min(int[], int[]);
void print_MST(int[], int[][V]);


int find_min(int key[], int vertex_set[]){
    /* key[]: array to store key value of vertices
    infinity if vertex not in MST
    weight of edge with other end in MST if otherwise
    MST[]: store vertices in MST
    1 if vertex is in MST
    0 otherwise */
    int min_vertex;// vertex with min weigh, other end in MST
    for(int v = 0; v < V; v++)
        if(vertex_set[v] == 0 && key[v] < INT_MAX)
            min_vertex = v;

    return min_vertex;
}

void print_MST(int MST[], int graph[V][V]){
    printf("egde\t weight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d\t %d\n", MST[i], i, graph[MST[i]][i]);
}

void prim_MST(int graph[V][V]){
    int key[V];// store key of vertex
    int MST[V];// store the MST. MST[i] = k means vertex i adjacent to vertex k
    int vertex_set[V];// store vertex alreadly in MST

    for(int v = 0; v < V; v++)
        key[v] = INT_MAX, vertex_set[v] = 0;
    
    key[0] = 0;// start at vertex 0

    MST[0] = -1;// 0 is in MST

    for(int vertex_count = 0; vertex_count < V - 1; vertex_count++){
        int new_vertex = find_min(key, vertex_set);// find vertex with min key

        vertex_set[new_vertex] = 1;// add to MST

        for(int v = 0; v < V; v++)
            if(graph[new_vertex][v] && vertex_set[v] == 0 && graph[new_vertex][v] < key[v]){
                MST[v] = new_vertex;
                key[v] = graph[new_vertex][v];
            }
    }
    print_MST(MST, graph);
}

int main(int argc, char *argv[])
{
    int graph[V][V] = { {76, 17, 70, 27, 13, 47, 89, 58, 20, 63, 99, 51, 47, 7, 54, 24},
                        {94, 77, 4, 36, 4, 17, 52, 27, 31, 88, 1, 33, 10, 40, 15, 30},
                        {17, 81, 60, 85, 17, 75, 1, 50, 33, 58, 86, 38, 73, 95, 2, 7},
                        {28, 99, 95, 16, 68, 76, 76, 57, 24, 55, 43, 18, 66, 31, 45, 62},
                        {56, 5, 83, 20, 43, 7, 13, 25, 97, 39, 39, 25, 75, 27, 83, 46},
                        {93, 69, 24, 8, 70, 72, 51, 13, 96, 3, 22, 30, 40, 34, 86, 3},
                        {22, 67, 2, 95, 7, 85, 58, 43, 74, 17, 62, 18, 1, 6, 20, 92},
                        {37, 31, 21, 67, 26, 80, 92, 32, 51, 50, 55, 4, 6, 56, 70, 61},
                        {21, 37, 21, 40, 18, 97, 42, 31, 27, 65, 91, 44, 78, 70, 71, 96},
                        {3, 35, 2, 83, 61, 36, 7, 41, 34, 9, 85, 97, 28, 3, 26, 77},
                        {69, 39, 83, 97, 77, 39, 37, 22, 14, 5, 27, 36, 29, 57, 9, 47},
                        {27, 44, 72, 13, 48, 84, 64, 49, 7, 88, 34, 37, 74, 52, 64, 77},
                        {22, 18, 58, 17, 30, 80, 73, 12, 37, 16, 95, 30, 46, 40, 81, 51},
                        {85, 93, 45, 52, 36, 29, 51, 18, 20, 98, 4, 41, 12, 36, 75, 24},
                        {88, 89, 47, 33, 25, 26, 91, 62, 65, 96, 63, 54, 44, 97, 40, 98},
                        {2, 67, 56, 11, 64, 26, 68, 95, 43, 76, 87, 19, 64, 86, 98, 21} };

    prim_MST(graph);

    return 0;
}
