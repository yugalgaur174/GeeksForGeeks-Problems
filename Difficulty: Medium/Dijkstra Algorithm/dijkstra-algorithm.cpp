// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<int> ans(V,INT_MAX);
        ans[src]=0;
        vector<vector<pair<int, int>>> adj(V);
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            int c=edges[i][2];
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }
        set<pair<int, int>> st;
        st.insert({0,src});
        while(!st.empty()){
            auto i=*(st.begin());
            int node=i.second;
            int dist=i.first;
            st.erase(i);
            for(auto it: adj[node]){
                 int adjnode=it.first;
                 int edge=it.second;
                 if(dist+edge<ans[adjnode]){
                     if(ans[adjnode]!=INT_MAX){
                         st.erase({ans[adjnode],adjnode});
                     }
                     ans[adjnode]=dist+edge;
                     st.insert({ans[adjnode],adjnode});
                 }
            }
        }
        return ans;
    }
};