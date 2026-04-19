class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int j = 0;
        int maxdis = 0;
        for (int i = 0; i < nums1.size(); i++) {
            while (j < nums2.size() && nums2[j] >= nums1[i]) {
                j++;
            }
            int dis = j - i - 1;
            maxdis = max(maxdis, dis);
        }
        return maxdis;
    }
};