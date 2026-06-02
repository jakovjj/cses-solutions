n = input()
array = input()
increases = 0

mod_int = []
for m in array.split(" "): 
    m = int(m); mod_int.append(m)

previous_number = 0
for int in mod_int:
    temp = 0
    if int < previous_number:
        temp = previous_number - int
        increases = increases + temp
    previous_number = int + temp

print(increases)
