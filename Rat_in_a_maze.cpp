void funct(vector<vector<int>> &m,string t ,vector<string>&ans,int i,int j){
   m[i][j]=0; 
    int R=m.size(),C=m[0].size();
    if(i==R-1 && j==C-1){
        ans.push_back(t);
        m[i][j]=1; 
        return ;
    }   
    if(i+1>=0 && i+1<R && j>=0 && j<C && m[i+1][j]==1){
     funct(m,t+'D',ans,i+1,j);    
    }
    if(i-1>=0 && i-1<R && j>=0 && j<C && m[i-1][j]==1){
     funct(m,t+'U',ans,i-1,j);    
    }
    if(i>=0 && i<R && j-1>=0 && j-1<C && m[i][j-1]==1){
     funct(m,t+'L',ans,i,j-1);    
    }
    if(i>=0 && i<R && j+1>=0 && j+1<C && m[i][j+1]==1){
     funct(m,t+'R',ans,i,j+1);    
    }
    m[i][j]=1;        
}
vector < string > searchMaze(vector < vector < int >> & m, int n) {
    // Write your code here.
          string t="";
    vector<string>ans;
    if(m[0][0]==1)
    funct(m,t,ans,0,0);
    sort(ans.begin(),ans.end());
    return ans;  
}
