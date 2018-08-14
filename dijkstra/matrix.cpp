//https://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<string>
#include<cstring>
#include<list>
#define FOR(i,n) for(int i = 0; i < n; i++)
#define V 9 

using namespace std;
void gDijkstras(int graph[V][V], int xSource) 
{
	int lDist[V];
	bool lDone[V];
	memset(lDone, 0, sizeof(lDone));
	FOR(i, V) 
	{
		if (i == xSource) 
			lDist[i] = 0;
		else 
			lDist[i] = INT_MAX;
	}
	
	list<int> lNodes;
	lNodes.push_back(xSource) ;
	while(!lNodes.empty()) 
	{
		int lFront = lNodes.front();
		lNodes.pop_front();
		if (lDone[lFront]) 
			continue;		
		int lNodeDis = lDist[lFront];
		int lMin = INT_MAX;
		int lMinIndex = -1;
		FOR(j, V) 
		{
			if(graph[lFront][j] != 0) 
			{
				if (lDist[j] > graph[lFront][j]+lNodeDis) 
					lDist[j] = graph[lFront][j] + lNodeDis;
				
					if (!lDone[j] && lDist[j] < lMin) 
					{
						lMin = lDist[j];
						lMinIndex = j;
					}
			}
		}
		if (lMinIndex != -1) 
			lNodes.push_back(lMinIndex);
		lDone[lFront] = true;
	}
	FOR(i, V)
	{ 
		cout<<i<<" "<<lDist[i]<<"\n";
	}
}


int main() 
{
	int graph[V][V] = {   {0,  4,  0,  0,  0,  0,  0,  8,  0},
	                      {4,  0,  8,  0,  0,  0,  0, 11,  0},
	                      {0,  8,  0,  7,  0,  4,  0,  0,  2},
	                      {0,  0,  7,  0,  9, 14,  0,  0,  0},
	                      {0,  0,  0,  9,  0, 10,  0,  0,  0},
	                      {0,  0,  4, 14, 10,  0,  2,  0,  0},
	                      {0,  0,  0,  0,  0,  2,  0,  1,  6},
	                      {8, 11,  0,  0,  0,  0,  1,  0,  7},
	                      {0,  0,  2,  0,  0,  0,  6,  7,  0}
	                     };
	gDijkstras(graph, 0);
}
