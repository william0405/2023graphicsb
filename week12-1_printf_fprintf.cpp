#include <stdio.h>
int main()
{

    char line[20];
    FILE * fin = fopen("file.txt","r");
    scanf(fin , "%s", line);
    printf("Ū��F:%s\n",line);
    scanf(fin , "%s", line);
    printf("Ū��F:%\n",line);
}
