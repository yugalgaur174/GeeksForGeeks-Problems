class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        vector<int> visited(adj.size()+1,0);
        queue<int> q;
        q.push(0);
        vector<int> ans;
        ans.push_back(0);
        visited[0]=1;
        while(!q.empty()){
            int a=q.front();
            q.pop();
            for(int i=0;i<adj[a].size();i++){
                if(!visited[adj[a][i]]){
                    q.push(adj[a][i]);
                    visited[adj[a][i]]=1;
                    ans.push_back(adj[a][i]);
                }
            }
        }
        return ans;
    }
};