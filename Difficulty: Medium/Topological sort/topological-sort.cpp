class Solution {
  public:
    void dfs(int i, vector<int>& visited, vector<vector<int>>& adj, stack<int> & ans){
        visited[i]=1;
        for(auto &it:adj[i]){
            if(!visited[it]){
                dfs(it,visited, adj, ans);
            }
        }
        ans.push(i);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> visited(V,0);
        vector<int> ans;
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            adj[a].push_back(b);
        }
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i, visited, adj, st);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};