#include<iostream> 
#include<string.h>
using namespace std;
// Longest common sequence
int m, n;

class LCS{
	private:
		char x[20],y[20];
	public:
		void LCS_main();
		void LCS_length();
		void print_LCS(char b[20][20],char x[20],int i,int j);
};

void LCS::LCS_main()
{
	cout<<"\nEnter the string X : ";
	cin>>x;
	cout<<"\nEnter the string Y : ";
	cin>>y;
	LCS_length();
}

void LCS::LCS_length()
{
	m = strlen(x);
	n = strlen(y);

	for(int i=m-1;i>=0;i--)
	{
		x[i+1] = x[i];
	}
	for(int i=n-1;i>=0;i--)
	{
		y[i+1] = y[i];
	}
	
	char b[20][20];
	int c[20][20];

	for(int i=0;i<=m;i++)
	{
		c[i][0]=0;
	}

	for(int j=0;j<=n;j++)
	{
		c[0][j]=0;
	}

	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(x[i]==y[j])
			{
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = 'D';
			}
			else if(c[i-1][j]>=c[i][j-1])
			{
				c[i][j] = c[i-1][j];
				b[i][j] = 'U';
			}
			else
			{
				c[i][j] = c[i][j-1];
				b[i][j] = 'L';
			}
		}
	}
	cout<<"\nThe length of Longest Common Subsequence is : "<<c[m][n];;
	cout<<"\nThe Longest Common Subsequence is : ";
	print_LCS(b,x,m,n);
}

void LCS::print_LCS(char b[20][20],char x[20],int i,int j)
{
	if (i==0 || j==0)
		return;
	if(b[i][j]=='D')
	{
		print_LCS(b,x,i-1,j-1);
		cout<<x[i];	
	}
	else if(b[i][j]=='U')
	{
		print_LCS(b,x,i-1,j);
	}
	else
	{
		print_LCS(b,x,i,j-1);
	}
}

int main()
{
	LCS l;
	l.LCS_main();
}
/*OUTPUT
C:\Users\Admin\Downloads\DAA Codes>g++ LCS.cpp
C:\Users\Admin\Downloads\DAA Codes>a
Enter the string X : aggtab
Enter the string Y : gxtxayb
	The length of Longest Common Subsequence is : 4
The Longest Common Subsequence is : gtab
*/