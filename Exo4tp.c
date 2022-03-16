#include<sys/types.h>
#includ <stdlib.h>
#include<md5.h>

int main ()
{
    int fd1;
    MD5File(fd1, &buffer );
    printf ("%p", buffer);
    fclose( fd1 );
    return 0;
}
