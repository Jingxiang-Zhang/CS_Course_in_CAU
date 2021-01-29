#include <stdio.h>
#include <stdlib.h>
typedef unsigned char* byte_poniter; 
void to_bites(byte_poniter start, int len)
{int i,j;
    for (i = 0; i < len ;i++)
    {
        for (j = 0; j < 8; j++)
            printf("%d", (start[i] >> j) & 0x1);
        printf(" ");
    }
    printf("\n");
}
 
void main()
{
    double dx = 10.5 ;	
  
    
    to_bites((byte_poniter)&dx, sizeof(double));
}
