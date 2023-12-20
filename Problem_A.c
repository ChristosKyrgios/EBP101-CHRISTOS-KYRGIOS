#include <stdio.h>
#include <math.h>
#include <string.h>

int main()

{

char seq[1000];
int i, j, length, count, minAminoAcids;

while ( scanf("%s", seq ) == 1 )
  {
      length = strlen(seq);
      count = 0;
      minAminoAcids = 0;
      
      for ( i = 0 ; i < length ; i++ )
            {
                    if ( seq[i] == 'A' && seq[i+1] == 'T' && seq[i+2] == 'G' )
                            {
                                    for ( j = i + 3 ; j < length ; j += 3 )
                                              {
                                                      if ( (seq[j] == 'T' && seq[j+1] == 'A' && seq[j+2] == 'A') || (seq[j] == 'T' && seq[j+1] == 'A' && seq[j+2] == 'G') || (seq[j] == 'T' && seq[j+1] == 'G' && seq[j+2] == 'A') )
                                                            { 
                                                                  count++;
                                                                  minAminoAcids = j - i / 3 ;
                                                            }
                                              }
                                    if ( minAminoAcids < 5 )
                                              { count++; }                             
                            }
            }
      if ( count == 0 )
          { printf ("This sequence does not have an ORF\n"); }
      else if ( count == 1 )
          { printf ("This sequence does not have a large enough ORF (with more than 5 aminoacids\n"); }
      else if ( count == 2 )
          { printf ("This sequence has a valid ORF\n"); }
 }

}
