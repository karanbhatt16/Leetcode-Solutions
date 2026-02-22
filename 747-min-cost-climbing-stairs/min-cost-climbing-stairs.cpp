class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev2 = 0;
        int prev1 = 0;
        int curr = 0;
        for (int i = 0; i < cost.size(); i++) {
            curr = min(prev2, prev1) + cost[i];
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev2, prev1);
    }
};