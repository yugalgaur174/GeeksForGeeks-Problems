class Solution {
  public:
    bool dfs(int i, vector<int>& visited, vector<int>&pathvisited,vector<vector<int>> adj){
        visited[i]=1;
        pathvisited[i]=1;
        for(int j=0;j<adj[i].size();j++){
            int a=adj[i][j];
            if(!visited[a]){
                if(dfs(a,visited, pathvisited,adj)){
                    return true;
                }
            }
            else if(pathvisited[a]){
                return true;
            }
        }
        pathvisited[i]=0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            adj[a].push_back(b);
        }
        vector<int> visited(V,0);
        vector<int> pathvisited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,visited, pathvisited,adj)){
                    return true;
                }
            }
        }
        return false;
    }
};