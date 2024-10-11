//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        vector<pair<pair<int,int>, int>> data;
        for(int i=0;i<n;i++){
            data.push_back({{start[i],end[i]},i});
            
        }
        sort(data.begin(),data.end(),[&](pair<pair<int,int>, int>a,pair<pair<int,int>, int>b){
            return a.first.second<b.first.second;
        });
        
        int freetime=-1;
        int ans=0;
        for(auto& it:data){
            if(it.first.first>freetime){
                freetime=it.first.second;
                ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends