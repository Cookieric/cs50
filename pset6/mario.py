import cs50

print("height: ", end="")
height = cs50.get_int()

while height < 0 or height > 23:
    print("height: ", end="")
    height = cs50.get_int()

for i in range(height):
    for j in range(height-i-1):
        print(" ", end="")
    for k in range(i+2):
        print("#",end="")
    print("");#default:/n