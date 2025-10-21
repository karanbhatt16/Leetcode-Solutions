class Solution {
public:
    void solve(int idx, vector<int>& candidates, int target, set<vector<int>>& ans, vector<int>& v,int sum){
        if(sum>target) return;
        if(sum==target){
            ans.insert(v);
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            v.push_back(candidates[i]);
            sum+=candidates[i];
            solve(i,candidates,target,ans,v,sum);
            v.pop_back();
            sum-=candidates[i];
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        vector<int> v;
        solve(0,candidates,target,ans,v,0);
        vector<vector<int>> result(ans.begin(),ans.end());
        return result;
    }
};