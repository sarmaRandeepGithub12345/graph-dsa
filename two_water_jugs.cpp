int minSteps(int m, int n, int d)
	{
	    vector<vector<int>>visited(m+1,vector<int>(n+1,0));
	    queue<pair<int,int>>q;
	    q.push({0,0});
	    visited[0][0]=1;
	    int steps=0;
	    while(!q.empty()){
	        int sz=q.size();
	        while(sz--){
	        int currX=q.front().first;
	        int currY=q.front().second;
	        q.pop();
	        if(currX==d || currY==d)return steps;
	        
	        //Empty operations
	        if(currX>0 && !visited[0][currY]){//Empty jug 1
	            visited[0][currY]=1;
	            q.push({0,currY});
	        }
	        if(currY>0 && !visited[currX][0]){//Empty jug 2
	            visited[currX][0]=1;
	            q.push({currX,0});
	        }
	        
	        //Fill operations
	        if(currX<m && !visited[m][currY]){//fill jug 1 to the brim
	            visited[m][currY]=1;
	            q.push({m,currY});
	        }
	        
	        if(currY<n && !visited[currX][n]){//fill jug 2 to the brim
	            visited[currX][n]=1;
	            q.push({currX,n});
	        }
	        
	        
	        
	        //Transfer operations
	        if(m-currX>0 && currY>0){//Transfer water from jug2 to jug1
	           if(currX+currY<m && !visited[currX+currY][0]){
	               q.push({currX+currY,0});
	               visited[currX+currY][0]=1;
	           }else if(currX+currY>=m && !visited[m][currY-(m-currX)]){
	               q.push({m,currY-(m-currX)});
	               visited[m][currY-(m-currX)]=1;
	           }
	            
	        }
	        if(currX>0 && n-currY>0){
	            if(currX+currY<n && !visited[0][currX+currY]){
	                visited[0][currX+currY]=1;
	                q.push({0,currX+currY});
	            }else if(currX+currY>=n && !visited[currX-(n-currY)][n]){
	                visited[currX-n+currY][n]=1;
	                q.push({currX-n+currY,n});
	            }
	        }
	        
	        }steps++;
	    }
	    
	    return -1;
	}
