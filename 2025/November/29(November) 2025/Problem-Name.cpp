class Solution {
public:
int countSetBits(int n) {
if (n == 0) return 0;


// Largest power of 2 <= n
int x = log2(n);
int power = 1 << x;


// 1. Count of MSB set bits from power to n
int msbBits = n - power + 1;


// 2. Bits from previous full cycles
int bitsBefore = x * (power >> 1);


// 3. Recursively compute remaining part
int rest = countSetBits(n - power);


return msbBits + bitsBefore + rest;
}
};
