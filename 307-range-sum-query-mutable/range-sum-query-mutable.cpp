class NumArray {
private:
    vector<int> seg;
    int N;

    void build(int idx, int low, int high, vector<int>& nums) {
        if (low == high) {
            seg[idx] = nums[low];
            return;
        }

        int mid = (low + high) >> 1;

        build(2 * idx + 1, low, mid, nums);
        build(2 * idx + 2, mid + 1, high, nums);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    int query(int idx, int low, int high, int l, int r) {
        if (l > high || r < low) {
            return 0;
        }

        if (low >= l && high <= r) {
            return seg[idx];
        }

        int mid = (low + high) >> 1;

        int left = query(2 * idx + 1, low, mid, l, r);
        int right = query(2 * idx + 2, mid + 1, high, l, r);

        return left + right;
    }

    void change(int idx, int low, int high, int i, int val) {
        if (low == high) {
            seg[idx] = val;
            return;
        }

        int mid = (low + high) >> 1;

        if (i <= mid) {
            change(2 * idx + 1, low, mid, i, val);
        } else {
            change(2 * idx + 2, mid + 1, high, i, val);
        }

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }


public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        N = n;
        seg.resize(4 * n + 1);
        build(0, 0, n - 1, nums);
    }

    
    void update(int index, int val) {
        change(0, 0, N - 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return query(0, 0, N - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */