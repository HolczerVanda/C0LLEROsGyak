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
    
}

