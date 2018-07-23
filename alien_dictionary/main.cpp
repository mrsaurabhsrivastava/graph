#include<iostream>
#include<vector>
#include<list>
#include<stack>

using namespace std;

class graph 
{
	public:
	graph(int xNumChar)
	:dNumChar(xNumChar)
	{
		dAdj = new list<int> [xNumChar];
	}
	
	void mAddEdge(int v, int w);
	void mTopologicalSort();
	private: 
	int dNumChar;
	list<int>* dAdj;
	void mTopologicalSortInternal(int xNode, vector<bool>& xVisited, stack<int>& xStack);
};

void graph::mAddEdge(int v, int w) 
{
	dAdj[v].push_back(w);	
}

void graph::mTopologicalSortInternal(int xNode, vector<bool>& xVisited, stack<int>& xStack) 
{
	if (!xVisited[xNode]) 
	{
		xVisited[xNode] = true;
		list<int>::const_iterator it = dAdj[xNode].begin();
		while (it != dAdj[xNode].end()) 
		{
			if (!xVisited[*it]) 
			{
				mTopologicalSortInternal(*it, xVisited, xStack);
			}
			it++;	
		}
		xStack.push(xNode);
	}
	return;
}

void graph::mTopologicalSort() 
{
	vector<bool> lVisited(dNumChar, false);
	stack<int> lStack;
	for(int i = 0; i < dNumChar; i++) 
	{
		if (!lVisited[i]) 
			mTopologicalSortInternal(i, lVisited, lStack);
	}

	while(!lStack.empty()) 
	{
		int lEl = lStack.top();
		lStack.pop();
		cout<<char(lEl+'a')<<" ";
	}
	return;
}


int main () 
{
	graph gr(4);
	vector<string> lDict = {"baa", "abcd", "abca", "cab", "cad"};
	for (int i = 0; i < lDict.size()-1; i++) 
	{
		for (int j = 0; j < min(lDict[i].size(), lDict[i+1].size());j++)
		{
			if (lDict[i][j] != lDict[i+1][j])
			{ 
				gr.mAddEdge(lDict[i][j]-'a', lDict[i+1][j]-'a');		
				break;
			}
		}
	}
	gr.mTopologicalSort();
}
