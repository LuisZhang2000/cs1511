#include <stdio.h>

int main(void) {

    int number;
    int Outliers = 0;
    int noRead;

    printf("Enter number: ");
    noRead = scanf("%d", &number);
    
    while (noRead == 1) {
        
        if (number < 5 || number > 25) {
            Outliers = Outliers + 1;
        }
        printf("Enter number: ");
        noRead = scanf("%d", &number);
   }
   
   printf("\n");
   printf("Outliers: %d\n", Outliers);
   
   return 0;
           
}
    
    
