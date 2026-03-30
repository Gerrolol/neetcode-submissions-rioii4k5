class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
       
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == INT_MAX){
                    queue<tuple<int,int,int>>q;   //x, y, currDist;
                    vector<pair<int,int>>directions = {{-1,0}, {0,-1}, {1,0}, {0,1}};
                    vector<vector<bool>>visited(m, vector<bool>(n, false));
                    q.push({i, j, 0});
                    while(!q.empty()){
                        auto [currx, curry,dist] = q.front();
                        visited[currx][curry] = true;
                        q.pop();
                        for(auto&[dx,dy] : directions){
                            int newx = currx + dx;
                            int newy = curry + dy;
                            if(newx >= 0 && newx <m && newy >=0 && newy <n && !visited[newx][newy] && grid[newx][newy] != -1){
                                if(grid[newx][newy] == 0){
                                    grid[i][j] = min(grid[i][j], dist+1);
                                }else{
                                    q.push({newx, newy, dist+1});
                                }
                            }
                        }
                    }
                }
            } 
        }
    }
};
