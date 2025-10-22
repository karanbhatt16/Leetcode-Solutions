class Solution {
public:
    int climbStairs(int n) {
        int prev2=1;
        int prev=2;
        int curr;
        if(n==1 || n==2) return n;
        for(int i=2;i<n;i++){
            curr=prev+prev2;
            prev2=prev;
            prev=curr;
        }
        return curr;
    }
};