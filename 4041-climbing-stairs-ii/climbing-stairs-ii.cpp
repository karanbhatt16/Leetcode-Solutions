class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> result(n+1,0);
        result[1]=costs[0]+1;
        if(n==1) return result[1];
        result[2]=min(costs[1]+4,costs[1]+result[1]+1);
        for(int i=3;i<=n;i++){
            result[i]=min(result[i-3]+costs[i-1]+9,min(result[i-2]+costs[i-1]+4,result[i-1]+costs[i-1]+1));
        }
        return result[n];
    }
};