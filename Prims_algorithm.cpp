struct comp{
      bool operator()(vector<int>&a,vector<int>&b){
          return a[0]>b[0];
      }  
    };
    
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<vector<int>,vector<vector<int>>,comp>q;
        vector<int>visited(V,0);
        int sum=0;
        q.push({0,0});
        while(!q.empty()){
            int node=q.top()[1];   
            int d=q.top()[0];
            q.pop();
            if(visited[node])continue;
            visited[node]=1;
            sum+=d;
            for(auto it:adj[node]){
                int child=it[0];
                int cdis=it[1];
                if(!visited[child]){
                    q.push({cdis,child});
                }
            }
        }
        return sum;
    }
