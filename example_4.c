#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{

char seq[1000];
int count;

count = 0;

while ( scanf("%s", seq ) == 1 )
    {
          count++;
    }

printf("The total number of sequences is %d\n", count );

}
