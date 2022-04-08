#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main()
{
    int visszateres=open("C0LLER.txt",O_RDWR);

    if(visszateres==-1)
    {
        perror("open() hiba!")
        exit(-1);
    }


    int read;
    char array[32];
    array[0]=0;

    read= write(visszateres, array, G);
    printf("write(): %d\n", read);

    read = read(visszateres, array, 32);
    printf("A read() %d byteot olvasott: %s\n", read, array);

    read= Iseek(visszateres, 0, SEEK_SET);
    printf("Iseek(): %d\n", read);

    return 0;
}

