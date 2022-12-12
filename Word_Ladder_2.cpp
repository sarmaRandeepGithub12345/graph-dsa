unordered_map<string,int>umap;
vector<vector<string>>ans;
void dfs(string word ,vector<string>&seq,string beginWord){

if(word ==beginWord){
reverse(seq.begin(),seq.end());
ans.push_back(seq);
reverse(seq.begin(),seq.end());
return ;
}
int steps=umap[word];
for(int i=0;i<word.size();i++){
    char original =word[i];
    for(char ch='a';ch<='z';ch++){
        word[i]=ch;
       if(umap.find(word)!=umap.end() && umap[word]+1==steps){
           
           seq.push_back(word);
           dfs(word,seq,beginWord);
           seq.pop_back();
       }

    } word[i]=original;
}
}

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
       unordered_set<string>st(wordList.begin(),wordList.end());
       umap[beginWord]=1;
       queue<string>q;
       q.push(beginWord);
       st.erase(beginWord);
       while(!q.empty()){
           string tp=q.front();
           int steps=umap[tp];
           q.pop();
           if(tp==endWord)break;
       for(int i=0;i<tp.size();i++){
           char original = tp[i];
           for(char ch='a';ch<='z';ch++){
               tp[i]=ch;
               if(st.find(tp)!=st.end()){
                   umap[tp]=steps+1;
                   q.push(tp);
                   st.erase(tp);
               }
           }
           tp[i]=original;
       }   
       }
     if(umap.find(endWord)!=umap.end()){
        vector<string>seq;
        seq.push_back(endWord);
        dfs(endWord,seq,beginWord);
     }

return ans;
    }
