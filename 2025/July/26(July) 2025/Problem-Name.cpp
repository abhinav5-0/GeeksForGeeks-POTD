class Solution {
public:
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        int num1 = 0, num2 = 1;  // Initialize to different values
        int count1 = 0, count2 = 0;

        // First pass to find potential candidates
        for (int num : arr) {
            if (num == num1)
                count1++;
            else if (num == num2)
                count2++;
            else if (count1 == 0) {
                num1 = num;
                count1 = 1;
            }
            else if (count2 == 0) {
                num2 = num;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }

        // Second pass to confirm the candidates
        count1 = count2 = 0;
        for (int num : arr) {
            if (num == num1) count1++;
            else if (num == num2) count2++;
        }

        vector<int> result;
        if (count1 > n / 3) result.push_back(num1);
        if (count2 > n / 3) result.push_back(num2);
        
        sort(result.begin(), result.end());
        return result;
    }
};
