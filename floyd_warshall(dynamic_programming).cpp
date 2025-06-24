#include <iostream> 
using namespace std; 

#define n 4
#define INF 9999

class floyd_warshall
{
    private:
        int ch;
    public:
        void class_main();
        void warshall(int W[][n]);
        void display(int d[][n]);
};

void floyd_warshall::class_main()
{
    int G[n][n] = { {0, 5, INF, INF},  
                    {50, 0, 15, 5},  
                    {30, INF, 0, 15},  
                    {15, INF, 5, 0}  
                };
    cout<<"\nThe graph is (D0) : \n";
    display(G);
    cout<<"\n1. Display all the distance graphs from D1 to D"<<n<<"\n2. Display the final shortest distance graph D"<<n;
    cout<<"\nEnter your choice : ";
    cin>>ch;
    cout<<"\nShortest Path between all vertices using Floyd Warshall's Algorithm is : \n";
    warshall(G);    
}

void floyd_warshall::warshall(int G[][n])
{
    int d[n][n], i, j, k;  

    for (i = 0; i < n; i++)  
        for (j = 0; j < n; j++)  
            d[i][j] = G[i][j];

    for (k = 0; k < n; k++)  
    {  
        for (i = 0; i < n; i++)  
        {  
            for (j = 0; j < n; j++)  
            {  
                if ( d[i][j] > (d[i][k] + d[k][j]) )  
                    d[i][j] = d[i][k] + d[k][j];  
            }  
        }
        if(ch==1)
        {
            cout<<"D"<<k+1<<" : \n";
            display(d);
        }  
    }
    if(ch==2)
    {
        display(d);
    }
}  

void floyd_warshall::display(int d[][n])  
{    
    for (int i = 0; i < n; i++)  
    {  
        for (int j = 0; j < n; j++)  
        {  
            if (d[i][j] == INF)  
                cout<<"\t"<<"INF";  
            else
                cout<<"\t"<<d[i][j];  
        }  
        cout<<endl;  
    }  
    cout<<endl;
}  
  
int main()  
{  
    floyd_warshall w;
    w.class_main();
    return 0;  
}  
  
/*OUTPUT
C:\Users\Admin\Downloads\DAA Codes>g++ warshall.cpp
C:\Users\Admin\Downloads\DAA Codes>a
The graph is (D0) :
0       5       INF     INF
50      0       15      5
30      INF     0       15
15      INF     5       0
1. Display all the distance graphs from D1 to D4
2. Display the final shortest distance graph D4
Enter your choice : 2
Shortest Path between all vertices using Floyd Warshall's Algorithm is :
0       5       15      10
20      0       10      5
30      35      0       15
15      20      5       0  
*/