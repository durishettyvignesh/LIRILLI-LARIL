a, b, c = map(int, input("Enter three numbers: ").split())

# Sort to make sure the largest number is last
a, b, c = sorted([a, b, c])

if a**2 + b**2 == c**2:
    print("The numbers form a Pythagorean triplet.")
else:
    print("The numbers do not form a Pythagorean triplet.")
