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
