// Find and return the minimum positive value
// from the values in a given array.
// By Luis Zhang (z5205864)
// Written on 2018-09-09
// Andrew Bennett (wed11-strings)


// You need to implement this function

// Returns the minimum positive value from a given array.
// A value is a positive value if it is greater than zero.
// If there are no positive values in a given list,
// the function should return zero.

int arrayPositiveMin(int a[], int size) {
    
    int value = 0;
    int currentMin;
    int j = 0;
    int i = 0;
    
    while (value <= 0 && j < size) {    /* while the number is within the array
                                           size and the number is negative, 
        value = a[j];                      assign to the value */
        j = j + 1;
        
    }
    
    if (value > 0) {                    /* the operations below apply to when
        currentMin = value;                the value is positive */
        
        while (i < size) {
            
            if (a[i] > 0 && a[i] < currentMin) {    /* if the number is +ve and
                currentMin = a[i];                     greater than the current
            }                                          min value, assign it to
                                                       the new current min */
            i = i + 1;
        }    
    } else {
        currentMin = 0;
    }             
    return currentMin;
}
