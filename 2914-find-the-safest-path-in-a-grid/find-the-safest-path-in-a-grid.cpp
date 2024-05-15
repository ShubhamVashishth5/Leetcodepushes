class Solution {
public:
    vector<int> roww = {0, 0, -1, 1};
    vector<int> coll = {-1, 1, 0, 0};

    void bfs(vector<vector<int>>& grid, vector<vector<int>>& distanceToThief, int n) {
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++){
                if(grid[i][j]) {
                    distanceToThief[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            auto t = q.front();
            q.pop();

            int x = t.first, y = t.second;
            int d = distanceToThief[x][y];

            for(int i = 0; i < 4; i++){
                int newX = x + roww[i];
                int newY = y + coll[i];

                if(newX >= 0 && newX < n && newY >= 0 && newY < n && distanceToThief[newX][newY] == INT_MAX) { 
                    distanceToThief[newX][newY] = d + 1;
                    q.push({newX, newY});
                }
            }
        }
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n - 1][n - 1]) return 0;

        vector<vector<int>> distanceToThief(n, vector<int>(n, INT_MAX));
        bfs(grid, distanceToThief, n);

        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({distanceToThief[0][0], {0, 0}});

        while(!pq.empty()){
            auto temp = pq.top().second;
            auto safe = pq.top().first;
            pq.pop();

            if(temp.first == n - 1 && temp.second == n - 1) return safe;

            for(int i = 0; i < 4; i++) {
                int newX = temp.first + roww[i];
                int newY = temp.second + coll[i];

                if(newX >= 0 && newX < n && newY >= 0 && newY < n){
                    int s = min(safe, distanceToThief[newX][newY]);
                    if(distanceToThief[newX][newY] != INT_MAX) {
                        pq.push({s, {newX, newY}});
                        distanceToThief[newX][newY] = INT_MAX;
                    }
                }
            }
        }

        return -1;
    }
};
