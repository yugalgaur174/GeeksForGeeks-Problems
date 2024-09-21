//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int ans(int n){
        if(n==2) return 1;
        if(n==1) return 0;
        return (n-1)+ans(n-1);
    }
    long long count(int n) {
        // your code here
        int a=ans(n);
        return pow(2,a);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.count(n) << "\n";
    }

    return 0;
}

// } Driver Code Ends