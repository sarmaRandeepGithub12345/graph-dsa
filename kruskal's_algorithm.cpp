 int find(vector<int>&parent,int node){
        if(parent[node]==node)return node;
        else parent[node]=find(parent,parent[node]);
    }
    void unionfunct(int u,int v,vector<int>&parent,vector<int>&dist){
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
    
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>>temp;
     //TC-O(Nodes +Edges)
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int u=it[0];
                int d=it[1];
         //  cout<<i<<" "<<u<<" "<<d<<endl;
                temp.push_back({d,{i,u}});
            }
        }
     
    vector<int>parent(V);//SC: O(Nodes)
    vector<int>dist(V); //SC: O(Nodes)
    
     //TC:O(Nodes)
     for(int i=0;i<V;i++){
        parent[i]=i;
        dist[i]=1;
    }
    int sum=0;
     
     
    sort(temp.begin(),temp.end());//TC: Edges*Log(Edges)    
   // cout<<temp[0].first<<" "<<temp[0].second.first<<" "<<temp[0].second.second<<endl;
    
    //TC:Edges*4*alpha 
     for(auto it:temp){
    int d=it.first,u=it.second.first,v=it.second.second;    
    
    if(find(parent,u)!=find(parent,v)){
   // cout<<u<<" "<<v<<" "<<d<<endl;
unionfunct(u,v,parent,dist);
    sum+=d;
    }    
    }    
        
    return sum;    
    }
