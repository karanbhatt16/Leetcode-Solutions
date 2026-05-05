class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rows;
        queue<int> q;
        vector<int> freq(k + 1, 0);
        vector<vector<int>> rowadj(k + 1);
        for (int i = 0; i < rowConditions.size(); i++) {
            rowadj[rowConditions[i][0]].push_back(rowConditions[i][1]);
        }
        for (int i = 0; i < rowConditions.size(); i++) {
            freq[rowConditions[i][1]]++;
        }
        for (int i = 1; i <= k; i++) {
            if (freq[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : rowadj[node]) {
                freq[it]--;
                if (freq[it] == 0) {
                    q.push(it);
                }
            }
            rows.push_back(node);
        }


        freq.clear();
        vector<vector<int>> coladj(k + 1);
        vector<int> cols;
        for (int i = 0; i < colConditions.size(); i++) {
            coladj[colConditions[i][0]].push_back(colConditions[i][1]);
        }
        for (int i = 0; i < colConditions.size(); i++) {
            freq[colConditions[i][1]]++;
        }
        for (int i = 1; i <= k; i++) {
            if (freq[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : coladj[node]) {
                freq[it]--;
                if (freq[it] == 0) {
                    q.push(it);
                }
            }
            cols.push_back(node);
        }

        vector<vector<int>> ans(k, vector<int> (k, 0));
        if (cols.size() != k || rows.size() != k) return {};
        vector<int> rowidx(k + 1, 0);
        vector<int> colidx(k + 1, 0);
        for (int i = 0; i < k; i++) {
            rowidx[rows[i]] = i;
            colidx[cols[i]] = i;
        }
        for (int i = 1; i <= k; i++) {
            ans[rowidx[i]][colidx[i]] = i;
        }
        return ans;
    }
};