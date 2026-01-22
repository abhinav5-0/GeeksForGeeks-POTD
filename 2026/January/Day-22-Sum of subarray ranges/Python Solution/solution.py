class Solution:
    def subarrayRanges(self, arr):
        n = len(arr)
        pge = [-1]*n
        nge = [n]*n
        pse = [-1]*n
        nse = [n]*n
        st = []

        # Previous Greater
        for i in range(n):
            while st and arr[st[-1]] <= arr[i]:
                st.pop()
            pge[i] = st[-1] if st else -1
            st.append(i)
        st.clear()

        # Next Greater
        for i in range(n-1, -1, -1):
            while st and arr[st[-1]] < arr[i]:
                st.pop()
            nge[i] = st[-1] if st else n
            st.append(i)
        st.clear()

        # Previous Smaller
        for i in range(n):
            while st and arr[st[-1]] >= arr[i]:
                st.pop()
            pse[i] = st[-1] if st else -1
            st.append(i)
        st.clear()

        # Next Smaller
        for i in range(n-1, -1, -1):
            while st and arr[st[-1]] > arr[i]:
                st.pop()
            nse[i] = st[-1] if st else n
            st.append(i)

        maxSum = minSum = 0
        for i in range(n):
            maxSum += arr[i] * (i - pge[i]) * (nge[i] - i)
            minSum += arr[i] * (i - pse[i]) * (nse[i] - i)

        return maxSum - minSum
