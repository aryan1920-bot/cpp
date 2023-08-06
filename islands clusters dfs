#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//using dfs to find number of clusters of islands in a map 
//map is matrix of 0 and 1 with 1 representing islands

void dfsislands(vector<vector<int>>& map,int rows,int columns,int i,int j)
{
    if(i>=rows || j>=columns || i<0 || j<0 || map[i][j]==0)
    {
        return;
    }
    map[i][j]=0;
    // if(i+1<rows && map[i+1][j]==1)
    dfsislands(map,rows,columns,i+1,j);
    // if(i-1>=0 && map[i-1][j]==1)
    dfsislands(map,rows,columns,i-1,j);
    // if(j+1<columns && map[i][j+1]==1)
    dfsislands(map,rows,columns,i,j+1);
    // if(j-1>=0 && 0smap[i][j-1]==1)
    dfsislands(map,rows,columns,i,j-1);

}


int main()
{
    vector<vector<int>> islands={{1,1,0,0,0},{0,1,0,0,1},{1,0,0,1,1},{0,0,0,0,0},{1,0,1,0,0}};
    int m=islands.size(); //rows
    int n=islands[0].size(); //columns
    int count=0; 
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {  
            if(islands[i][j]==1)
            {
                count++;
                dfsislands(islands,m,n,i,j);
            }

        }
    }
    cout<<count<<endl;


}
