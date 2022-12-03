//Using dfs   
bool funct(int node,int parent, vector<int>&visited,int V,vector<int>adj[]){
     visited[node]=1;
     for(int i=0;i<adj[node].size();i++){
        int t=adj[node][i];
        if(!visited[t]){
            if(funct(t,node,visited,V,adj))return 1;
        }else if(t!=parent)return 1; 
         
     }
        
     visited[node]=0;     
     return 0;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
     vector<int>visited(V,0);
     vector<int>temp(V,0);
     for(int i=0;i<V;i++){
         if(!temp[i]){
             temp[i]=1;
             if(funct(i,-1,visited,V,adj))return 1;
         }
     }
        return 0;
    }
//Using bfs
bool check(vector<int>adj[],int i,vector<int>&visited,queue<pair<int,int>>&q){
     visited[i]=1;
     while(!q.empty()){
            int v=q.front().first;//son
            int u=q.front().second;//parent
            q.pop();
           
            for(int i=0;i<adj[v].size();i++){
                int t=adj[v][i];
                if(!visited[t]){
                    q.push({t,v});
                     visited[t]=1;
                }else if(visited[t]==1 && t!=u)return true;   
            }}
     return false;
 } 
  
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>visited(V,0);
        queue<pair<int,int>>q;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                q.push({i,-1});
                if(check(adj,i,visited,q))return true;
            }
            
        }        
        return false;
    }
