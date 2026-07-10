#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                     vector<vector<int>>& queries) {

        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++)
            arr[i] = {nums[i], i};

        sort(arr.begin(), arr.end());

        vector<int> orgToNode(n);
        for (int i = 0; i < n; i++)
            orgToNode[arr[i][1]] = i;

        vector<int> farthest(n);

        for (int i = 0; i < n; i++) {
            int x = arr[i][0] + maxDiff;

            auto it = upper_bound(
                arr.begin(), arr.end(), x,
                [](int val, const vector<int>& a) {
                    return val < a[0];
                });

            --it;
            farthest[i] = it - arr.begin();
        }

        const int LOG = 20;

        vector<vector<int>> up(LOG, vector<int>(n));

        for (int i = 0; i < n; i++)
            up[0][i] = farthest[i];

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                up[j][i] = up[j - 1][ up[j - 1][i] ];
            }
        }

        vector<int> ans;

        for (auto &query : queries) {

            int a = orgToNode[query[0]];
            int b = orgToNode[query[1]];

            if (a > b)
                swap(a, b);

            if (a == b) {
                ans.push_back(0);
                continue;
            }

            if (farthest[a] == a) {
                ans.push_back(-1);
                continue;
            }

            int jumps = 0;
            int cur = a;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][cur] < b) {
                    jumps += (1 << j);
                    cur = up[j][cur];
                }
            }

            if (farthest[cur] >= b)
                ans.push_back(jumps + 1);
            else
                ans.push_back(-1);
        }

        return ans;
    }
};