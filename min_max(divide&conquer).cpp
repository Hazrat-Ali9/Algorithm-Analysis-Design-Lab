//Code

#include<iostream>
using namespace std;

class minmax
{
    private:
        int n, min, max;
        int a[20];
    public:
        void accept();
        void maxmin(int i, int j);
        void display();
};

void minmax::accept()
{
    cout<<"\nEnter the number of elements : ";
    cin>>n;
    cout<<"\nEnter the elements : \n";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"\nThe elements are : \n";
    display();
    max = a[0];
    min = a[0];
    maxmin(1, n-1);
    cout<<"\nThe minimum is : "<<min;
    cout<<"\nThe maximum is : "<<max;
    cout<<endl;
}

void minmax::maxmin(int i, int j)
{
    int max1, min1, mid;
    if(i==j)
    {
        max = min = a[i];
    }
    else
    {
        if(i == j-1)
        {
            if(a[i] < a[j])
            {
                max = a[j];
                min = a[i];
            }
            else
            {
                max = a[i];
                min = a[j];
            }
        }
        else
        {

            mid = (i+j)/2;
            maxmin(i, mid);
            max1 = max; 
            min1 = min;
            maxmin(mid+1, j);
            if(max < max1)
                max = max1;
            if(min > min1)
                min = min1;
        }
    }
}

void minmax::display()
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }
}

int main()
{
    minmax m;
    m.accept();
    return 0;
}

/*OUTPUT

safir@safir-Predator-PH315-51:~/Desktop/DAA codes$ g++ min_max.cpp
safir@safir-Predator-PH315-51:~/Desktop/DAA codes$ ./a.out

Enter the number of elements : 6

Enter the elements : 
4
2
3
7
9
8

The elements are : 
4	2	3	7	9	8	
The minimum is : 2
The maximum is : 9

*/

