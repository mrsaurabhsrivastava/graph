//https://practice.geeksforgeeks.org/problems/shortest-path-from-1-to-n/0
#include<iostream>
using namespace std;

int gMinEdges(int n) 
{
	int lNumEdge = 0;
	int l = n;
	while (l > 1) 
	{
		lNumEdge++;
		if (l % 3 == 0) 
			l = l / 3;
		else 
			l--;
	}
	return lNumEdge;
}

int main () 
{
	int lNumTests;
	cin>>lNumTests;
	for (int i = 0; i < lNumTests; i++) 
	{
		int n;
		cin>>n;
		cout<<gMinEdges(n)<<"\n";
	}
}
