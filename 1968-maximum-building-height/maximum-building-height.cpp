class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        sort(restrictions.begin(), restrictions.end(), [] (const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        if (restrictions.size() == 0 || restrictions[0][0] != 1) {
            restrictions.insert(restrictions.begin(), {1, 0});
        }
        if (restrictions.size() == 0 || restrictions[restrictions.size() - 1][0] != n) {
            restrictions.push_back({n, n - 1});
        }

        int m = restrictions.size();

        for (int i = 1; i < m; i++) {
            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i - 1][1] + restrictions[i][0] - restrictions[i - 1][0]
            );
        }

        for (int i = m - 2; i >= 0; i--) {
            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i + 1][1] + restrictions[i + 1][0] - restrictions[i][0]
            );
        }

        int start = 1;
        int height = 0;
        int maxheight = 0;

        for (auto it : restrictions) {
            int newHeight = height + (it[0] - start);
            if (newHeight <= it[1]) {
                start = it[0];
                height = newHeight;
                maxheight = max(maxheight, height);
            } else {
                if (it[1] >= height) {
                    start += (it[1] - height);
                    int h = it[1] + (it[0] - start) / 2;
                    maxheight = max(maxheight, h);
                } else {
                    int end = it[0] - (height - it[1]);
                    int h = height + (end - start) / 2;
                    maxheight = max(maxheight, h);
                }
                start = it[0];
                height = it[1];
            }
        }
        int newheight = (n - start) + height;
        maxheight = max(maxheight, newheight);

        return maxheight;
    }
};