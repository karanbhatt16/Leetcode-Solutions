class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<int> copy(arr.begin(), arr.end());
        vector<int> ans;
        int count = 1;
        while (count != 0) {
            count = 0;
            for (int i = 0; i < copy.size(); i++) {
                if (copy[i] == 0) {
                    ans.push_back(arr[i]);
                    copy[i] = -1;
                }else if (copy[i] != -1){
                    copy[i] = copy[i] & (copy[i] - 1);
                    count++;
                }
            }
        }
        return ans;
    }
};