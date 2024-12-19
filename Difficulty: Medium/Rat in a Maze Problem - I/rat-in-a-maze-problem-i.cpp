//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void find(int i, int j, vector<vector<int>>& mat, vector<string>& ans, string a){
         int n = mat.size();
        if (i == n - 1 && j == n - 1) {
            ans.push_back(a);
            return;
        }
        if(i<0 || j<0 || i>mat.size()-1 || j>mat.size()-1 || mat[i][j]==0){
            return;
        }
        mat[i][j]=0;
        find(i+1,j,mat, ans,a+"D");
        find(i-1,j,mat, ans,a+"U");
        find(i,j+1,mat, ans,a+"R");
        find(i,j-1,mat, ans,a+"L");
        mat[i][j]=1;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // code here
        vector<string> ans;
        if(mat[0][0]==0) return ans;
         if (mat.empty() || mat[0][0] == 0 || mat[mat.size() - 1][mat.size() - 1] == 0) {
            return ans; 
        }
        string a="";
        find(0,0,mat, ans,a);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends