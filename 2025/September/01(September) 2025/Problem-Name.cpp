class Solution {
public:
    int sumOfModes(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> freq;  // element -> frequency
        map<int, set<int>> freqToElements; // freq -> elements with that freq
        int sum = 0, maxFreq = 0;

        auto add = [&](int x) {
            int oldFreq = freq[x];
            int newFreq = oldFreq + 1;
            freq[x] = newFreq;

            if (oldFreq > 0) {
                freqToElements[oldFreq].erase(x);
                if (freqToElements[oldFreq].empty())
                    freqToElements.erase(oldFreq);
            }
            freqToElements[newFreq].insert(x);
            maxFreq = max(maxFreq, newFreq);
        };

        auto remove = [&](int x) {
            int oldFreq = freq[x];
            int newFreq = oldFreq - 1;
            freq[x] = newFreq;

            freqToElements[oldFreq].erase(x);
            if (freqToElements[oldFreq].empty())
                freqToElements.erase(oldFreq);

            if (newFreq > 0) {
                freqToElements[newFreq].insert(x);
            }

            if (freqToElements.find(maxFreq) == freqToElements.end())
                maxFreq--;
        };

        // First window
        for (int i = 0; i < k; i++) {
            add(arr[i]);
        }
        sum += *freqToElements[maxFreq].begin();

        // Slide window
        for (int i = k; i < n; i++) {
            add(arr[i]);
            remove(arr[i-k]);
            sum += *freqToElements[maxFreq].begin();
        }

        return sum;
    }
};
