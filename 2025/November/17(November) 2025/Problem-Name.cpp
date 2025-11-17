class Solution {
public:
int maxSumIS(vector<int>& arr) {
int n = arr.size();
vector<int> dp(n);


// Initialize dp with the array values
for(int i = 0; i < n; i++) {
dp[i] = arr[i];
}


// Compute MSIS
for(int i = 1; i < n; i++) {
for(int j = 0; j < i; j++) {
if(arr[j] < arr[i]) {
dp[i] = max(dp[i], dp[j] + arr[i]);
}
}
}


// The answer is the maximum value in dp
return *max_element(dp.begin(), dp.end());
}
};
