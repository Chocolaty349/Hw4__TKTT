#include <stdio.h>

#define COINS 9
#define MAX 20

void find_minimum_coin(int);

int main(int argc, char* argv[])
{
    int n = 0;
    char *str = argv[1];
    while ((*str) != '\0')
    {
        n = n * 10 + (*str - '0');
        str++;
    }

    printf("Following is minimal number of change for %d: ", n);
    find_minimum_coin(n);
    return 0;
}

int coins[COINS] = {1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000, 500000};

void find_minimum_coin(int cost)
{
    int coinList[MAX] = {0};
    int i, coin_count = 0;

    for (i = COINS - 1; i >= 0; i--)
    {
        while (cost >= coins[i])
        {
            cost -= coins[i];
            // Add coin in the list
            coinList[coin_count++] = coins[i];
        }
    }

    for (i = 0; i < coin_count; i++)
        printf("%d ", coinList[i]);
    return;
}


