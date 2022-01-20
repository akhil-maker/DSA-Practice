#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	int visited[505][505];
	
	int dfs(int x, int y, vector<vector<int>> &grid, int mndist){
	    int mn = INT_MAX;
	    visited[x][y] = 1;
	    if(x<0 || y<0 || x>=grid.size() || y>=grid.size()) return INT_MAX;
	    if(x==grid.size()-1 && y==grid.size()-1) return mndist;
	    int addx[] = {-1, 0, 1, 0};
	    int addy[] = {0, 1, 0, -1};
	    cout<<x<<" "<<y<<" "<<((mndist!=INT_MAX)?(mndist):(-1))<<endl;
	    for(int i=0; i<4; i++){
	        int p = x+addx[i], q = y+addy[i];
	        if(p>=0 && q>=0 && p<grid.size() && q<grid.size() && visited[p][q]==0)
	            mn = min(mn, dfs(p, q, grid, mndist+grid[p][q]));
	    }
        visited[x][y] = 0;
        cout<<"mn="<<mn<<endl;
	    return mn;
	}
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int mn = 0;
        for(int i=0; i<505; i++)
            for(int j=0; j<505; j++)
                visited[i][j] = 0;
        mn = dfs(0, 0, grid, grid[0][0]);
        return mn;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends