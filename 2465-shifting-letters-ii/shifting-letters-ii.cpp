class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = shifts.size();
        int l = s.length();
        vector<int> a(l, 0);
        for (auto q : shifts) {
            if (q[2] == 0) {
                a[q[0]] -= 1;
                if (q[1] < l - 1) {
                    a[q[1] + 1] += 1;
                }
            } else {
                a[q[0]] += 1;
                if (q[1] < l - 1) {
                    a[q[1] + 1] -= 1;
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < l; i++) {
            sum += a[i];
            a[i] = sum;
            int x = ((s[i] - 'a') + sum) % 26;
            if (x < 0) x += 26;
            s[i] = 'a' + x;
        }
        return s;
    }
};