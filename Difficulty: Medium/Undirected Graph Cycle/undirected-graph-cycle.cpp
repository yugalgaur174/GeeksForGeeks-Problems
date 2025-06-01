class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                queue<pair<int, int>> q;
                q.push(make_pair(i,-1));
                visited[i]=1;
                while(!q.empty()){
                    auto a=q.front();
                    q.pop();
                    int b=a.first;
                    int c=a.second;
                    for(int j=0;j<adj[b].size();j++){
                        if(!visited[adj[b][j]]){
                            visited[adj[b][j]]=1;
                            q.push(make_pair(adj[b][j],b));
                        }
                        else{
                            if(c!=adj[b][j]){
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};