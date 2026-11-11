class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(costBoth<=cost1 && costBoth<=cost2) return (long long)costBoth*(long long)max(need1, need2);
        else if(costBoth>=cost1+cost2) return (long long)cost1*(long long)need1 + (long long)cost2*(long long)need2;
        else if(costBoth<cost1+cost2 && costBoth>=cost1 && costBoth>=cost2){
            if(need1<need2){
                return (long long)need1*(long long)costBoth + (long long)(need2-need1)*(long long)cost2;
            }else{
                return (long long)need2*(long long)costBoth + (long long)(need1-need2)*(long long)cost1;
            }
        }else if(cost1>costBoth && costBoth>=cost2){
            if(need1>need2) return (long long)costBoth*(long long)need1;
            else return (long long)costBoth*(long long)need1 + (long long)(need2-need1)*(long long)cost2;
        }else{
            if(need2>need1) return (long long)costBoth*(long long)need2;
            else return (long long)costBoth*(long long)need2 + (long long)(need1-need2)*(long long)cost1;
        }
    }
};