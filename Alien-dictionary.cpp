//In case when string count is given
string findOrder (string dict[], int n, int K)
{
  //code here
  vector < int >adj[K];
  vector < int >indegree (K, 0);
  for (int i = 0; i < n - 1; i++)
    {
      int s1 = dict[i].length ();
      int s2 = dict[i + 1].length ();
      int j = 0;

      while (j < s1 && j < s2)
	{
	  if (dict[i][j] == dict[i + 1][j])
	    j++;
	  else
	    {
	      char c1 = dict[i][j];
	      char c2 = dict[i + 1][j];
	      adj[c1 - 'a'].push_back (c2 - 'a');
	      indegree[c2 - 'a']++;
	      break;
	    }
	}
    }
/*for(int i=0;i<K;i++){
    cout<<i<<":";
    for(int j=0;j<adj[i].size();j++){
        cout<<adj[i][j]<<"->";
    }cout<<endl;
}*/
  queue < int >q;
  for (int i = 0; i < K; i++)
    {
      if (!indegree[i])
	q.push (i);
    }
  string ans = "";
  while (!q.empty ())
    {
      int t = q.front ();
      ans += 'a' + t;
      q.pop ();
      for (int i = 0; i < adj[t].size (); i++)
	{
	  int s = adj[t][i];
	  indegree[s]--;
	  if (!indegree[s])
	    {
	      q.push (s);
	    }
	}
    }
  return ans;
}
//In case when string count is not given
#include <set>
#include <queue>
#include <map>
vector<char> getAlienLanguage(string* dict, int n)
{
int ch[26]={0};
//cout<<K<<endl;
           vector<int>adj[26];
        vector<int>indegree(26,0);
        for(int i=0;i<n-1;i++){
            int s1=dict[i].length();
            int s2=dict[i+1].length();
            int j=0;
            
            while(j<s1 && j<s2){
                ch[dict[i][j]-'a']=1;
                ch[dict[i+1][j]-'a']=1;
                if(dict[i][j]==dict[i+1][j])j++;   
             else{
                char c1 =dict[i][j];
                char c2 =dict[i+1][j];
                adj[c1-'a'].push_back(c2-'a');
                indegree[c2-'a']++;
                break;
             }     
            }
        }
/*for(int i=0;i<K;i++){
    cout<<i<<":";
    for(int j=0;j<adj[i].size();j++){
        cout<<adj[i][j]<<"->";
    }cout<<endl;
}*/
queue<int>q;
for(int i=0;i<26;i++){
    if(!indegree[i] && ch[i]==1)q.push(i);
}vector<char>ans;
while(!q.empty()){
    int t=q.front();
    ans.push_back('a'+t);
    q.pop();
    for(int i=0;i<adj[t].size();i++){
        int s =adj[t][i];
        indegree[s]--;
        if(!indegree[s]){
            q.push(s);
        }
    }
}return ans;
}
