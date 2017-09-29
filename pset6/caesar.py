import cs50
import sys


s="hello"
c=""
cnt=3
k=0#secret key
for letter in s:
    if k%3==0:
        k=0
    int_letter=ord(letter)
    shift=k%26
    int_letter=int_letter+shift
    if ord('A')<=int_letter and int_letter<=ord('Z') or ord('Z')<=int_letter and int_letter<=ord('a'):
        while int_letter>ord('Z'):
            int_letter=int_letter-26
        c=c+chr(int_letter);
    elif ord('a')<=int_letter and int_letter<=ord('z'):
        while int_letter>ord('z'):
            int_letter=int_letter-26
        c=c+chr(int_letter);
    k+=1
print("plaintext:{}".format(s))
print("ciphertext:{}".format(c));