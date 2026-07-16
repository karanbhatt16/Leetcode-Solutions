class Solution {
private:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a%b);
    }
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n);
        int mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            prefixGcd[i] = gcd(nums[i], mx);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        int low = 0;
        int high = n - 1;
        long long sum = 0;
        while (low < high) {
            sum += gcd(prefixGcd[low], prefixGcd[high]);
            low++;
            high--;
        }
        return sum;
    }
};