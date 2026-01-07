class Solution:
    def countDistinct(self, arr, k):
        from collections import defaultdict

        freq = defaultdict(int)
        result = []

        for i in range(len(arr)):
            # add current element
            freq[arr[i]] += 1

            # remove element going out of window
            if i >= k:
                freq[arr[i - k]] -= 1
                if freq[arr[i - k]] == 0:
                    del freq[arr[i - k]]

            # window size reached
            if i >= k - 1:
                result.append(len(freq))

        return result
