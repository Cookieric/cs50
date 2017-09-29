import cs50

f=cs50.get_float()
c=(5/9)*(f-32)
print("{:.5f}".format(c))

char=cs50.get_char()
if char == "Y" or char=="y":
    print("Yes")
elif char == "N" or char=="n":
    print("No")
else:
    print("error")