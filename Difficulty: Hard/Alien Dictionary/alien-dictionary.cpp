class Solution {
  public:
    bool dfs(int i, vector<vector<int>> & adj, vector<int> &visited, string &ans,vector<int>&pathvisited){
        visited[i]=1;
        pathvisited[i]=1;
        for(int j=0;j<adj[i].size();j++){
            int a=adj[i][j];
            if(!visited[a]){
                if(dfs(a,adj, visited, ans,pathvisited)){
                    return true;
                }
            }
                else if(pathvisited[a]){
                    return true;
                }
        }
        pathvisited[i]=0;
        ans+=(char)('a'+i);
        return false;
    }
    string findOrder(vector<string> &words) {
        // code here
        vector<vector<int>> adj(26);
        unordered_map<char,int>mpp;
        for(int i=0;i<words.size()-1;i++){
            string a=words[i];
            string b=words[i+1];
            if(a.size() > b.size() && a.substr(0, b.size()) == b){
        return "";  // invalid prefix case
    }
            for(int j=0;j<min(a.size(),b.size());j++){
                if(a[j]!=b[j]){
                    adj[a[j]-'a'].push_back(b[j]-'a');
                    break;
                }
            }
        }
        for(int i=0;i<words.size();i++){
            for(char a:words[i]){
                mpp[a]++;
            }
        }
        vector<int> pathvisited(26,0);
        vector<int> visited(26,0);
        string ans="";
        for(int i=0;i<26;i++){
            if(!visited[i] && mpp[i+97]!=0){
                if(dfs(i, adj, visited, ans,pathvisited)){
                    return "";
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};