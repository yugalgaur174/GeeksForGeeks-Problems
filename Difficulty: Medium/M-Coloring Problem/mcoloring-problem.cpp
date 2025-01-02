//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool issafe(int node, vector<int> color, vector<vector<int>>graph, int v, int i){
        for(int k=0;k<v;k++){
            if(k!=node && graph[node][k]==1&& color[k]==i){
                return false;
            }
        }
        return true;
    }
    bool solve(int node, vector<int> color, int m, int v, vector<vector<int> > graph){
        if(node==v)return true;
        for(int i=1;i<=m;i++){
            if(issafe(node, color, graph, v, i)){
                color[node]=i;
                if(solve(node+1, color, m, v, graph)){
                    return true;
                }
                color[node]=0;
            }
        }
        return false;
    }
    
    bool graphColoring(int v, vector<pair<int, int>>& edge, int m) {
        // code here
        vector<vector<int>>graph(v, vector<int>(v,0));
        for(int i=0;i<edge.size();i++){
            graph[edge[i].first][edge[i].second]=1;
            graph[edge[i].second][edge[i].first]=1;
        }
        vector<int> color(v,0);
        if(solve(0,color, m, v,graph))return true;
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m;
        cin >> n;
        cin.ignore(); // Ignore newline after reading n
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number); // Populate the array with edge values
        }
        cin >> m;
        cin.ignore(); // Ignore newline after reading m

        int edges_count = arr.size();
        vector<pair<int, int>> edges(edges_count /
                                     2); // Correct size of the edges vector

        for (int i = 0; i < edges_count; i += 2) {
            int l1 = arr[i];
            int l2 = arr[i + 1];
            edges[i / 2] = {l1, l2}; // Properly assign the pair
        }

        Solution ob;
        cout << (ob.graphColoring(n, edges, m) ? "true" : "false")
             << "\n~\n"; // Call the graph coloring function
    }
    return 0;
}

// } Driver Code Ends