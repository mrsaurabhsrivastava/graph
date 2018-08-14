
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<cstring>
#define FOR(i,n) for(int i = 0; i < n; i++)
#define MAX 100

using namespace std;

void gDFS(int i, int j, int A[MAX][MAX], int N, int M, bool xVisited[MAX][MAX]) 
{
	xVisited[i][j] = true;
	if (i >= 0 && i < N && j >= 0 && j < M)
	{
		for (int ii = -1; ii <= 1; ii++) 
		{
			for (int jj = -1; jj <=1; jj++) 
			{
				if (i+ii >= 0 && j+jj >=0)
				{
					if (xVisited[i+ii] [j+jj] != true) 
					{ 
						xVisited[i+ii][j+jj] = true; 
						if (A[i+ii][j+jj] != 0)
						{
							gDFS(i+ii, j+jj, A, N, M, xVisited);
						}
					}
				}
			}
		}				
	} 	
}

int gNumIslands(int A[MAX][MAX], int N, int M) 
{
	int count = 0;
	bool lVisited[MAX][MAX];
	memset(lVisited, 0, sizeof(lVisited));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++) 	
		{
			if (A[i][j] != 0 && lVisited[i][j] == false) 
			{
				gDFS(i,j,A,N,M,lVisited);
				count++;
			}
		}
	}	
	return count;	
}

int main() 
{
	std::ios_base::sync_with_stdio(false);
	int Matrix[MAX] [MAX] = {{1,1,0,0,0}, 
		            	 {0,1,0,0,1},
		      	  	 {1,0,0,1,1}, 
		      	 	 {0,0,0,0,0},
		      	     	 {1,0,1,0,1}};
	cout<<gNumIslands(Matrix, 5, 5);                       
}
