#include<iostream>
#include<vector>
#include<stack>
#include<list>

using namespace std;

class graph 
{
	public: 
	graph(int xV) 
	:dV(xV)
	{
		dAdj = new list<int>[xV];
	}
	
	void mAddEdge(int v, int w) 
	{
		dAdj[v].push_back(w);
	}
	
	void mTopologicalSort();
	
	private: 
	int dV; //Number of vertices
	list<int>* dAdj; //List of list having edges 
	void mTopologicalSortInternal(int xNode, vector<bool>& xVisited, stack<int>& xStack);
	
};

void graph::mTopologicalSort() 
{
	vector<bool> lVisited(dV, false);
	stack<int> lStack;
		
	for (int i = 0; i < dV; i++) 
	{
		if (!lVisited[i]) 
		{
			mTopologicalSortInternal(i, lVisited, lStack); 	
		}
	}
	
	while (!lStack.empty()) 
	{
		int lEl = lStack.top();
		lStack.pop();
		cout<<lEl<<" ";
	}
	return;
}

void graph::mTopologicalSortInternal(int xNode, vector<bool>& xVisited, stack<int>& xStack)
{
	
	if (!xVisited[xNode]) 
	{
		list<int>::const_iterator it = dAdj[xNode].begin();
		while(it != dAdj[xNode].end())
		{
			if (!xVisited[*it]) 
			{
				mTopologicalSortInternal(*it, xVisited, xStack);
			}
			it++;	
		}
		xVisited[xNode] = true;
		xStack.push(xNode);
	}
	return;
}

int main () 
{
	graph gr(6);
	gr.mAddEdge(5,0);
	gr.mAddEdge(5,2);
	gr.mAddEdge(4,0);
	gr.mAddEdge(4,1);
	gr.mAddEdge(2,3);
	gr.mAddEdge(3,1);
	gr.mTopologicalSort();
}
