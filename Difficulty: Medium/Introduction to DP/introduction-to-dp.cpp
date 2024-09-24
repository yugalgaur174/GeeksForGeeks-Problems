//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  const long long MOD = 1000000007;
    long long int topDown(int n) {
        // code here
        vector<long long> dp(n+1,-1);
        return fb(n,dp);
    }
    long long int fb(int n, vector<long long > &dp){
        if(n<=1) return n;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=(fb(n-1, dp) + fb(n-2, dp)) % MOD;
    }
    long long int bottomUp(int n) {
        // code here
        if(n<=1) return n;
        long long int prev2=0;
        long long int prev=1;
        for(int i=2;i<=n;i++){
            long long int curr=(prev + prev2) % MOD;
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends