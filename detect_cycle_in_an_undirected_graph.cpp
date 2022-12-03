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
