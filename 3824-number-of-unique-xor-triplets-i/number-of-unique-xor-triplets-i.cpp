class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        if (n <= 2) {
            return n;
        }
        while (n != 0) {
            n /= 2;
            count++;
        }
        return 1 << (count);
    }
};