import heapq

def kthLargest(arr, k):
    pq = []
    result = []
    
    for x in arr:
        heapq.heappush(pq, x)
        
        if len(pq) > k:
            heapq.heappop(pq)
        
        if len(pq) < k:
            result.append(-1)
        else:
            result.append(pq[0])
    
    return result
