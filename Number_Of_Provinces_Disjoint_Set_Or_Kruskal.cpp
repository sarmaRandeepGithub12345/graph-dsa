//Adjacency Matrix dfs 
//TC: 98%
//SC:12.12%
void dfs(int node,vector<int>graph[],vector<int>&visited){
        visited[node]=1;
        for(auto it:graph[node]){
            if(!visited[it]){
                dfs(it,graph,visited);
            }
        }
    }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int>graph[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
                if(adj[i][j]){
               
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
            }
        }
        int count=0;
        vector<int>visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,graph,visited);
                count++;
                
            }
        }return count;
    }
//Adjacency List DFS
//TC - 90.78%
//SC - 18.18%
   void dfs(int node,vector<int>graph[],vector<int>&visited){
        visited[node]=1;
        for(auto it:graph[node]){
            if(!visited[it]){
                dfs(it,graph,visited);
            }
        }
    }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int>graph[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
                if(adj[i][j]){
               
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
            }
        }
        int count=0;
        vector<int>visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,graph,visited);
                count++;
                
            }
        }return count;
    }
//Adjacency list bfs
//TC - 87%
//SC - 18.18%
int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int>graph[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
                if(adj[i][j]){
               
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
            }
        }
    int count=0;
    vector<int>visited(V,0);
    queue<int>q;    
      for(int i=0;i<V;i++){
          if(!visited[i]){
            count++;
            q.push(i);
            visited[i]=1;
            while(!q.empty()){
                int t =q.front();
                q.pop();
                for(auto it:graph[t]){
                    if(!visited[it]){
                        q.push(it);
                        visited[it]=1;
                    }
                }
            }
          }
      }return count;
    }
};

//Union 
//TC:  93%
//SC:  40%
int find(vector<int>&parent,int node){
        if(node==parent[node])return node;
        else return parent[node]=find(parent,parent[node]);
    }
    
    void unionfunct( int u, int v, vector<int>&parent, vector<int>&dist) 
    {
        int lu= find(parent,u);
        int lv= find(parent,v);
        if(dist[lv]<dist[lu]){
            parent[lv]=lu;
            dist[lu]+=dist[lv];
            
        }else{
            parent[lu]=lv;
            dist[lv]+=dist[lu];
        }
          
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<pair<int,int>>temp;
        for(int i=0;i<V;i++){
            for(int j=i;j<V;j++){
                if(adj[i][j] && i!=j)
                    temp.push_back({i,j});
                
            }
        }
    vector<int>parent(V,0),dist(V,0);
    for(int i=0;i<V;i++){
        parent[i]=i;
        dist[i]=1;
    }
for(auto it:temp){
    int u=it.first,v=it.second;    
    
    if(find(parent,u)!=find(parent,v))
        unionfunct(u,v,parent,dist);
    }    
    int count=0;
for(int i=0;i<V;i++)if(parent[i]==i)count++;
return count;
        
    }
