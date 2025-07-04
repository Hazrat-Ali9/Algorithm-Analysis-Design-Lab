//Code

#include<iostream>
using namespace std;

class strassens
{
    private:
        int n,z;
        int a[2][2], b[2][2], c[2][2];
        int m1, m2, m3, m4, m5, m6, m7;
    public:
        void accept();
        void display(int arr[][2]);
        void operate();
};

void strassens::accept()
{
    cout<<"\nEnter 4 elements of first matrix : \n";
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            cin>>a[i][j];

    cout<<"\nEnter 4 elements of second matrix : \n";
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            cin>>b[i][j];

    cout<<"\nThe first matrix is : \n";
    display(a);
    cout<<"\nThe second matrix is : \n";
    display(b);
    operate();
    cout<<"\nThe resultant matrix after Strassen's multiplication is : \n";
    display(c);
}

void strassens::display(int arr[][2])
{
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<"\n";
    }
}

void strassens::operate()
{
    m1= (a[0][0] + a[1][1])*(b[0][0]+b[1][1]);
	m2= (a[1][0]+a[1][1])*b[0][0];
	m3= a[0][0]*(b[0][1]-b[1][1]);
	m4= a[1][1]*(b[1][0]-b[0][0]);
	m5= (a[0][0]+a[0][1])*b[1][1];
	m6= (a[1][0]-a[0][0])*(b[0][0]+b[0][1]);
	m7= (a[0][1]-a[1][1])*(b[1][0]+b[1][1]);

	c[0][0]=m1+m4-m5+m7;
	c[0][1]=m3+m5;
	c[1][0]=m2+m4;
	c[1][1]=m1-m2+m3+m6;
}

int main()
{
    strassens s;
    s.accept();
    return 0;
}

/*OUTPUT
safir@safir-Predator-PH315-51:~/Desktop/DAA codes$ g++ strassens.cpp
safir@safir-Predator-PH315-51:~/Desktop/DAA codes$ ./a.out

Enter 4 elements of first matrix : 
3
4
2
6

Enter 4 elements of second matrix : 
1
2
1
4

The first matrix is : 
3	4	
2	6	

The second matrix is : 
1	2	
1	4	

The resultant matrix after Strassen's multiplication is : 
7	22	
8	28	
*/
