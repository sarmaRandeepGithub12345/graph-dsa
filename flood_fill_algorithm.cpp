//TC: N*N*4;
//SC: N*N
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int oldColor=image[sr][sc];
    
     vector<int>X={0,0,1,-1};
     vector<int>Y={1,-1,0,0};
    queue<pair<int,int>>q;
    q.push({sr,sc});
    image[sr][sc]=newColor;
    while(!q.empty()){
    int i=q.front().first;
    int j=q.front().second;
        q.pop();
    for(int k=0;k<4;k++){
    int x=i+X[k],y=j+Y[k];
    if(x>=0 && x<image.size() && y>=0 && y<image[0].size() && image[x][y]==oldColor && oldColor!=newColor){
    image[x][y]=newColor;
    q.push({x,y});
    }
 }    
    }
    return image;    
    }
