#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int indexarr(float num[], int len_num, float numb){ // This function returns given item's index in given array
    for (int i = 0; i < len_num; i = i + 1){
        if(num[i] == numb){
            return i;
        }
    }
    // Note that if given item repeats itself on given array, it'll only return first appearence's index.
}

float sum(float num[],float numlen){ // This function returns the sum of all items of given array
    float sum = 0; // Initializes the float variable that contains the sum of given items
    for(int i = 0; i < numlen; i += 1){
        sum += num[i]; // Sums the items 
    }
    return sum;
}

float minus(float num[],float numlen){ // This function returns the subtraction of all items of given array using its first item as a starting point
    float minus = 0; // Initializes the float variable that contains the subtraction of given items
    for(int i = 0; i < numlen; i += 1){
        if(i == 0){
            minus = num[i]; // Sets starting point
    }
    else{
    minus -= num[i]; // Subtracts the items
    }
    }
    return minus;
}

float multiply(float num[],float numlen){ // This function returns the product of all items of given array using its first item as a starting point
    float multiply = 0;  // Initializes the float variable that contains the product of given items
    for(int i = 0; i < numlen; i += 1){
        if(i == 0){
            multiply = num[i]; // Sets starting point
    }
    else{
    multiply = multiply * num[i]; // Multiplies the items
    }
    }
    return multiply;
}

float divide(float num[],float numlen){ // This function returns the division of all items of given array using its first item as a starting point
    float divide = 0;  // Initializes the float variable that contains the division of given items
    for(int i = 0; i < numlen; i += 1){
        if(i == 0){
            divide = num[i]; // Sets starting point
    }
    else{
    divide = divide / num[i]; // Divides the items
    }
    }
    return divide;
}

float mean(float num[], int len_num){ // This function returns the arithmetic mean of given array's items

    return divide(sum(num,len_num),len_num); // Returns the arithmetic mean, using the known formula (sum of items divided by number of items)
}

float max(float num[], int len_num){ // This function returns the maximum item of given array

    float max = num[0]; // Initializes the maximum item variable by setting the first item of given array as starting point
    for (int i = 0; i < len_num; i = i + 1){
        if (max < num[i]){ // The next item is greater than the item that is believed to be the maximum [...]
            max = num[i]; // [...] it'll be replaced by this item
        }
    }
    return max;
}

float min(float num[], int len_num){ // This function returns the minimum item of given array 
    float min = num[0]; // Initializes the minimum item variable by setting the first item of given array as starting point
    for (int i = 0; i < len_num; i = i + 1){
        if (min > num[i]){ // The next item is less than the item that is believed to be the maximum [...]
            min = num[i]; // [...] it'll be replaced by this item
        }
    }
    return min;
}

char * sortcres(float num[], int len_num){ // This function returns a string containg the crescent order of given array's items 
    int len1 = len_num; // Initializes the variable length by starting with the same length as the actual given array
    float tosort[len_num]; // Defines the temporary array that will contain the given array's items (reason: given array is static, and the sorting algorithm will actually pop array's items, so it needs to not be constant/static)
    
    for(int i = 0; i < len_num; i = i + 1){
        tosort[i] = num[i]; // Copies items from given array
    }

    float sorted[len_num]; // Defines the array that will contain the rearranged items 
    for(int i = 0; i < len_num;i = i + 1){
        float number = min(tosort, len1); // Searches for temporary array's minimum value
        sorted[i] = number; // Sets current index's item from array as the current minimum value
        int x = indexarr(tosort,len_num,number); // Searches for such item's index at temporary array
        for (int j = x; j< len1;j = j + 1){
            tosort[j] = tosort[j + 1]; // Pops the item 
        }
        len1 = len1 - 1; // Subtracts the popped item from length
    }

    char* result = (char*)malloc(10000 * sizeof(char)); // Dynamically allocates memory for string that will contain the sorted items
    result[0] = '\0'; // Initializes array by setting starting item as null
    for (int i = 0; i < len_num; i++) {
        char buffer[100]; // Defines temporary string that will contain current item
        sprintf(buffer, "%.3f\n", sorted[i]); // Converts current item from float to string, allocating it into temporary string
        strcat(result, buffer); // Concatenates temporary string into result string
    }

    return result;
}

char * sortdecres(float num[], int len_num){ // This function returns a string containg the decrescent order of given array's items 
     int len1 = len_num; // Initializes the variable length by starting with the same length as the actual given array
    float tosort[len_num]; // Defines the temporary array that will contain the given array's items (reason: given array is static, and the sorting algorithm will actually pop array's items, so it needs to not be constant/static)
    
    for(int i = 0; i < len_num; i = i + 1){
        tosort[i] = num[i]; // Copies items from given array
    }

    float sorted[len_num]; // Defines the array that will contain the rearranged items 
    for(int i = 0; i < len_num;i = i + 1){
        float number = max(tosort, len1); // Searches for temporary array's maximum value
        sorted[i] = number; // Sets current index's item from array as the current minimum value
        int x = indexarr(tosort,len_num,number); // Searches for such item's index at temporary array
        for (int j = x; j< len1;j = j + 1){
            tosort[j] = tosort[j + 1]; // Pops the item 
        }
        len1 = len1 - 1; // Subtracts the popped item from length
    }

    char* result = (char*)malloc(10000 * sizeof(char)); // Dynamically allocates memory for string that will contain the sorted items
    result[0] = '\0'; // Initializes array by setting starting item as null
    for (int i = 0; i < len_num; i++) {
        char buffer[100]; // Defines temporary string that will contain current item
        sprintf(buffer, "%.3f\n", sorted[i]); // Converts current item from float to string, allocating it into temporary string
        strcat(result, buffer); // Concatenates temporary string into result string
    }

    return result;
}

char * to_date(int num){ // This function converts given 6-digit number into a DD/MM/YY date string
    if(num > 999999){
        return "Error: Given date is greater than application's limit (99/99/99)";
    }
    char* tdate = (char*)malloc(9 * sizeof(char)); // Dynamically allocates memory for converted date string
    sprintf(tdate,"%02d/%02d/%02d", num/10000,(num/100)%100,num%100); // Converts given integer into DD/MM/YY date format and stores it on the date string
    return tdate;

}


