class Solution {
public
    int shortestPathBinaryMatrix(vectorvectorint& grid) {
        
        int n = grid.size();

        if(grid[0][0] == 1)return -1;

        queuevectorint  q;  x, y, len
        q.push({0, 0, 1});
        grid[0][0] = 1;

        while(!q.empty()){
            vectorint node = q.front();
            q.pop();

            int x = node[0];
            int y = node[1];
            int len = node[2];

            if(x==n-1 && y==n-1)return len;

            int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
            int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

            for(int i=0; i8; i++){
                int a = x + dx[i];
                int b = y + dy[i];

                if(a = 0 && a  n && b=0 && bn && grid[a][b] == 0){
                    grid[a][b] = 1;
                    q.push({a, b, len + 1});
                }
            }
        }

        return -1;


    }
};