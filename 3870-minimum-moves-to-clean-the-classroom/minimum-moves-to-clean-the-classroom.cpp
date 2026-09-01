struct info {
    int row;
    int col;
    int energy;
    int mask;
};

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        int maxEnergy = energy;

        vector<vector<int>> directions = {{1,0}, {0, 1}, {-1, 0}, {0, -1}};

        vector<vector<int>> litterBit(20, vector<int> (20, 0));
        int litterCount = 0;
        int startR = 0;
        int startC = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                litterBit[i][j] = -1;
                if (classroom[i][j] == 'S') {
                    startR = i;
                    startC = j;
                } else if (classroom[i][j] == 'L') {
                    litterBit[i][j] = litterCount;
                    litterCount++;
                }
            }
        }

        int allCollected = (1 << litterCount) - 1;
        if (litterCount == 0) {
            return 0;
        }

        vector<vector<vector<vector<bool>>>> visited(20, vector<vector<vector<bool>>> (20, vector<vector<bool>> (energy + 1, vector<bool> (1025, 0))));
        queue<info> q;
        q.push({startR, startC, maxEnergy, 0});
        visited[startR][startC][maxEnergy][0] = true;

        int moves = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                info curr = q.front();
                q.pop();
                
                if (curr.mask == allCollected) {
                    return moves;
                }

                if (curr.energy == 0) {
                    continue;
                }

                for (auto &dir : directions) {
                    int nextR = dir[0] + curr.row;
                    int nextC = dir[1] + curr.col;

                    if (nextR < 0 || nextR >= m || nextC < 0 || nextC >= n) {
                        continue;
                    }

                    char cell = classroom[nextR][nextC];
                    if (cell == 'X') continue;

                    int nextEnergy = curr.energy - 1;
                    int nextMask = curr.mask;

                    if (cell == 'R') {
                        nextEnergy = maxEnergy;
                    }
                    if (cell == 'L') {
                        nextMask |= (1 << litterBit[nextR][nextC]);
                    }

                    if (!visited[nextR][nextC][nextEnergy][nextMask]) {
                        visited[nextR][nextC][nextEnergy][nextMask] = true;
                        q.push({nextR, nextC, nextEnergy, nextMask});
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};