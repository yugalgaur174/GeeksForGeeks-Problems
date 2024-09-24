//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    long long ans=-1;
    void findd(long long low,long long high, long long x, vector<long long> & v){
        if(low>high) return;
        long long mid=(low+high)/2;
        if(v[mid]==x) {
            ans=mid;
            return;
        }   
        else if(v[mid]<x){
            ans=mid;
            findd(mid+1,high,x,v);
        }
        else{
            findd(low,mid-1,x,v);
        }
    }
    int findFloor(vector<long long> &v, long long n, long long x) {

        // Your code here
        long long low=0;
        long long high=n-1;
        findd(low,high,x,v);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    long long t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;
        long long x;
        cin >> x;

        vector<long long> v;

        for (long long i = 0; i < n; i++) {
            long long temp;
            cin >> temp;
            v.push_back(temp);
        }
        Solution obj;
        cout << obj.findFloor(v, n, x) << endl;
    }

    return 0;
}
// } Driver Code Ends