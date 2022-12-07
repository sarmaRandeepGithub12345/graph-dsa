//Time complexity O(N) where N is Nodes 
vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int>adj[N];
        for(int i=0;i<M;i++){
            int f=edges[i][0];
            int s=edges[i][1];
            adj[f].push_back(s);
            adj[s].push_back(f);
        }
        vector<int>shortest(N,1e9+7);
        queue<int>q;
        vector<int>visited(N,0);
        visited[src]=1;
        shortest[src]=0;
        q.push(src);
        while(!q.empty()){
            int s=q.size();
            while(s--){
                int t=q.front();
                q.pop();
                for(int i=0;i<adj[t].size();i++){
                    int k=adj[t][i];
                    if(!visited[k]){
                    q.push(k);
                    visited[k]=1;
                    shortest[k]=shortest[t]+1;
                    }
                }
            }
            
        }
        for(int i=0;i<shortest.size();i++){
            if( shortest[i]==1e9+7)shortest[i]=-1;
        }
        return shortest;
    }
