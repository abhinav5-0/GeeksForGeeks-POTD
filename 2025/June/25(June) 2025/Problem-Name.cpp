class Solution {
public:
    bool sameFreq(string& s) {
        unordered_map<char, int> freq;
        unordered_map<int, int> freqCount;

        // Count frequency of each character
        for (char c : s)
            freq[c]++;

        // Count how many characters have each frequency
        for (auto& it : freq)
            freqCount[it.second]++;

        if (freqCount.size() == 1)
            return true; // All characters already have the same frequency

        if (freqCount.size() == 2) {
            auto it = freqCount.begin();
            int f1 = it->first, c1 = it->second;
            ++it;
            int f2 = it->first, c2 = it->second;

            // Check if we can remove one character
            if ((f1 == 1 && c1 == 1) || (f2 == 1 && c2 == 1))
                return true; // One character appears only once

            if ((abs(f1 - f2) == 1) && ((f1 > f2 && c1 == 1) || (f2 > f1 && c2 == 1)))
                return true; // One character has one extra frequency and occurs once
        }

        return false;
    }
};
