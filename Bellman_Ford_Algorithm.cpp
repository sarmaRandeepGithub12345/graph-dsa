 struct comp{
      bool operator()(vector<int>&a,vector<int>&b){
          return a[1]>b[1];
      }  
    };
    
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
       
        vector<int>dist(V,1e8);
        dist[S]=0;
        for(int i=0;i<V-1;i++){
        for(auto it:edges){
            int v=it[0];
            int u =it[1];
            int d=it[2];
            if(
              dist[v]!=1e8 /*Because if we have not reached the parent node ,there is no point of relaxation or reducing the distance to the vertices*/ 
              && dist[v]+d<dist[u]){
              dist[u]=dist[v]+d;  
            }
        }
        }
        for(auto it:edges){
            int v=it[0];
            int u =it[1];
            int d=it[2];
            if(dist[v]!=1e8 && dist[v]+d<dist[u]){
              return {-1};  
            } 
        }
     return dist;
    }
