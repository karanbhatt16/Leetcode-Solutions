class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> common(n + 1, 0);
        vector<int> output(n, 0);
        for (int i = 0; i < n; i++) {
            common[A[i]]++;
            common[B[i]]++;
            int count = 0;
            for (int j = 1; j <= n; j++) {
                if (common[j] == 2) {
                    count++;
                }
            }
            output[i] = count;
        }
        return output;
    }
};