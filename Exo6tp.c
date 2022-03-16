#include <stdio.h>
#include <stdlib.h>
#include<md5.h>

int main ()
{
    int i;
    for (i=1; i<1000; i++)
    {
         int a;
         MD5File(a, &buffer );
         printf ("%p", buffer);
    }


    fclose( a );
    return 0;
}
