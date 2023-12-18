#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{

    char seq[ 1000 ];
    int length;

    while (scanf("%s", seq) == 1 )
    {
          length = strlen(seq);
          printf("The length is %d\n", length );
    }

}
