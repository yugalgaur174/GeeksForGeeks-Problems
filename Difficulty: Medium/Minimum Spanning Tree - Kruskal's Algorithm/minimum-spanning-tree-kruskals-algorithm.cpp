// User function Template for C++
class Disjointset{
    vector<int> size, parent;
    public:
        Disjointset(int n){
            size.resize(n);
            parent.resize(n);
            for(int i=0;i<n;i++){
                parent[i]=i;
                size[i]=1;
            }
        }
        
        int findpar(int node){
            if(node==parent[node]){
                return node;
            }
            return parent[node]=findpar(parent[node]);
        }
        void unionbysize(int u, int v){
            int uu=findpar(u);
            int vv=findpar(v);
            if(uu==vv){
                return;
            }
            if(size[uu]<size[vv]){
                parent[uu]=vv;
                size[vv]+=size[uu];
            }else {
            parent[vv] = uu;
            size[uu] += size[vv];
        }
        }
};
class Solution {
  public:
    static bool custom(vector<int> a, vector<int> b){
        int c=a[2];
        int d=b[2];
        return c<d;
    }
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        // vector<vector<pair<int, pair<int, int>>> edge;
        // for(int i=0;i<edges.size();i++){
            
        // }
        sort(edges.begin(),edges.end(), custom);
        int ans=0;
        Disjointset ds(V);
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            int c=edges[i][2];
            
            if(ds.findpar(a)!=ds.findpar(b)){
                ans+=c;
                ds.unionbysize(a,b);
            }
        }
        return ans;
    }
};