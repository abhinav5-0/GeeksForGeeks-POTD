class Solution {
  public:
    int maxPartitions(string &s) {
        unordered_map<char, int> lastIndex;
        int n = s.size();

        // Step 1: Store last occurrence of each character
        for (int i = 0; i < n; i++) {
            lastIndex[s[i]] = i;
        }

        int maxPartitions = 0;
        int currentEnd = 0, prevPartition = -1;

        // Step 2: Iterate to form partitions
        for (int i = 0; i < n; i++) {
            currentEnd = max(currentEnd, lastIndex[s[i]]);
            
            if (i == currentEnd) {  // When we reach the boundary of a partition
                maxPartitions++;
                prevPartition = i;
            }
        }

        return maxPartitions;
    }
};
