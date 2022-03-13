#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    char *command="";
    char quit;

    do
    {
        printf("Give a command: ");
        scanf("%s",command);
        system(command);
        puts(command);
        scanf("%c",&quit);
        printf("%c",quit);
    }while(!(quit=='n'));

    return 0;
}
