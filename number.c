#include <stdio.h>

int main(int argc, char *argv[])
{
    int num = 0;
    char* str = "1234";
    while ((*str) != '\0'){
        num = num*10 + (*str - '0');
        str++;
    }
    printf("%d\n", num);
    
    return 0;
}
