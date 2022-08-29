class Solution {

void visit(vector<vector<char>> &matrix,int x,int y,int r,int c)
{
    if(x<0 || x>=r || y<0 || y>=c || matrix[x][y]!='1')
        return;
    
    matrix[x][y]='2';
    
    visit(matrix,x+1,y,r,c);
    visit(matrix,x,y+1,r,c);
    visit(matrix,x-1,y,r,c);
    visit(matrix,x,y-1,r,c);
}
    

    
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int row=grid.size();
        int col=grid[0].size();
        if(row==0)
            return 0;
        
        int no_ofIsland=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='1')
                {
                  visit(grid,i,j,row,col);
                    no_ofIsland++;
                } 
                
            }
        }
        return no_ofIsland;
}
};
    
