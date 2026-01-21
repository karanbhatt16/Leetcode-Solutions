class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> visited(isConnected.size(), 0);
        int count = 0;
        for (int i = 0; i < isConnected.size(); i++) {
            if (!visited[i]) {
                count++;
                queue<int> q;
                q.push(i);
                while (!q.empty()) {
                    int row = q.front();
                    q.pop();
                    visited[row] = 1;
                    for (int j = 0; j < isConnected.size(); j++) {
                        if (isConnected[row][j] && !visited[j]) {
                            q.push(j);
                        }
                    }
                }
            }
        }
        return count;
    }
};