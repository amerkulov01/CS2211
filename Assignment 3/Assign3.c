#include <stdio.h>

int print_Array(int orgArray[], int size);  //initialising function to print array
int large_Array(int orgArray[], int size);  //initialising function to show largest value
int rev_Array(int orgArray[], int size);    //initialising function to output array in reverse order
int sum_Array(int orgArray[], int size);    //initialsing function to calculate sum of all values in array
int desc_Array(int orgArray[], int size);   //initialising function to sort array into descending order
int swap_Array(int orgArray[], int size);   //initialising function which swaps first and last elements

int main() {
    int size;   //the size of the array
    int i;
    int j;
    printf("Please enter the number of integers to process: ");
    scanf("%d", &size); // taking in user imput for specified size of array
    int orgArray[size]; //setting original array to user inputted size
    printf("There is enough room in your array for %d integers ",size);
    printf("(%d bytes)\n",sizeof(orgArray));    //calcualting available bits based off size of array
    printf("\nPlease enter your integers seperated by spaces: ");
    for (i=0;i<size;i++) {  //for loop which takes in users input of values for the array seperated by spaces
        scanf("%d",&orgArray[i]);
    }
    print_Array(orgArray, size);    //calling function for part 1
    large_Array(orgArray, size);    //calling function for part 2
    rev_Array(orgArray, size);      //calling function for part 3
    sum_Array(orgArray, size);      //calling function for part 4
    desc_Array(orgArray, size);     //calling function for part 5
    swap_Array(orgArray, size);     //calling function for part 6

    return 0;

}

int print_Array(int orgArray[], int size) { //functino which prints users array
    //part 1
    int i;
    printf("\nPart 1:\n");
    printf("Your array is: ");
    for (i=0;i<size;i++) {  //for loop which prints each value and what index that value is at
        printf("[%d] = ",i);
        if (i<size-1) {
            printf("%d, ",orgArray[i]);
        } else {
            printf("%d\n",orgArray[i]); //no comma after the last digit
        }
    }
    return 0;
}

int large_Array(int orgArray[], int size) { //function which prints the largest number in array
    //part 2
    int i;
    int max = -9999;    //setting a low max to ensure it is overwritten by user input
    printf("\nPart 2:\n");
    printf("The largest value in your array is: ");
    for (i=0;i<size;i++) {
        if (orgArray[i] > max) {    //checks each value to see if it is larger than current max
            max = orgArray[i];
        }
    }
    printf("%d\n",max); //print max
    return 0;
}

int rev_Array(int orgArray[], int size) {   //function which reverses order of the array
    //part 3
    int i;
    printf("\nPart 3:\n");
    printf("Your array in reverse is: ");
    for (i=size-1;i>=0;i--) {   //loops from the last digit to the first digit now to print reverse order
        printf("[%d] = ",i);
        if (i!=0) {
            printf("%d, ",orgArray[i]);
        } else {
            printf("%d\n",orgArray[i]);
        }
    }
    return 0;
}

int sum_Array(int orgArray[], int size) {   //function which prints sum of all valules in the array
    //part 4
    int i;
    printf("\nPart 4:\n");
    printf("The sum of all values in your array is: ");
    int sum = 0;    //sum starts at 0
    for (i=0;i<size;i++) {  //loop through to add value at index 'i' to current sum total 
        sum = sum + orgArray[i];
    }
    printf("%d\n",sum);
    return 0;
}

int desc_Array(int orgArray[], int size) {  //funciton which prints array in descending order
    //part 5
    printf("\nPart 5:\n");
    int i;
    int j;  //initialising a j because we are using 2 counts for 2 for loops
    int temp = 0;
    int array2[size];   //initialising the second array so we do not manipulate the original array
    for (i=0;i<size;i++) {  //loop to copy every value from original array to array2
        array2[i] = orgArray[i];
    }
    for (i=0;i<size;i++) {  //to loop through all values of array
        for (j=i+1;j<size;j++) {    //compares current element from first loop with every other element
            if (array2[i] < array2[j]) {    //if current element is smaller than any other element it swaps places with it
                temp = array2[i];  //temporary variable to hold value at i while we swap i and j
                array2[i] = array2[j];
                array2[j] = temp;  //now putting temp into j
            }
        }
    }
    printf("Your array in sorted order is : ");
    for (i=0;i<size;i++) {  //printing the new sorted array
        printf("[%d] = ",i);
        if (i<size-1) {
            printf("%d, ",array2[i]);
        } else {
            printf("%d\n",array2[i]);
        }
    }
    return 0;
}

int swap_Array(int orgArray[], int size) {  //funciton which swaps first and last element of the array
    printf("\nPart 6\n");
    int i;
    int array3[size];   //initialising third array so we do not manipulate original array
    for (i=0;i<size;i++) {  //copying original array values into array3
        array3[i] = orgArray[i];
    }
    int temp;
    temp = array3[0];   //temporarily storying value at index '0' in temp
    array3[0] = array3[size-1]; //index '0' is now equal to last element of array (size of array -1)
    array3[size-1] = temp;  //last element of array is changed to first element which was being held by temp
    printf("Your array with first and last element switched is: ");
    for(i=0;i<size;i++) {   //printing out the new array
        printf("[%d] = ",i);
        if (i<size-1) {
            printf("%d, ",array3[i]);
        } else {
            printf("%d\n",array3[i]);
        }
    }
    return 0;
}
