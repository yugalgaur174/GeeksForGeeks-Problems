//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node, vector<vector<int>> & list, vector <int>& vis){
        vis[node]=1;
        for(auto & it:list[node]){
            if(!vis[it]){
                dfs(it,list, vis);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here/
        int n=V;
        vector<vector<int>> list(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && adj[i][j]==1){
                    list[i].push_back(j);
                }
            }
        }
        vector<int> vis(V,0);
        // int start;
        int cnt=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,list,vis);
                cnt++;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends