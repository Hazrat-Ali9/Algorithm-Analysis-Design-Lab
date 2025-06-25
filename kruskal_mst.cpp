#include<iostream>
using namespace std;

class Edge 
{
	public :
		int u, v, wt;
};

class kruskal
{
    private:
        int n, m, mincost, i, j;
        int path[50];
	    Edge e[50];
    public:
        void accept();
        int check(Edge e, int path[50]);
        void MST();
};

void kruskal::accept()
{
    cout << "Enter the number of vertices in the graph: ";
	cin >> n;
	cout << "Enter the number of edges in the graph: ";
	cin >> m;
    for (i=0; i<m; i++) 
	{
		cout << "Enter vertices and weight of edge " << i+1 << endl;
		cout << "First vertex: ";
		cin >> e[i].u;
		cout << "Second vertex: ";
		cin >> e[i].v;
		cout << "Weight: ";
		cin >> e[i].wt;
		cout << endl;
	}
    MST();
}

int kruskal::check(Edge e, int path[50]) 
{
	int u = e.u, v = e.v;
	while (path[u] > 0)
		u = path[u];
	while (path[v] > 0)
		v = path[v];
	if (u != v) 
	{
		path[u] = v;
		return 1;
	}
	return 0;
}

void kruskal::MST()
{
    Edge t;
    for (i=0; i<=m-1; i++) 
	{
		for (j=0; j<m-i-1; j++) 
		{
			if (e[j].wt > e[j+1].wt) 
			{
				t = e[j];
				e[j] = e[j+1];
				e[j+1] = t;
			}
		}
	}
	for (i=1; i<=n; i++) 
	{
		path[i] = 0;
	}
	i = 0;		
	j = 0;		
	mincost = 0;
	while ((i!=n-1) && (j!=m)) 
	{
		if (check(e[j], path)) 
		{
			mincost = mincost + e[j].wt;
			i++;
			cout << "Edge ("<< e[j].u << ", " << e[j].v << ") "<< "with weight " << e[j].wt << " ";
			cout << "is selected"<<endl;
		} 
		j++;
	}
	cout<<endl<<"Minimum cost of the tree is "<<mincost<<endl;
}

int main()
{
    kruskal k;
    k.accept();
    return 0;
}