// count number of zeroes on 1's boundary

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0;
        int row,col;
        row=grid.size();
        if(row){
            col=grid[0].size();
        }
        for(int i=0;i<row;i++){
            
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    int a=0,b=0,c=0,d=0;
                    if(i>0 && grid[i-1][j]==1){
                        a=1;
                    }
                    if(i<row-1 && grid[i+1][j]==1){
                        b=1;
                    }
                    if(j>0 && grid[i][j-1]==1){
                        c=1;
                    }
                    if(j<col-1 && grid[i][j+1]==1){
                        d=1;
                    }
                    ans+=4-a-b-c-d; 
                }
            }
        }
        return ans;
    }
};
