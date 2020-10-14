from cs50 import get_float

while True:

    # User inputs how much change is owed
    dollars = get_float("Change owed: ")
    if dollars >= 0:
        break

# Round dollars to cents
cents = round(dollars * 100)

# Priority is to use the largest coins possible
q = cents // 25
d = cents % 25 // 10
n = cents % 25 % 10 // 5
p = cents % 25 % 10 % 5 // 1

# Minimum number of coins with which change can be made
print(q + d + n + p)