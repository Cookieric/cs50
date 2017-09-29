import cs50
import math

print("O hai! How much change is owed?")
amount=cs50.get_float()
while amount < 0:
    print("O hai! How much change is owed?")
    amount=cs50.get_float()
    
cents = round(amount * 100)
# print("{}".format(cents / 25))
number_of_coins=0
number_of_coins += math.floor(cents / 25)
cents %= 25;

number_of_coins += math.floor(cents / 10)
cents %= 10;

number_of_coins += math.floor(cents / 5)
cents %= 5;
number_of_coins += cents;

print("{}".format(number_of_coins));