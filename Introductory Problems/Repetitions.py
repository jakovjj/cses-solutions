n = input()

base = ''; repetition = 1; max_r = 0
for letter in n:
    if letter == base: repetition += 1
    else: repetition = 1
    base = letter
    if repetition >= max_r:
        max_r = repetition

print(max_r)

            

