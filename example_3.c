#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{

char seq[1000];
int length;
int i;

while ( scanf("%s", seq ) == 1 )
      {
      length = strlen( seq );

      for ( i = 0 ; i < length ; i++ )
              {
                    if ( seq[i] == 'D' || 'E' || 'H' || 'K' || 'N' || 'Q' || 'R' )
                          { printf(" "); }
                    else if ( seq[i] == 'S' || 'T' || 'G' )
                          { printf("."); }
                    else if ( seq[i] == 'A' || 'C' || 'M' || 'P' )
                          { printf(":"); }
                    else if ( seq[i] == 'F' || 'I || 'L' || 'V' || 'W' || 'Y' )
                          { printf("*"); }
              }
      }
}
