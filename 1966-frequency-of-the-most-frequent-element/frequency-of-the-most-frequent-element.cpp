class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        map<int, int, greater<int>> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        int maxx = 0;
        for(auto it1 = mp.begin(); it1 != mp.end(); it1++) {
            int x = k;
            for (auto it2 = next(it1); it2 != mp.end(); it2++) {
                if(x/(it1->first - it2->first) >= it2->second){
                    x = x - ((it1->first - it2->first) * it2->second);
                    it1->second += it2->second;
                }else{
                    it1->second += x/(it1->first - it2->first);
                    break;
                }
            }
            maxx = max(maxx, it1->second);
        }
        return maxx;
    }
};