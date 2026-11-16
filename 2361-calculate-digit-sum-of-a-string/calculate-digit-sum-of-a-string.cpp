class Solution {
public:
    string digitSum(string s, int k) {
        string t = s;
        string nt = "";
        while (t.size () > k) {
            int val = 0;
            for (int i = 0; i < t.size(); i++) {
                if (i % k == 0) {
                    val = 0;
                }
                val += (t[i] - '0');
                if ((i + 1) % k == 0 || i == t.size() - 1) {
                    nt += to_string(val);
                }
            }
            t = nt;
            nt = "";
        }
        return t;
    }
};