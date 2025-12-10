class Solution {
public:
vector<int> findTwoElement(vector<int>& arr) {
long long n = arr.size();


long long S = n * (n + 1) / 2; // sum 1..n
long long S2 = n * (n + 1) * (2*n + 1) / 6; // sum of squares 1..n


long long A = 0, A2 = 0;
for (long long x : arr) {
A += x;
A2 += 1LL * x * x;
}


long long diff1 = A - S; // x - y
long long diff2 = (A2 - S2) / diff1; // x + y


long long repeating = (diff1 + diff2) / 2;
long long missing = repeating - diff1;


return {(int)repeating, (int)missing};
}
};
