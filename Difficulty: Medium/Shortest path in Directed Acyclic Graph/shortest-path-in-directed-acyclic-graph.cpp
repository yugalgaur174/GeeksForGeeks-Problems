// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<int> visited(V,0);
        vector<vector<pair<int, int>> >adj(V);
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            int c=edges[i][2];
            adj[a].push_back({b,c});
        }
        vector<int> ans(V,-1);
        queue<int> q;
        visited[0]=1;
        ans[0]=0;
        q.push(0);
        while(!q.empty()){
            int a=q.front();
            int b=ans[a];
            q.pop();
            for(int i=0;i<adj[a].size();i++){
                int c=adj[a][i].first;
                int d=adj[a][i].second;
                if(!visited[c] || (ans[c]>-1 && d+b<ans[c] )){
                    q.push(c);
                    visited[c]=1;
                    
                    ans[c]=d+b;
                }
            }
        }
        return ans;
    }
};
