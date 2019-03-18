file = open('Keyboard_h.txt','r')
keys = {}
lines = file.readlines()
for line in lines:
	words = line.split(' ')
	key = words[1]
	value = int(words[-1].split('\n')[0], 16)
	keys[key] = value
print(keys)
