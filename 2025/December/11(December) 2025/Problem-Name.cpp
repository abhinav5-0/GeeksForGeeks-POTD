class Solution {
public:
vector<int> findTwoElement(vector<int>& arr) {
long long n = arr.size();


long long S = n * (n + 1) / 2;
long long P = n * (n + 1) * (2 * n + 1) / 6;
long long sum_arr = 0, sum_sq_arr = 0;


for (long long x : arr) {
sum_arr += x;
sum_sq_arr += 1LL * x * x;
}


long long diff = sum_arr - S; // R - M
long long sq_diff = sum_sq_arr - P; // R^2 - M^2


long long sumRM = sq_diff / diff; // R + M


long long R = (diff + sumRM) / 2;
long long M = sumRM - R;


return {(int)R, (int)M};
}
};
