class Solution {
public:
    int numTrees(int n) {
        map<int,int> mp;
        mp[0]=1;
        mp[1]=1;
        int sum=0;
        for(int i=2;i<=n;i++){
            int sum=0;
            for(int j=0;j<i;j++){
                sum+=mp[j]*mp[i-j-1];
            }
            mp[i]=sum;
        }
        return mp[n];
    }
};