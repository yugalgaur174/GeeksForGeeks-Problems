// User function template for C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        int n=dist.size();
        int mod=1e8;
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][via]!=mod && dist[via][j]!=mod && dist[i][j]>(dist[i][via]+dist[via][j])){
                        dist[i][j]=dist[i][via]+dist[via][j];
                    }
                }
            }
        }
    }
};