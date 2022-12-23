   int find(int*parent,int node){
        if(node==parent[node])return node;
        else return parent[node]=find(parent,parent[node]);
    }
    
    void union_( int a, int b, int parent[], int rank[]) 
    {
        int lv=find(parent,a);
        int lu=find(parent,b);
        if(lv==lu){
            
            return;
        }
        
        if(rank[lv]<rank[lu]){
         
         parent[lv]=lu;
         
        }else{
         parent[lu]=lv ;   
        }
    }
    int makeConnected(int n, vector<vector<int>>& edge) {
            int parent[n],dist[n];
        for(int i=0;i<n;i++){
            parent[i]=i;
            dist[i]=1;
        }
        int count=0;
        for(auto it:edge){
            int u = it[0];
            int v = it[1];
            if(find(parent,u)!=find(parent,v))
            union_(u,v,parent,dist);
            else count++;
        }int pc=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i)pc++;
        }pc--;
        if(count>=pc)return pc;
        return -1;      
    }
