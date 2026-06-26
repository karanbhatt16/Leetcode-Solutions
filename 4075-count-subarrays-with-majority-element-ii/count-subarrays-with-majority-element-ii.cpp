class ST {
    vector<int> seg;
    int N;
public:
    ST (int n, vector<int>& a) {
        seg.resize(4 * n + 1, 0);
        N = n;
        build(0, 0, N - 1, a);
    }

    void build (int idx, int low, int high, vector<int>& a) {
        if (low == high) {
            seg[idx] = a[low];
            return;
        }

        int mid = (low + high) >> 1;

        build(2 * idx + 1, low, mid, a);
        build(2 * idx + 2, mid + 1, high, a);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    void pointUpdate(int idx, int low, int high, int i, int val) {
        if (low == high) {
            seg[idx] += val;
            return;
        }

        int mid = (low + high) >> 1;

        if (i <= mid) {
            pointUpdate(2 * idx + 1, low, mid, i, val);
        } else {
            pointUpdate(2 * idx + 2, mid + 1, high, i, val);
        }

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];

    }

    int queryST(int idx, int low, int high, int l, int r) {

        // no overlap
        if (l > high || r < low) {
            return 0;
        }

        // complete overlap
        if (low >= l && high <= r) {
            return seg[idx];
        }

        // partial overlap
        int mid = (low + high) >> 1;

        int left = queryST(2 * idx + 1, low, mid, l, r);
        int right = queryST(2 * idx + 2, mid + 1, high, l, r);

        return left + right;
    }

    void update(int i, int val) {
        pointUpdate(0, 0, N - 1, i, val);
    }

    int query(int l, int r) {
        return queryST(0, 0, N - 1, l, r);
    }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> cumm(n, 0);
        int mini = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) cumm[i] = 1;
            else cumm[i] = -1;
            if(i > 0) {
                cumm[i] += cumm[i - 1];
            }
            mini = min(mini, cumm[i]);
        }

        mini *= -1;

        for (int i = 0; i < n; i++) {
            cumm[i] += mini;
        }

        vector<int> freq(n + 1, 0);
        for (int i = 0; i < n; i++) {
            freq[cumm[i]]++;
        }

        for (int i = 0; i <= n; i++) {
            cout << freq[i];
        }

        ST seg(n + 1, freq);

        long long ans = seg.query(1 + mini, n);

        for (int i = 1; i < n; i++) {
            int x = cumm[i - 1];
            ans += seg.query(x + 1, n);

            seg.update(x, -1);
        }

        return ans;
    }
};