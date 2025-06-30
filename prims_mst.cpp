#include<iostream>
using namespace std;

#define V 5

class prims
{
    private:
        int parent[V]; 
	    int key[V]; 
	    bool mstSet[V];
    public:
        int minKey(int key[], bool mstSet[]);
        void printMST(int parent[], int graph[V][V]);
        void MST(int graph[V][V]);
};

int prims::minKey(int key[], bool mstSet[]) 
{ 
	int min = INT_MAX, min_index; 

	for (int v = 0; v < V; v++) 
		if (mstSet[v] == false && key[v] < min) 
			min = key[v], min_index = v; 

	return min_index; 
}

void prims::printMST(int parent[], int graph[V][V]) 
{ 
	int mincost;
	mincost = 0;
	for (int i = 1; i < V; i++) 
	{
		mincost = mincost + graph[i][parent[i]];
		cout << "Edge ("<< parent[i] << ", " << i << ") "<< "with weight " << graph[i][parent[i]] << " ";
		cout << "is selected"<<endl;
	}
	cout<<endl<<"Minimum cost of the tree is "<<mincost<<endl; 
} 

void prims::MST(int graph[V][V]) 
{ 
	for (int i = 0; i < V; i++) 
		key[i] = INT_MAX, mstSet[i] = false; 

	key[0] = 0; 
	parent[0] = -1; 

	for (int count = 0; count < V - 1; count++) 
	{  
		int u = minKey(key, mstSet); 
 
		mstSet[u] = true; 

		for (int v = 0; v < V; v++) 

			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
				parent[v] = u, key[v] = graph[u][v]; 
	} 
	printMST(parent, graph); 
} 

int main()
{
    prims p;
    int graph[V][V] = { { 0, 2, 0, 6, 0 }, 
						{ 2, 0, 3, 8, 5 }, 
						{ 0, 3, 0, 0, 7 }, 
						{ 6, 8, 0, 0, 9 }, 
						{ 0, 5, 7, 9, 0 } }; 

	p.MST(graph);
    return 0;
}