class SegTree {
    struct Info {
        long long sum = 0;  // Sum of distinct counts
        long long sq = 0;   // Sum of squared distinct counts
        long long lazy = 0; // Pending increment
    };

    vector<Info> seg;
    int n;
    static const int MOD = 1e9 + 7;

    void apply(int i, int left, int right, long long val) {
        long long len = right - left + 1;

        seg[i].sq = (seg[i].sq
            + 2LL * val % MOD * seg[i].sum % MOD
            + len % MOD * val % MOD * val % MOD) % MOD;

        seg[i].sum = (seg[i].sum + len * val) % MOD;
        seg[i].lazy = (seg[i].lazy + val) % MOD;
    }

    void push(int i, int left, int right) {
        if (seg[i].lazy == 0 || left == right) return;

        int mid = (left + right) / 2;
        long long val = seg[i].lazy;

        apply(2 * i + 1, left, mid, val);
        apply(2 * i + 2, mid + 1, right, val);

        seg[i].lazy = 0;
    }

    void update(int i, int left, int right, int l, int r) {
        if (right < l || left > r) return;

        if (l <= left && right <= r) {
            apply(i, left, right, 1);
            return;
        }

        push(i, left, right);

        int mid = (left + right) / 2;
        update(2 * i + 1, left, mid, l, r);
        update(2 * i + 2, mid + 1, right, l, r);

        seg[i].sum = (seg[2 * i + 1].sum
                    + seg[2 * i + 2].sum) % MOD;

        seg[i].sq = (seg[2 * i + 1].sq
                   + seg[2 * i + 2].sq) % MOD;
    }

public:
    SegTree(int n) : n(n), seg(4 * n + 5) {}

    void update(int l, int r) {
        update(0, 0, n - 1, l, r);
    }

    long long getSquares() {
        return seg[0].sq;
    }
};

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        SegTree st(n);
        unordered_map<int, int> last;

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int l = 0;

            if (last.count(nums[i])) {
                l = last[nums[i]] + 1;
            }

            st.update(l, i);
            ans = (ans + st.getSquares()) % MOD;

            last[nums[i]] = i;
        }

        return ans;
    }
};