class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int prev=pref[0];
        for(int i=1;i<pref.size();i++){
            int temp=pref[i];
            pref[i]=prev^pref[i];
            prev=temp;
        }
        return pref;
    }
};