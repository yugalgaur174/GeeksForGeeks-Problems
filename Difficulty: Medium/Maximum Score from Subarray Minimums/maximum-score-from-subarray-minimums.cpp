//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to find pair with maximum sum
    int pairWithMaxSum(vector<int> &arr) {
        // Your code goes here
        int a=arr[0];
        int max=0;
        int b=arr[1];
        for(int i=1;i<arr.size()-1;i++){
            if(a+b<arr[i]+arr[i+1]){
                a=arr[i];
                b=arr[i+1];
            }
        }
        return a+b;
        // int a=max(arr[0],arr[1]);
        // int b=min(arr[0],arr[1]);
        // if(arr.size()<2) return arr[0];
        // for(int i=2;i<arr.size();i++){
        //     if(arr[i]>a){
        //         b=a;
        //         a=arr[i];
        //     }
        //     else if(arr[i]>b){
        //         b=arr[i];
        //     }
        // }
        // return b;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        cout << ob.pairWithMaxSum(nums) << endl;
    }
    return 0;
}

// } Driver Code Ends