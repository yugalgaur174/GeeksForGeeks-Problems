//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int cost(int n,vector<int>& height, vector<int>& arr){
        if(n==0) return 0;
        int left=INT_MAX, right=INT_MAX;
        if(arr[n]!=-1){
            return arr[n];
        }
        
            
            left=cost(n-1,height,arr)+abs(height[n]-height[n-1]);
            
        
        if(n>1){
            
            
                right=cost(n-2,height,arr)+abs(height[n]-height[n-2]);
                
            
        }
        return arr[n]=min(left,right);
    }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> arr(n,-1);
        return cost(n-1,height,arr);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends