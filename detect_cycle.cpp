
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<string>
#include<cstring>
#include<list>
#include<stack>
#define FOR(i,n) for(int i = 0; i < n; i++)

using namespace std;
class Graph
{
	int V;
	list<int>* adj;
	
	public: 
	Graph(int V);
	void addEdge(int v, int w);
	bool isCycle();
};

Graph::Graph(int V)
:V(V)
{
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) 
{
	adj[v].push_back(w);
}

bool Graph::isCycle() 
{
	bool lIsCycle = false;
	bool lArray[V];
	stack<int> lStack;
	stack<int> lCallStack;
	memset(lArray,0,sizeof(lArray));
	lStack.push(0);
	
	while(!lStack.empty()) 
	{
		int lCurrElement = lStack.top();
		lStack.pop();
		if (lCurrElement == INT_MIN) 
		{
			int top = lCallStack.top();
			lCallStack.pop();
			lArray[top] = false;
			continue;
		}
		lStack.push(INT_MIN);
		lCallStack.push(lCurrElement);
		lArray[lCurrElement] = true;
		list<int>::const_iterator it = adj[lCurrElement].begin();
		while(it != adj[lCurrElement].end()) 
		{
			if (lArray[*it] == true) 
				return true;
			lStack.push(*it);
			it++;		
		}		
	}	
	return false;
		
}

int main() 
{
	std::ios_base::sync_with_stdio(false);
	Graph g(5);
	g.addEdge(0,1);	
	g.addEdge(0,2);	
	g.addEdge(1,3);	
	g.addEdge(2,4);
	g.addEdge(3,0);
	cout<<g.isCycle()<<endl;	
}
