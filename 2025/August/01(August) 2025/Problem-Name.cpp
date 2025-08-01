class Solution {
public:
    int countBalanced(vector<string>& arr) {
        unordered_map<int, int> balanceCount;
        balanceCount[0] = 1; // Initial balance before any characters
        int currBalance = 0, result = 0;

        for (const string& s : arr) {
            for (char ch : s) {
                if (isVowel(ch))
                    currBalance += 1;
                else
                    currBalance -= 1;

                // If this balance was seen before, it means a balanced substring exists
                result += balanceCount[currBalance];
                balanceCount[currBalance]++;
            }
        }
        return result;
    }

private:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};
