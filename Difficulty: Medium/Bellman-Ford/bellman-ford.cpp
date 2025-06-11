// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> weight(V,INT_MAX);
        weight[src]=0;
        for(int i=0;i<V-1;i++){
            for(int j=0;j<edges.size();j++){
                int a=edges[j][0];
                int b=edges[j][1];
                int c=edges[j][2];
                if(weight[a]!=INT_MAX && weight[a]+c<weight[b]){
                    weight[b]=weight[a]+c;
                }
            }
        }
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            int c=edges[i][2];
            if(weight[a]!=INT_MAX &&weight[a]+c<weight[b]){
                return {-1};
            }
        }
        for(int i=0;i<V;i++){
            if(weight[i]==INT_MAX){
                weight[i]=1e8;
            }
        }
        return weight;
    }
};
