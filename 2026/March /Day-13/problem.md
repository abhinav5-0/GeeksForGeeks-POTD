# Generate IP Addresses

## Problem

Given a string `s` containing only digits, return all possible **valid IP address combinations** that can be formed by inserting three dots into `s`.

A valid IP address must be in the form:

```
A.B.C.D
```

Where:

* `A`, `B`, `C`, and `D` are integers between **0 and 255** (inclusive).
* The numbers **cannot contain leading zeros** unless the number itself is `0`.

### Example

**Input**

```
s = "255678166"
```

**Output**

```
["25.56.78.166", "255.6.78.166", "255.67.8.166", "255.67.81.66"]
```

**Explanation**
These are the only valid IP addresses that can be formed.

---

**Input**

```
s = "25505011535"
```

**Output**

```
[]
```

**Explanation**
No valid IP address can be formed.

---

## Constraints

* `1 ≤ s.size() ≤ 16`
* `s` contains only digits (`0-9`)

---

## Approach

An IP address has **4 parts**. Each part:

* Can have **1 to 3 digits**
* Value must be **0 to 255**
* Cannot have **leading zeros** (except `0`)

We try every possible split of the string into **four parts** and check if each part is valid.

Steps:

1. Choose lengths for the first three parts (1 to 3 digits).
2. The remaining characters form the fourth part.
3. Validate each part.
4. If all parts are valid, join them using `.` and add to the result.

Time Complexity: **O(1)** (constant possibilities)

---

## Pseudocode

```
for len1 from 1 to 3
  for len2 from 1 to 3
    for len3 from 1 to 3
        len4 = remaining length
        check validity of all 4 parts
        if valid -> add IP
```

---

## Edge Cases

* String length < 4 → Not possible
* String length > 12 → Not possible
* Parts with leading zeros
* Numbers greater than 255
