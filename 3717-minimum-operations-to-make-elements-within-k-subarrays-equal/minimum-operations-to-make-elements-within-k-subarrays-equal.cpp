class DoubleMultisetMedian {
private:
    multiset<long long> left_set;
    multiset<long long> right_set;
    long long left_sum = 0;
    long long right_sum = 0;
public:
    void insert(int val) {
        if (left_set.empty() || val <= *left_set.rbegin()) {
            left_set.insert(val);
            left_sum += val;
        } else {
            right_set.insert(val);
            right_sum += val;
        }

        if (left_set.size() > right_set.size() + 1) {
            auto it = prev(left_set.end());
            right_sum += *it;
            left_sum -= *it;
            right_set.insert(*it);
            left_set.erase(it);
        } else if (left_set.size() < right_set.size()) {
            auto it = right_set.begin();
            left_sum += *it;
            right_sum -= *it;
            left_set.insert(*it);
            right_set.erase(it);
        }
    }

    void erase(int val) {
        auto it = left_set.find(val);

        if (it != left_set.end()) {
            left_set.erase(it);
            left_sum -= val;
        } else {
            it = right_set.find(val);
            if (it != right_set.end()) {
                right_set.erase(it);
                right_sum -= val;
            }
        }
        if (left_set.size() > right_set.size() + 1) {
            auto it = prev(left_set.end());
            right_sum += *it;
            left_sum -= *it;
            right_set.insert(*it);
            left_set.erase(it);
        } else if (left_set.size() < right_set.size()) {
            auto it = right_set.begin();
            left_sum += *it;
            right_sum -= *it;
            left_set.insert(*it);
            right_set.erase(it);
        }
    }

    long long get_cost() {
        long long median = get_left_center();

        return median * left_set.size() - left_sum
            + right_sum - median * right_set.size();
    }

    double get_median() {
        if (left_set.empty()) {
            return 0.0;
        }
        if (left_set.size() > right_set.size()) {
            return *left_set.rbegin();
        } else {
            return ((long long)*left_set.rbegin() + *right_set.begin()) / 2.0;
        }
    }
    
    int get_left_center() {
        if (left_set.empty()) return -1;
        return *left_set.rbegin();
    }
};

class Solution {
private:
    long long solve(vector<long long>& a, int k, int i, int gap, vector<vector<long long>>& dp) {
        if (k == 0) {
            return 0;
        }
        if (i >= a.size()) return 1e18;
        if (dp[i][k] != -1) {
            return dp[i][k];
        }
        long long take = solve(a, k - 1, i + gap, gap, dp);
        long long not_take = solve(a, k, i + 1, gap, dp);

        if (take != 1e18) {
            take += a[i];
        }
        
        return dp[i][k] = min(take, not_take);
    }
public:
    long long minOperations(vector<int>& nums, int x, int k) {

        DoubleMultisetMedian ms;
        int n = nums.size();
        vector<long long> a;
        for (int i = 0; i < n; i++) {
            ms.insert(nums[i]);
            if (i < x - 1) continue;
        
            a.push_back(ms.get_cost());

            ms.erase(nums[i - x + 1]);
        }

        vector<vector<long long>> dp(a.size(), vector<long long> (k + 1, -1));
        return solve(a, k, 0, x, dp);
    }
};