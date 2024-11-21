class Solution {
public:
    
    void dfs(int r, int c, string dir,  vector<vector<int>>& mat){
        if(r<0 || r>=mat.size() || c<0 || c>=mat[0].size()) return;
        if(mat[r][c] == 2 || mat[r][c] == 1 ) return;
        mat[r][c] = 4;
        if(dir == "r"){
            dfs(r, c+1, "r", mat);
        }
        if(dir == "l"){
            dfs(r, c-1, "l", mat);
        }
        if(dir == "u"){
            dfs(r-1, c, "u", mat);
        }
        if(dir == "d"){
            dfs(r+1, c, "d", mat);
        }
        
    }
    
    
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> mat(m, vector<int>(n, 0));
        for(auto a : guards){
            mat[a[0]][a[1]] = 1;
        }
        for(auto a : walls){
            mat[a[0]][a[1]] = 2;
        }

        for(auto a : guards){
            int r = a[0];
            int c = a[1];
            dfs(r,c+1,"r",mat);
            dfs(r,c-1,"l",mat);
            dfs(r+1,c,"d",mat);
            dfs(r-1,c,"u",mat);
        }

        int cnt=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0) cnt++;
            }
        }
        return cnt;
    }
};