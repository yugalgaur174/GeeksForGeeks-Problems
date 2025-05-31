
class Solution {
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> visited(V,0);
        vector<vector<int>> ans;
        for(int i=0;i<V;i++){
            if(visited[i]==1){
                continue;
            }
            queue<int> q;
            vector<int> z;
            visited[i]=1;
            q.push(i);
            while(!q.empty()){
                int a=q.front();
                q.pop();
                z.push_back(a);
                for(int j=0;j<adj[a].size();j++){
                    if(!visited[adj[a][j]]){
                        visited[adj[a][j]]=1;
                        q.push(adj[a][j]);
                    }
                }
            }
            sort(z.begin(), z.end());
            ans.push_back(z);
        }
        return ans;
    }
};
