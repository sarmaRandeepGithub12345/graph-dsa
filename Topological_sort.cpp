//With a stack	- BFS
vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>indegree(V,0);
	  for(int i=0;i<V;i++){
	      for(int j=0;j<adj[i].size();j++){
	          int t=adj[i][j];
	          indegree[t]++;
	    }
	  }
	stack<int>sq;
	for(int i=0;i<V;i++){
	    if(!indegree[i])sq.push(i);
	}
	  vector<int>ans;
	  while(!sq.empty()){
	      int tp=sq.top();
	      ans.push_back(tp);
	      sq.pop();
	      for(int i=0;i<adj[tp].size();i++){
	          int t =adj[tp][i];
	          indegree[t]--;
	          if(!indegree[t])sq.push(t);
	      }  
	  }
	  return ans;
	}
//with a queue -BFS
vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   vector<int>indegree(V,0);
	  for(int i=0;i<V;i++){
	      for(int j=0;j<adj[i].size();j++){
	          int t=adj[i][j];
	          indegree[t]++;
	    }
	  }
	queue<int>sq;
	for(int i=0;i<V;i++){
	    if(!indegree[i])sq.push(i);
	}
	  vector<int>ans;
	  while(!sq.empty()){
	      int tp=sq.front();
	      ans.push_back(tp);
	      sq.pop();
	      for(int i=0;i<adj[tp].size();i++){
	          int t =adj[tp][i];
	          indegree[t]--;
	          if(!indegree[t])sq.push(t);
	      }
	  }
	 
	  return ans;
	}
//DFS
void dfs(vector<int>adj[],int i,vector<int>&visited,stack<int>& sq){
	    visited[i]=1;
	    for(int j=0;j<adj[i].size();j++){
	        int t =adj[i][j];
	        if(!visited[t]){
	             dfs(adj,t,visited,sq);
	        }
	    }
	    
	    sq.push(i);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int>sq;
	    // code here
	    vector<int>visited(V,0);
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            dfs(adj,i,visited,sq);
	        }
	    }vector<int>res;
	    while(!sq.empty()){
	        int v =sq.top();
	        sq.pop();
	        res.push_back(v);
	        
	    }return res;
	}
