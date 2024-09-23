//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr, int k) {
        // Your code here
        map<int,int> mpp;
        int n=arr.size();
        int sum=0;
        int maxlen=0;
        for(int i=0;i<n;i++){
            sum=arr[i]+sum;
            if(sum==0){
                maxlen=max(maxlen,i+1);
            }
            else{
                if(mpp.find(sum)!=mpp.end()){
                    maxlen=max(maxlen,i-mpp[sum]);
                }
                else{
                    mpp[sum]=i;
                }
            }
        }
        return maxlen;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i) {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}

// } Driver Code Ends