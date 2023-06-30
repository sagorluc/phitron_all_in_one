cnt = {}
i = 1
if i not in cnt:
    cnt[i] = 1
    print(cnt)
else:
    cnt[i] += 1

print(cnt)
print(type(cnt))

arr = []
arr.append(10)
arr.append(10)
print(arr)