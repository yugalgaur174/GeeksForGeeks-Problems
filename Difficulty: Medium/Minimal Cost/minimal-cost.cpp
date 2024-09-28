//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // int cost(int n,int k,vector<int>arr,vector<int>& mark){
    //     if(n==0) return 0;
    //     if(mark[n]!=-1) return mark[n];
    //     int ans=INT_MAX;
    //     for(int i=1;i<=k;i++){
    //         if(n-i>=0){
    //             ans=min(ans,(cost(n-i,k,arr,mark)+abs(arr[n]-arr[n-i])));
    //         }
    //     }
    //     return mark[n]=ans;
    // }
    // int minimizeCost(int k, vector<int>& arr) {
    //     // Code here
    //     vector<int>mark(arr.size(),-1);
    //     int n=arr.size();
    //     return cost(n-1,k,arr,mark);
        
    // }
    
    int minimizeCost(int k, vector<int>& arr) {
    //     // Code here
        int n=arr.size();
        int dp[n];
        dp[0]=0;
        for(int i=1;i<n;i++){
            int minsteps=INT_MAX;
            for(int j=1;j<=k;j++){
                if(i-j>=0){
                    
                int jump=dp[i-j]+abs(arr[i]-arr[i-j]);
                minsteps=min(minsteps,jump);
                }
            }
            dp[i]=minsteps;
        }
        return dp[n-1];
        // return cost(n-1,k,arr,mark);
    }
    
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends