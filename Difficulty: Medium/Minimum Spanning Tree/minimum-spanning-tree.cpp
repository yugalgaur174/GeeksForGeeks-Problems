class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        vector<int> visited(V,0);
        priority_queue<pair<int, int>, vector< pair<int, int>>, greater< pair<int, int>>> pq;
        vector<vector<pair<int, int>>> arr(V);
        pq.push({0,0});
        int ans=0;
        int n=0;
        while(!pq.empty()){
            int a=pq.top().first;
            int b=pq.top().second;
            pq.pop();
            if(visited[b]){
                continue;
            }
            visited[b]=1;
            ans+=a;
            for(auto &z:adj[b]){
                int c=z[0];
                int d=z[1];
                if(!visited[c]){
                    pq.push({d,c});
                    
                }
            }
        }
        return ans;
        
    }
};