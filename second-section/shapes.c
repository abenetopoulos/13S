/* Draw this shape
        *         
      * * *       
    * * * * *     
  * * * * * * *   
* * * * * * * * * 
*/


#include<stdio.h>

int main() {
    int n;
    do {
        printf("Enter the number of rows: ");
        scanf("%d", &n);
        if (n % 2) {
            // number is odd
            break;
        }

        printf("\nYou need to specify an odd number of rows\n");
    } while (1);

    int numColumns = 2 * n - 1;
    for (int i=1; i<=n; i++) { //number of rows
        int numEntries = 2 * i - 1;
        int numBlanksEitherSide = (numColumns - numEntries) / 2;
        for (int j = 0; j < numBlanksEitherSide; j++) {
            printf("  ");
        }

        for (int j = 1; j <= numEntries; j++) {
            printf("* ");
        }

        for (int j = 0; j < numBlanksEitherSide; j++) {
            printf("  ");
        }
    
        printf("\n");
    }
    return 0;
}