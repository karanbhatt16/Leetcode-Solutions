class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> result(4,0);
        result[1]=costs[0]+1;
        if(n==1) return result[1];
        result[2]=min(costs[1]+4,costs[1]+result[1]+1);
        if(n==2) return result[2];
        for(int i=3;i<=n;i++){
            result[3]=min(result[0]+costs[i-1]+9,min(result[1]+costs[i-1]+4,result[2]+costs[i-1]+1));
            result[0]=result[1];
            result[1]=result[2];
            result[2]=result[3];
        }
        return result[3];
    }
};