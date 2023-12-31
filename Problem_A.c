#include <stdio.h>
#include <math.h>
#include <string.h>

/* Η συνάρτηση δεν θα μας επιστρέψει κάποια τιμή. Γι'αυτό το λόγο ξεκινά με το void. Το όνομα της είναι generateReverseComplementary και στις παραμέτρους ορίζονται οι δυο μεταβλητές τύπου string, δηλαδή η original και η reverseComplementary. Παρακάτω θα δούμε ότι στη θέση τους θα μπουν οι μεταβλητές seq και reverseComplementarySeq αντίστοιχα */
void generateReverseComplementary(char original[], char reverseComplementary[]) 
{
    int i;
    int length = strlen(original);
    
    for (i = 0; i < length; i++) 
    {
        switch (original[i]) /* Στη θέση πολλαπλών if-else χρησιμοποιείται η συνάρτηση switch. Αναζητώντας χαρακτήρα-χαρακτήρα στο string original (ή seq) όταν ισχύει η τιμή που υπάρχει στο case εκτελείται ο κώδικας που ακολουθεί και η εκτέλεση ολοκληρώνεται με το break. Τέλος, με το default εξασφαλίζεται πως κάθε άλλος χαρακτήρας πέραν αυτών που μαςενδιαφέρουν δεν θα αλλάξει */
        {
            case 'A':
                reverseComplementary[length - i - 1] = 'T'; /* Το (length - i - 1) εξασφαλίζει ότι η συμπληρωματική αλληλουχία θα αναστραφεί επίσης, ώστε να διαβαστεί για την εύρεση ενός ORF με κατεύθυνση 5' -> 3' */
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
    reverseComplementary[length] = '\0';  /* Με αυτόν τον τρόπο εξασφαλίζεται ότι το μετά τον τελευταίο χαρακτήρα του string θα μπει ένας χαρακτήρας null ώστε να σημανθεί το τέλος της αλληλουχίας, κάτι απαραίτητο για τη γλώσσα προγραμματισμού C */
}


int main()

{
  
  char seq[1000];    /* Δηλώνω μεταβλητή τύπου string με μέγιστο μήκος τους 1000 χαρακτήρες, στην οποία θα αποθηκευτεί η αλληλουχία DNA */
  char reverseComplementarySeq[1000]; /* Δηλώνω μεταβλητή που θα περιέχει τη συμπληρωματική αλληλουχία ανεστραμμένη */
  int i, j, length, count, minAminoAcids;  /* Δηλώνω μεταβλητές τύπου ακεραίου : για την αρχικοποίηση των επερχόμενων for (i και j), για το μήκος της αλληλουχίας (length), για τον μετρητή count που καθορίζει άμεσα το αποτέλεσμα (το αν μία αλληλουχία έχει ORF ή όχι) και το minAminoAcids ώστε να ελεγχθεί και ότι το μήκος του ORF είναι αρκετά μεγάλο ώστε αυτό να θεωρείται ένα έκγυρο ORF */ 

while ( scanf("%s", seq ) == 1 )  /* Με την εντολή αυτή το πρόγραμμα διαβάζει και εκτελεί όσα υπάρχουν μέσα στην while για πολλές αλληλουχίες που μπορεί να πληκτρολογήσει ο χρήστης */
  {
         length = strlen(seq);
         count = 0;
         minAminoAcids = 0;
      
      for ( i = 0 ; i < length ; i++ )  /* Με αυτή την πρώτη for, το string διαβάζεται χαρακτήρα-χαρακτήρα μέχρις ότου βρεθεί το κωδικόνιο έναρξης, κάτι που διασφαλίζεται από την if που ακολουθεί. Επειδή η πρώτη θέση στο string είναι αριθμημένη με 0 και όχι 1, για αυτό και για να γίνει αναζήτηση σε όλη την αλληλουχία η for συνεχίζεται με βήμα 1 μέχρι το length-1 και όχι μέχρι το length ( i < length ) */
            {
                    if ( seq[i] == 'A' && seq[i+1] == 'T' && seq[i+2] == 'G' )
                            {
                                    for ( j = i + 3 ; j < length ; j += 3 ) /* Η δεύτερη for, θα εκτελεστεί μόνο εφόσον βρεθεί κωδικόνιο έναρξης στην αλληλουχία. Σε αυτή, το j θα αυξάνει με βήμα 3, για ολόκληρη την αλληλουχία μέχρις ότου βρεθεί κάποιο από τα κωδικόνια λήξης. */
                                              {
                                                      if ( (seq[j] == 'T' && seq[j+1] == 'A' && seq[j+2] == 'A') || (seq[j] == 'T' && seq[j+1] == 'A' && seq[j+2] == 'G') || (seq[j] == 'T' && seq[j+1] == 'G' && seq[j+2] == 'A') )
                                                            { 
                                                                  count++; /* Το count = 1 εξασφαλίζει ότι βρέθηκε κωδικόνιο έναρξης και με βήμα τριπλέτας ένα από τα τρία κωδικόνια λήξης. Δεν έχει ληφθεί ωστόσο υπόψιν το μήκος του ORF. Αυτό γίνεται με τη βοήθεια της επόμενης μεταβλητής, του minAminoAcids, που υπολογίζει τον αριθμό αμινοξέων του ORF */
                                                                  minAminoAcids = (j - i) / 3 ;
                                                            }
                                              }
                                    if ( minAminoAcids > 100 ) /* Αφού εκτελεστεί η προηγούμενη for, με την συγκεκριμένη if μπορεί να οριστεί ένα ελάχιστο μήκος σε αμινοξέα που θεωρούμε αποδεκτό ότι αντιπροσωπεύει ένα έγκυρο ORF. Αυτό για ένα απλό βακτηριακό ORF τυπικά θεωρείται ως τα 100 αμινοξέα. */
                                              { count++; }
                                    break; /* Το break εξασφαλίζει ότι αφού βρεθεί ένα ATG, δεν θα ξεκινήσει η αναζήτηση εκ νέου αν μέσα στο ORF υπάρχουν και άλλα κωδικόνια ATG */
                            }
            }

      generateReverseComplementary(seq, reverseComplementarySeq); /* Επανάληψη της διαδικασίας για τη συμπληρωματική αλληλουχία. */
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

      if ( count == 0 ) /* Στις ακόλουθες if, ο μετρητής count ανάλογα την τιμή που έχει λάβει μετά την αναζήτηση, μπορεί να δώσει τρία πιθανά αποτελέσματα : α) Δεν υπάρχει ORF στην αλληλουχία όταν count = 0, β) Υπάρχει ORF στην αλληλουχία αλλά δεν έχει επαρκώς μεγάλο αριθμό αμινοξέων όταν count = 2 και γ) Υπάρχει ORF όταν count = 2 */
          { printf ("This sequence does not have an ORF\n"); }
      else if ( count == 1 )
          { printf ("This sequence does not have a large enough ORF (with more than 100 aminoacids)\n";) }
      else if ( count == 2 )
          { printf ("This sequence has a valid ORF\n"); }
    
 }

return 0;
   
}


