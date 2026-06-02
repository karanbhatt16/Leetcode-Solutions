class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int minTime = INT_MAX;
        for (int i = 0; i < landStartTime.size(); i++) {
            for (int j = 0; j < waterStartTime.size(); j++) {
                if (landStartTime[i] < waterStartTime[j]) {
                    if (landStartTime[i] + landDuration[i] > waterStartTime[j]) {
                        minTime = min(minTime, landStartTime[i] + landDuration[i] + waterDuration[j]);
                        continue;
                    }
                    minTime = min(minTime, waterStartTime[j] + waterDuration[j]);
                } else {
                    if (waterStartTime[j] + waterDuration[j] > landStartTime[i]) {
                        minTime = min(minTime, waterStartTime[j] + landDuration[i] + waterDuration[j]);
                        continue;
                    }
                    minTime = min(minTime, landStartTime[i] + landDuration[i]);
                }
            }
        }
        return minTime;
    }
};