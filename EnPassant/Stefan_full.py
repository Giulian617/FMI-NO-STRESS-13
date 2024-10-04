cine_joaca = input().strip()
tabla = [input().strip() for _ in range(8)]

if cine_joaca == 'W':
	tabla.reverse()

cine_sta = chr(ord('W') ^ ord('B') ^ ord(cine_joaca))
cnt = 0
for i in range(8):
	if tabla[1][i] == cine_joaca and tabla[2][i] == '.' and tabla[3][i] == '.':
		if (i > 0 and tabla[3][i - 1] == cine_sta) or (i < 7 and tabla[3][i + 1] == cine_sta):
			cnt += 1
print(cnt)
