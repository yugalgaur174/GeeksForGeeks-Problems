class Solution {
  public:
    int wordLadderLength(string startWord, string targetWord,
                         vector<string>& wordList) {
        // Code here
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string, int>>q;
        q.push({startWord,1});
        st.erase(startWord);
        while(!q.empty()){
            string word=q.front().first;
            int level=q.front().second;
            q.pop();
            if(word==targetWord){
                return level;
            }
            for(int i=0;i<word.size();i++){
                char orig=word[i];
                for(char j='a';j<='z';j++){
                    word[i]=j;
                    if(st.find(word)!=st.end()){
                        q.push({word,level+1});
                        st.erase(word);
                    }
                }
                word[i]=orig;
            }
        }
        return 0;
        
    }
};