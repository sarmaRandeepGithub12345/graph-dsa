 struct comp{
      bool operator()(vector<int>&a,vector<int>&b){
          return a[1]>b[1];
      }  
    };
    
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
       
        vector<int>dist(V,1e8);
        dist[S]=0;
     //V-1 iterations because if we have a tree of size n
     //Suppose V =5
     //and the graph is 0 -1-> 1 -1-> 3 -1-> 4 -1-> 2 .So,to find the shortest path from source to each node ,we have to iterate the graph 4 times
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
