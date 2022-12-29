//TC : n*n*h8
//SC : n*n
void funct(int i,int j,vector<vector<char>>&grid){
        int R=grid.size(),C=grid[0].size();
        
        grid[i][j]='0';
    if(i+1>=0 && i+1<R && j>=0 && j<C && grid[i+1][j]=='1'){
        funct(i+1,j,grid);
    }
    if(i-1>=0 && i-1<R && j>=0 && j<C && grid[i-1][j]=='1'){
        funct(i-1,j,grid);
    }  
    if(i>=0 && i<R && j+1>=0 && j+1<C && grid[i][j+1]=='1'){
        funct(i,j+1,grid);
    }      
    if(i>=0 && i<R && j-1>=0 && j-1<C && grid[i][j-1]=='1'){
        funct(i,j-1,grid);
    } 
    if(i+1>=0 && i+1<R && j+1>=0 && j+1<C && grid[i+1][j+1]=='1'){
        funct(i+1,j+1,grid);
    }      
    if(i-1>=0 && i-1<R && j-1>=0 && j-1<C && grid[i-1][j-1]=='1'){
        funct(i-1,j-1,grid);
    }      
    if(i+1>=0 && i+1<R && j-1>=0 && j-1<C && grid[i+1][j-1]=='1'){
        funct(i+1,j-1,grid);
    }      
    if(i-1>=0 && i-1<R && j+1>=0 && j+1<C && grid[i-1][j+1]=='1'){
        funct(i-1,j+1,grid);
    }      
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int R=grid.size();
        int count=0;
        int C=grid[0].size();
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(grid[i][j]=='1'){
                    count++;
                    funct(i,j,grid);
                }
            }
        }return count;
    }
