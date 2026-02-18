class Solution:
    def merge(self, arr, left, mid, right):
        temp = []
        i, j = left, mid + 1
        inv_count = 0

        while i <= mid and j <= right:
            if arr[i] <= arr[j]:
                temp.append(arr[i])
                i += 1
            else:
                temp.append(arr[j])
                inv_count += (mid - i + 1)
                j += 1

        while i <= mid:
            temp.append(arr[i])
            i += 1

        while j <= right:
            temp.append(arr[j])
            j += 1

        arr[left:right+1] = temp
        return inv_count

    def merge_sort(self, arr, left, right):
        inv_count = 0
        if left < right:
            mid = (left + right) // 2
            inv_count += self.merge_sort(arr, left, mid)
            inv_count += self.merge_sort(arr, mid + 1, right)
            inv_count += self.merge(arr, left, mid, right)
        return inv_count

    def inversionCount(self, arr):
        return self.merge_sort(arr, 0, len(arr) - 1)
