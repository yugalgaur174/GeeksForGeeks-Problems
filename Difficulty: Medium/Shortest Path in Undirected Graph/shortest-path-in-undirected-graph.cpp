class Solution {
  public:
    
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        vector<int> ans(adj.size(),-1);
        vector<int> visited(adj.size(),0);
        queue<pair<int, int>> q;
        q.push({src,0});
        visited[src]=1;
        while(!q.empty()){
            int a=q.front().first;
            int level=q.front().second;
            q.pop();
            ans[a]=level;
            for(int i=0;i<adj[a].size();i++){
                int b=adj[a][i];
                if(!visited[b]){
                    visited[b]=1;
                    q.push({b,level+1});
                }
            }
        }
        return ans;
    }
};