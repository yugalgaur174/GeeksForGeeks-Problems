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
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // for(int i=0;i<adj[src].size();i++){
        //     pq.push({adj[src][i].second, adj[src][i].first});
        // }
        pq.push({0,src});
        while(!pq.empty()){
            int a=pq.top().first;
            int b=pq.top().second;
            pq.pop();
            for(int i=0;i<adj[b].size();i++){
                int c=adj[b][i].first;
                int d=adj[b][i].second;
                if(a+d<ans[c]){
                    ans[c]=a+d;
                    pq.push({ans[c],c});
                }
            }
        }
        return ans;
    }
};