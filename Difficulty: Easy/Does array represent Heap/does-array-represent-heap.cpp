//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        for(int i=0;i<n/2;i++){
            if(arr[i]>=arr[2*i+1]) {
                if(2*i+1+1<=n){
                    if(arr[2*i+1+1]<=arr[i]){
                        continue;
                    }
                    else{
                        return false;
                    }
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}

// } Driver Code Ends