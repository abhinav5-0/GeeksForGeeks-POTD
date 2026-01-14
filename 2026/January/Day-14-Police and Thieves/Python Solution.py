def catchThieves(arr, k):
police = []
thief = []


for i in range(len(arr)):
if arr[i] == 'P':
police.append(i)
else:
thief.append(i)


i = j = count = 0


while i < len(police) and j < len(thief):
if abs(police[i] - thief[j]) <= k:
count += 1
i += 1
j += 1
elif police[i] < thief[j]:
i += 1
else:
j += 1


return count
