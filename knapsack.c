#include <stdio.h>

int max(int, int);
int knapSack(int, int[], int[], int);

int main(int argc, char const *argv[])
{
    //data in anany 3.4
    int value[] = {42, 12, 40, 25};
    int weight[] = {7, 3, 4, 5};
    int cap = 10;
    int numberOfItems = sizeof(value) / sizeof(value[0]);
    printf("maximum value: %d", knapSack(cap, weight, value, numberOfItems));
    return 0;
}

int max(int a, int b){
    return (a > b) ? a : b;
}
/* W: knapsack capcacity, n: number of items*/
int knapSack(int W, int wt[], int val[], int n){
    if (n == 0 || W == 0)
        return 0;

    /* if weight of n_th item > W, cannot put this item to knapsack*/
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);

    /* Return the maximum of two cases:
    1. n_th item included
    2. not included */
    else
        return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1) /* include n_th item */,
                   knapSack(W, wt, val, n - 1)); // not include
}
