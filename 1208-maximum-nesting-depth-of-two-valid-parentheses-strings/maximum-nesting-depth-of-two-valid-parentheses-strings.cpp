class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> a(n, 0);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (seq[i] == '(') {
                count++;
                a[i] = count % 2;
            } else {
                a[i] = count % 2;
                count--;
            }
        }
        return a;
    }
};