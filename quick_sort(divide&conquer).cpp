//Code

#include<iostream>
#include<time.h>
using namespace std;

class quick_sort
{
    private:
        int n,z;
        int A[20];
    public:
        void swap(int* a, int* b);
        void accept();
        void display(int arr[]);
        void quicksort(int arr[], int low, int high);
        int partition(int arr[], int low, int high);
};

void quick_sort::swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}

void quick_sort::accept()
{
    cout<<"\nEnter the number of elements : ";
    cin>>n;
    cout<<"\nEnter the elements : \n";
    for(z=0;z<n;z++)
        cin>>A[z];
    cout<<"\nUnsorted elements are : \n";
    display(A);
    time_t x, y;
    time(&x);
    quicksort(A,0,n-1);
    time(&y);
    double time_taken = double(y-x);
    cout<<"\nTime take by function : "<<fixed<<time_taken;
    cout<<"\nSorted elements are : \n";
    display(A);
}

void quick_sort::display(int arr[])
{
    for(z=0;z<n;z++)
        cout<<A[z]<<"\t";
    cout<<endl;
}

void quick_sort::quicksort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(arr, low, high);  
  
        // Separately sort elements before  
        // partition and after partition  
        quicksort(arr, low, pi - 1);  
        quicksort(arr, pi + 1, high);  
    }  
} 
/* This function takes last element as pivot, places  
the pivot element at its correct position in sorted  
array, and places all smaller (smaller than pivot)  
to left of pivot and all greater elements to right  
of pivot */
int quick_sort::partition(int arr[], int low, int high)  
{  
    int pivot = arr[high]; // pivot  
    int i = (low - 1); // Index of smaller element  
  
    for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (arr[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
} 

int main()
{
    quick_sort q;
    q.accept();
    return 0;
}

/*OUTPUT

safir@safir-Predator-PH315-51:~/Desktop/DAA codes$ g++ quick.cpp
safir@safir-Predator-PH315-51:~/Desktop/DAA codes$ ./a.out

Enter the number of elements : 5

Enter the elements : 
4
2
7
9
8

Unsorted elements are : 
4	2	7	9	8	

Sorted elements are : 
2	4	7	8	9
*/
