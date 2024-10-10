//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        sort(arr,arr+n,[&](Item a,Item b){
            return (double)a.value/a.weight>(double)b.value/b.weight;
        });
        double profit=0.00;
        // return 0.00;
        int i=0;
        while(w>0 && i<n){
            if(w-arr[i].weight>=0){
                w-=arr[i].weight;
                profit+=arr[i].value;
            }
            else{
                profit+=((double)w/arr[i].weight)*(double)arr[i].value;
                w=0;
                break;
            }
            i++;
        }
        return profit;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends