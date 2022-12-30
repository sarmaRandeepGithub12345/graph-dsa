//dfs
bool dfs(vector<int>&color,vector<int>adj[],int parent){

for(auto it:adj[parent]){
    if(!color[it]){
        color[it]=color[parent]==1?2:1;
        if(!dfs(color,adj,it))return false;
        
    }else if(color[it]==color[parent])return false;
}
return true;
}
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>color(V,0);
	    for(int i=0;i<V;i++){
	        if(color[i]==0){
	            color[i]=1;
	           if(!dfs(color,adj,i))return false;
	        }
	    }return true;
	}
//bfs
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int>color(V,0);
	    queue<pair<int,int>>q;
	    for(int i=0;i<V;i++){
	        if(!color[i]){
	            q.push({i,1});
	            while(!q.empty()){
	                int node=q.front().first;
	                int Pcolor=q.front().second;
	                q.pop();
	                for(auto it:adj[node]){
	                    if(!color[it]){
	                        color[it]=Pcolor==1?2:1;
	                        q.push({it,Pcolor==1?2:1});
	                    }else if(color[it]==Pcolor){
	                        return 0;
	                    }
	                }
	            }
	        }
	    }return 1;
	}
