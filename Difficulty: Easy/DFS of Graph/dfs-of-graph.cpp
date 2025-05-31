class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int> visited(adj.size()+1,0);
        stack<int> q;
        q.push(0);
        vector<int> ans;
        while(!q.empty()){
            int a=q.top();
            q.pop();
            if(visited[a]){
                continue;
            }
            ans.push_back(a);
            visited[a]=1;
            for(int i=adj[a].size()-1;i>=0;i--){
                if(!visited[adj[a][i]]){
                    q.push(adj[a][i]);
                }
            }
        }
        return ans;
    }
};