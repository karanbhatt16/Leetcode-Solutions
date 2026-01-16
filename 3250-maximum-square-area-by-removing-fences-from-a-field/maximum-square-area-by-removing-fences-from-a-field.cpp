class Solution {
public:

     vector<long long> solve(vector<int>& arr, int size) {
        vector<int> test(arr.begin(), arr.end());
        test.push_back(1);
        test.push_back(size);

        sort(test.begin(), test.end());

        set<int> st;
        
        for (int i = 1; i < test.size(); i++) {
            for(int j = 0; j < i; j++) {
                st.insert(test[i] - test[j]);
            }
        }

        vector<long long> ans(st.begin(), st.end());
        sort(ans.begin(), ans.end());

        return ans;

    }


    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        
        vector<long long> horizontal = solve(hFences, m);

        vFences.push_back(1);
        vFences.push_back(n);
        sort(vFences.begin(), vFences.end());

        for (int i = horizontal.size() - 1; i >= 0; i--) {
            int j = 0, k = 1;
            while (k < vFences.size()) {
                if (vFences[k] - vFences[j] == horizontal[i]) {
                    return ((horizontal[i] % 1000000007) * (horizontal[i] % 1000000007)) % 1000000007;
                } else if (vFences[k] - vFences[j] > horizontal[i]) {
                    j++;
                } else {
                    k++;
                }
            }
        }

        return -1;

    }
};