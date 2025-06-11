// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int, int>> q;
        vector<int> mark(99999,-1);
        q.push({0,start});
        mark[start]=0;
        int mod=100000;
        while(!q.empty()){
            int a=q.front().first;
            int b=q.front().second;
            q.pop();
            if(b==end){
                return a;
            }
            for(int i=0;i<arr.size();i++){
                int c=arr[i];
                int d=b*arr[i];
                d=d%mod;
                if(mark[d]==-1){
                    q.push({a+1,d});
                    mark[d]=a+1;
                }
            }
        }
        return -1;
    }
};
