#include <iostream>
#include <windows.h>

using namespace std;

void arrPrinter(int* array, int n);
void BubbleSorter(int* array, int n);
void CocktailSorter(int* array, int n);

int main()
{
    //array values
    int const arrayLen = 15;
    int array[arrayLen+1] = { 1,4,5,7,9,1,4,5,7,9,1,4,5,7,9,69696969 };
    int array2[arrayLen+1] = { 1,4,5,7,9,1,4,5,7,9,1,4,5,7,9,69696969 };

    //prints to console the array before and after the bubblesort
    arrPrinter(array, arrayLen);
    BubbleSorter(array, arrayLen);
    arrPrinter(array, arrayLen);

    cout << "cocktailsorter" << endl;

    arrPrinter(array2, arrayLen);
    CocktailSorter(array2, arrayLen);
    arrPrinter(array2, arrayLen);
    return 0;
}

//prints out all values in an array given its array and length
void arrPrinter(int* array, int n)
{
    for (int i = 0; i < n; i++) {
        cout << " : " << array[i];
    }
    cout << endl;
}

//Simple bubble sort where it loops through array and swaps the numbers if val1 is higher than val2
void BubbleSorter(int* array, int n)
{
    //Bail for single element or invalid indices
    if (n < 2)
        return;
    //Track if list is sorted
    bool sorted = false; //set to false to ensure the while loop starts up
    while (!sorted)
    {
        sorted = true;
        for (int i = 0; i < n - 1; ++i)
        {
            if (array[i] > array[i + 1])
            {
                swap(array[i], array[i + 1]);
                sorted = false;
            }
        }
    }
}

//an optimized bubblesorter 
void CocktailSorter(int* array, int n)
{
    //Bail for single element or invalid indices
    if (n < 2){ return; }
    //Track if list is sorted
    bool sorted = false; //set to false to ensure the while loop starts up
    while (!sorted)
    {
        sorted = true;
        for (int i = 0; i < n - 1; ++i)
        {
            if (array[i] > array[i + 1])
            {
                swap(array[i], array[i + 1]);
                sorted = false;
            }
        }        
        for (int k = n-1; k > 0; --k)
        {
            cout << k;
            if (array[k-1] > array[k])
            {
                swap(array[k], array[k + 1]);
                sorted = false;
            }
        }
    }
}
