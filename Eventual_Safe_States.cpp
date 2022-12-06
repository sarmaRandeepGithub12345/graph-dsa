//Using BFS
vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int>graph[V];
        vector<int>indegree(V,0);
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
                int t =adj[i][j];
                graph[t].push_back(i);
                
                indegree[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(!indegree[i])q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
        int t=q.front();
        q.pop();
        ans.push_back(t);
        for(int i=0;i<graph[t].size();i++){
            int temp=graph[t][i];
            indegree[temp]--;
            if(!indegree[temp]){
                q.push(temp);
            }
        }
            
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
//Using DFS
bool funct(vector<int>&visited,vector<int>&trackcycle,int node,vector<int> adj[]){
     
    visited[node]=1;  
    trackcycle[node]=1;  
    for(int i=0;i<adj[node].size();i++){
        int t=adj[node][i];
        if(!visited[t]){
            if(funct(visited,trackcycle,t,adj))return 1;
        }else if(trackcycle[t])return 1;
    }  
    
    
    return trackcycle[node]=0;  
  }
  
  
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    vector<int>visited(V,0);
    vector<int>trackcycle(V,0);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            funct(visited,trackcycle,i,adj);
        }
    }vector<int>ans;
     for(int i=0;i<V;i++){
         if(!trackcycle[i])ans.push_back(i);
     }
     return ans;
    }


