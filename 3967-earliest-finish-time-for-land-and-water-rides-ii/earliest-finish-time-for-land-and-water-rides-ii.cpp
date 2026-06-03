class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        long long ans = LLONG_MAX;

        int n = landStartTime.size();
        int m = waterStartTime.size();

        // ---------- preprocess water rides ----------
        vector<pair<int,int>> water;
        for (int i = 0; i < m; i++) {
            water.push_back({waterStartTime[i], waterDuration[i]});
        }

        sort(water.begin(), water.end());

        vector<int> wStarts(m);
        vector<long long> prefMinDur(m);
        vector<long long> suffMinOpenPlusDur(m);

        for (int i = 0; i < m; i++) {
            wStarts[i] = water[i].first;

            if (i == 0)
                prefMinDur[i] = water[i].second;
            else
                prefMinDur[i] = min(prefMinDur[i - 1],
                                    (long long)water[i].second);
        }

        for (int i = m - 1; i >= 0; i--) {
            long long val =
                (long long)water[i].first + water[i].second;

            if (i == m - 1)
                suffMinOpenPlusDur[i] = val;
            else
                suffMinOpenPlusDur[i] =
                    min(suffMinOpenPlusDur[i + 1], val);
        }

        // land -> water
        for (int i = 0; i < n; i++) {
            long long landEnd =
                (long long)landStartTime[i] + landDuration[i];

            int pos =
                upper_bound(wStarts.begin(), wStarts.end(), landEnd)
                - wStarts.begin();

            if (pos > 0) {
                ans = min(ans,
                          landEnd + prefMinDur[pos - 1]);
            }

            if (pos < m) {
                ans = min(ans,
                          suffMinOpenPlusDur[pos]);
            }
        }

        // ---------- preprocess land rides ----------
        vector<pair<int,int>> land;
        for (int i = 0; i < n; i++) {
            land.push_back({landStartTime[i], landDuration[i]});
        }

        sort(land.begin(), land.end());

        vector<int> lStarts(n);
        vector<long long> prefMinDurLand(n);
        vector<long long> suffMinOpenPlusDurLand(n);

        for (int i = 0; i < n; i++) {
            lStarts[i] = land[i].first;

            if (i == 0)
                prefMinDurLand[i] = land[i].second;
            else
                prefMinDurLand[i] =
                    min(prefMinDurLand[i - 1],
                        (long long)land[i].second);
        }

        for (int i = n - 1; i >= 0; i--) {
            long long val =
                (long long)land[i].first + land[i].second;

            if (i == n - 1)
                suffMinOpenPlusDurLand[i] = val;
            else
                suffMinOpenPlusDurLand[i] =
                    min(suffMinOpenPlusDurLand[i + 1], val);
        }

        // water -> land
        for (int j = 0; j < m; j++) {
            long long waterEnd =
                (long long)waterStartTime[j] + waterDuration[j];

            int pos =
                upper_bound(lStarts.begin(), lStarts.end(), waterEnd)
                - lStarts.begin();

            if (pos > 0) {
                ans = min(ans,
                          waterEnd + prefMinDurLand[pos - 1]);
            }

            if (pos < n) {
                ans = min(ans,
                          suffMinOpenPlusDurLand[pos]);
            }
        }

        return (int)ans;
    }
};