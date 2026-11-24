class Solution {
private:
    int Gcd(int a, int b) {
        while (b != 0) {
            a = a % b;
            swap(a, b);
        }
        return a;
    }
    int Lcm(int a, int b) {
        int num = a;
        int ans = 1;
        for (int i = 2; i <= b && b != 1; i++) {
            while (b % i == 0) {
                b = b / i;
                if (a % i == 0) a = a / i;
                else ans *= i;
            }
        }
        return num * ans;
    }
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        for (int i = 0; i < n; i++) {
            int prod = 1;
            int lcm = 1;
            int gcd = nums[i];
            for (int j = i; j < n; j++) {
                prod *= nums[j];
                lcm = Lcm(lcm, nums[j]);
                gcd = Gcd(gcd, nums[j]);
                cout << gcd << " ";
                if (lcm * gcd < prod) break;
                if (prod == lcm * gcd) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};