
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        set<pair<int, int>> freeServers;
        set<vector<long long>> busyServers;

        for (int i = 0; i < n; i++) {
            freeServers.insert({servers[i], i});
        }

        vector<int> ans(m);

        for (int i = 0; i < m; i++) {

            while (!busyServers.empty() && (*busyServers.begin())[0] <= i) {
                auto server = *busyServers.begin();
                busyServers.erase(busyServers.begin());

                freeServers.insert({
                    (int)server[1],
                    (int)server[2]
                });
            }

            if (freeServers.empty()) {
                auto server = *busyServers.begin();
                busyServers.erase(busyServers.begin());

                long long availableTime = server[0];
                int weight = server[1];
                int index = server[2];

                ans[i] = index;

                busyServers.insert({
                    availableTime + tasks[i],
                    weight,
                    index
                });
            }
            else {
                auto server = *freeServers.begin();
                freeServers.erase(freeServers.begin());

                int weight = server.first;
                int index = server.second;

                ans[i] = index;

                busyServers.insert({
                    (long long)i + tasks[i],
                    weight,
                    index
                });
            }
        }

        return ans;
    }
};
