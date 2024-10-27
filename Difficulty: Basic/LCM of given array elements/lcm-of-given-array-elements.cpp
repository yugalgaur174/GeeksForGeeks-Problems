//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
 

const int MOD = 1000000007;

// Helper function to calculate GCD
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate LCM under modulo
int lcmModulo(int a, int b) {
    return (int)((1LL * a * (b / gcd(a, b))) % MOD);
}

// Function to calculate LCM of array elements modulo 1000000007
int lcmOfArray(int N, int A[]) {
    int result = A[0];
    for (int i = 1; i < N; i++) {
        result = lcmModulo(result, A[i]);
    }
    return result;
}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>A[i];

        Solution ob;
        cout<<ob.lcmOfArray(N,A)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends