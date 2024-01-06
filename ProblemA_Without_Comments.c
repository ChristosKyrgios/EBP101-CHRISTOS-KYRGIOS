#include <stdio.h>
#include <math.h>
#include <string.h>

void generateReverseComplementary(char original[], char reverseComplementary[]) 
{
    int i;
    int length = strlen(original);
    
    for (i = 0; i < length; i++) 
    {
        switch (original[i]) 
        {
            case 'A':
                reverseComplementary[length - i - 1] = 'T'; 
                break;
            case 'T':
                reverseComplementary[length - i - 1] = 'A';
                break;
            case 'C':
                reverseComplementary[length - i - 1] = 'G';
                break;
            case 'G':
                reverseComplementary[length - i - 1] = 'C';
                break;
            default:
                reverseComplementary[length - i - 1] = original[i];  
        }
    }
    reverseComplementary[length] = '\0';  
}


int main()

{
  
  char seq[1000];    
  char reverseComplementarySeq[1000]; 
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
                                                                  minAminoAcids = (j - i) / 3 ;
                                                            }
                                              }
                                    if ( minAminoAcids > 100 ) 
                                    break; 
                            }
            }

      generateReverseComplementary(seq, reverseComplementarySeq); 
      for ( i = 0 ; i < length ; i++ ) 
            {
                    if ( reverseComplementarySeq[i] == 'A' && reverseComplementarySeq[i+1] == 'T' && reverseComplementarySeq[i+2] == 'G' )
                            {
                                    for ( j = i + 3 ; j < length ; j += 3 )
                                              {
                                                      if ( (reverseComplementarySeq[j] == 'T' && reverseComplementarySeq[j+1] == 'A' && reverseComplementarySeq[j+2] == 'A') || (reverseComplementarySeq[j] == 'T' && reverseComplementarySeq[j+1] == 'A' && reverseComplementarySeq[j+2] == 'G') || (reverseComplementarySeq[j] == 'T' && reverseComplementarySeq[j+1] == 'G' && reverseComplementarySeq[j+2] == 'A') )
                                                            { 
                                                                  count++; /* */
                                                                  minAminoAcids = (j - i) / 3 ;
                                                            }
                                              }
                                    if ( minAminoAcids > 100 )
                                              { count++; }
                                    break; 
                            }
            }

      if ( count == 0 ) 
          { printf ("This sequence does not have an ORF\n"); }
      else if ( count == 1 )
          { printf ("This sequence does not have a large enough ORF (with more than 100 aminoacids)\n"); }
      else if ( count == 2 )
          { printf ("This sequence has a valid ORF\n"); }
    
 }

return 0;
   
}
