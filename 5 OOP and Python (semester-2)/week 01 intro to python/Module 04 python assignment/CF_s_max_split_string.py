s = input()

cnt_L = 0
cnt_R = 0
mx_string_cnt = 0
string_split = []

for char in s:
      if char == 'L':
            cnt_L += 1
      elif char == 'R':
            cnt_R += 1
      if cnt_L == cnt_R:
        mx_string_cnt += 1
        string_split.append(s[:cnt_L + cnt_R])
        s = s[cnt_L + cnt_R:]
        cnt_L = 0
        cnt_R = 0

print(mx_string_cnt)

for i in string_split:
      print(i)
