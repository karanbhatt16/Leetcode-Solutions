class Solution {
public:
void solve(vector<int>& candidates, int target, int idx, set<vector<int>>& ans, vector<int>& v){
    if(target<0){
        return;
    }
    if(target==0){
        ans.insert(v);
        return;
    }
    for(int i=idx;i<candidates.size();i++){
        if(i!=idx && candidates[i]==candidates[i-1]){
            continue;
        }
        if(target-candidates[i]<0) break;
        v.push_back(candidates[i]);
        solve(candidates,target-candidates[i],i+1,ans,v);
        v.pop_back();

    }
    return;
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        set<vector<int>> ans;
        vector<int> v;
        solve(candidates,target,0,ans,v);
        vector<vector<int>> result(ans.begin(),ans.end());
        return result;
    }
};