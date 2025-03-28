class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        int n = start.size();
        vector<pair<int, int>> activities;
        
        // Store activities as (finish time, start time) pairs
        for (int i = 0; i < n; i++) {
            activities.push_back({finish[i], start[i]});
        }

        // Sort activities by finish time
        sort(activities.begin(), activities.end());

        int count = 1;  // First activity is always selected
        int last_finish = activities[0].first;

        // Select activities that do not overlap
        for (int i = 1; i < n; i++) {
            if (activities[i].second >= last_finish) { 
                count++;
                last_finish = activities[i].first; // Update last selected finish time
            }
        }

        return count;
    }
};
