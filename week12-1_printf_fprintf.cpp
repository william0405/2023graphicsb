#include <stdio.h>
int main()
{

    char line[20];
    FILE * fin = fopen("file.txt","r");
    scanf(fin , "%s", line);
    printf("讀到了:%s\n",line);
    scanf(fin , "%s", line);
    printf("讀到了:%\n",line);
}
