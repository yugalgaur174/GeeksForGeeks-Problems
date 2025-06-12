// User function Template for C++
// User function Template for C++
class Disjointset{
    public:
    vector<int> size, parent;
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
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        Disjointset ds(n);
        int cnt=0;
        for(int i=0;i<edge.size();i++){
            int a=edge[i][0];
            int b=edge[i][1];
            if(ds.findpar(a)==ds.findpar(b)){
                cnt++;
            }
            else{
                ds.unionbysize(a,b);
            }
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i){
                c++;
            }
        }
        int ans=c-1;
        if(cnt>=ans){
            return ans;
        }
        return -1;
    }
};