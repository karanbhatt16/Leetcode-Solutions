class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {

        //for land
        int n = landStartTime.size();
        int minLandTime = INT_MAX;
        for (int i = 0; i < n; i++) {
            minLandTime = min(minLandTime, landStartTime[i] + landDuration[i]);
        }

        int minWaterTime = INT_MAX;
        int m = waterStartTime.size();
        for (int i = 0; i < m; i++) {
            minWaterTime = min(minWaterTime, waterStartTime[i] + waterDuration[i]);
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int res = max(minWaterTime, landStartTime[i]) + landDuration[i];
            ans = min(ans, res);
        }
        
        for (int i = 0; i < m; i++) {
            int res = max(minLandTime, waterStartTime[i]) + waterDuration[i];
            ans = min(ans, res);
        }
        return ans;
    }
};