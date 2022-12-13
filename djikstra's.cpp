//Using priority queue -Incase of PQ, the maximum heap size can go upto E = number of edges, leading to complexity = O(E*logE).
 vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int>dist(V,100000);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,S});
        dist[S]=0;
        while(!q.empty()){
        pair<int,int>p=q.top();
        q.pop();
        for(auto it:adj[p.second]){
        if(dist[it[0]]>it[1]+dist[p.second]){
            dist[it[0]]=it[1]+dist[p.second];
            q.push({dist[it[0]],it[0]});
        }     
        }
        }
    return dist;   
    }
//Using set - Incase of set, the maximum set size can go upto V =. number of vertices, leading to complexity = O(E*logV).


 vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
       set<pair<int,int>>st;
       st.insert({0,S});
       vector<int>dist(V,1e9);
       dist[S]=0;
       while(!st.empty()){
           auto it=*(st.begin());
           int parent= it.second;
           int dis=it.first;
           
           st.erase(it);
           
           for(auto it:adj[parent]){
               int child=it[0];
               int edgeW=it[1];
               
               if(dis+edgeW < dist[child]){
                   
                   
                   if(dist[child]!=1e9)st.erase({dist[child],child});
                   
                   
                   dist[child]=dis+edgeW;
                   st.insert({dist[child],child});   
               }   
           }      
       }return dist;
    }
