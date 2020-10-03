pattern = 'abacaba'
text = 'abxabacabacabayz'

n = len(text)
m = len(pattern)
lps = [0] * m

i = 0
j = 1
while j < m:
	if pattern[i] == pattern[j]:
		lps[j] = i+1
		i += 1
		j += 1
	else:
		if i == 0:
			lps[j] = 0
			j += 1
		else:
			i = lps[i-1]

i = j = 0
c = 0
while i < n:
	if text[i] == pattern[j]:
		if j == m-1:
			c += 1
			print('At ', i+1-m)
			j = lps[j-1]
		else:
			i += 1
			j += 1
	else:
		if j == 0:
			i += 1
		else:
			j = lps[j-1]
print(c)