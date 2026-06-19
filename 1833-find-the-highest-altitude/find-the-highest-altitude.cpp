class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude = 0;
        int altgain = 0;
        int n = gain.size();
        for (int i = 0; i < n; i++) {
            altgain += gain[i];
            altitude = max(altitude, altgain);
        }
        return altitude;
    }
};