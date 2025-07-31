class Solution {
  public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        map<int, int> events;

        // Step 1: Convert intervals into events
        for (auto& interval : intervals) {
            events[interval[0]] += 1;
            events[interval[1] + 1] -= 1;
        }

        int count = 0;
        int maxPowerful = -1;

        for (auto it = events.begin(); it != events.end(); ++it) {
            count += it->second;

            auto nextIt = std::next(it);
            if (count >= k) {
                if (nextIt != events.end()) {
                    maxPowerful = max(maxPowerful, nextIt->first - 1);
                } else {
                    maxPowerful = max(maxPowerful, it->first);
                }
            }
        }

        return maxPowerful;
    }
};
