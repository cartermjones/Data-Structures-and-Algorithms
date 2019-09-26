#include<stdio.h>
#include <stdlib.h>

/*
    Below is the merge function. It has a void return type and accepts three arguments:
    int l, int r, and int a[].
    int l is the leftmost (lowest) index of the integer array a[].
    int r is the rightmost (highest) index of the integer array a[].
    int a[] is the integer array to be merged. It is presumed to be sorted.
*/
void merge(int l, int r, int a[])
{
    //These are iterator variables.
    int i, j, k;
    //This creates the variable mid and instantiates it with the index position in the middle of the array.
    int mid = (l + r) / 2;
    //This creates an array named merged that has the same size as int a[].
    //This is important because this is the array where the sorted sub-arrays will be housed.
    int merged[r - l + 1];

    //The iterator i is set to the left index of the array a[].
    i = l;
    //The iterator j is set to the midpoint of array a[].
    j = mid + 1;
    //The iterator k is set to 0; it will be used to iterate through merged[].
    k = 0;

    /*
        This while loop will run until indexes i and j are at their natural limit (the midpoint of the array for i,
        which is used for the left side of the array, and r for j, which is the right side of the array.
        The purpose of this while loop is to populate the array merged[] with the ordered contents of the sub-arrays in a[].
    */
    while(i <= mid && j <= r)
    {
        /*
            This if statement checks to see if the value of a[i] is less than or equal to a[j].
            If it is, a[i] is placed into the merged[] array at index k and the index i is incremented.
            Control would then pass back out of this if/else block, index k will be incremented,
            and then pass back to the top of the while loop.
        */
        if(a[i] <= a[j])
        {
            merged[k] = a[i];
            i++;
        }

        /*
            If a[i] is not less than or equal to a[j], the value of a[j] is placed into merged[] at index k.
            Index j is incremented and control passes out of the if/else block.
            Index k will be incremented and control will return to the top of the while loop.
        */
        else
        {
            merged[k] = a[j];
            j++;
        }

        /*
            This line increments the index k used to navigate the merged[] array.
            This incrementation happens with each sweep through the while loop.
        */
        k++;
    }

    //This while loop populates merged[] with the sorted contents of the left side of array a[].
    //It is activated in case the first while loop did not iterate all the way through the sub-array
    //governed by the index i.
    while (i <= mid)
    {
        merged[k] = a[i];
        i++;
        k++;
    }

    //This while loop populates merged[] with the sorted contents of the right side of array a[].
    //It is activated in case the first while loop did not iterate all the way through the sub-array
    //governed by the index j.
    while (j <= r)
    {
        merged[k] = a[j];
        j++;
        k++;
    }

    //This for loop repopulates a[] with the properly merged contents of merged[].
    for(i = l, k = 0; i <= r; i++, k++)
    {
        a[i] = merged[k];
    }
}

/*
    This is the sort function. It has a void return type.
    It accepts three arguments (or parameters): int a[], int left, and int right.
    int a[] is an integer array that will be sorted. It is presumed unsorted.
    int left is the leftmost (lowest) index of a[].
    int right is the rightmost (highest) index of a[].
*/
void sort(int a[], int left, int right)
{
    //This creates a variable mid and initializes it to 0.
    //mid will be used to house the midpoint of the array (a[]) to be sorted.
    int mid = 0;

    //This if statement checks to see if the value of left is less than right.
    if (left < right)
    {
        //If left is less than right, a mid point is calculated and stored in the variable mid.
        mid = (left + right)/2;
        //Sort calls itself recursively until left no longer is less than right.
        sort(a, left, mid);
        sort(a, mid + 1, right);
        merge(left, right, a);
    }
}

int main()
{
    int i;
    int a[32] = {55,12,4, 0,14,76,8,98,150,10,6, 201,32,16,45,9,39,28,110,95,67,21,87,72,3,1,11,54,75,40,90,2};

    sort(a,0,31);
    printf("The sorted array\n");
    //iterate through the array and print sorted array
    for (i = 0; i<=31;i++)
    {
        printf("%d\n", a[i]);
    }

    return 0;
}
