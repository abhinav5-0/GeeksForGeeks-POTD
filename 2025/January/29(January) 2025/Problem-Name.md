# Power Function Implementation

## Description
This repository contains an efficient implementation of the `power` function in C++, which calculates `b^e` (b raised to the power e) using Exponentiation by Squaring.

## Usage
Compile and run the program with multiple test cases. The function handles edge cases, including negative exponents.

## Code Example
```cpp
class Solution {
  public:
    double power(double b, int e) {
        double result = 1.0;
        long long exponent = e; // Use long long to handle edge cases for e = -109
        
        if (exponent < 0) {
            b = 1 / b;
            exponent = -exponent;
        }
        
        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result *= b;
            }
            b *= b;
            exponent /= 2;
        }
        
        return result;
    }
};
```

## Constraints
- `-100.0 < b < 100.0`
- `-109 <= e <= 109`
- Either `b` is not zero or `e > 0`
- `-10^4 <= b^e <= 10^4`

## License
This project is open-source and available under the MIT License.
