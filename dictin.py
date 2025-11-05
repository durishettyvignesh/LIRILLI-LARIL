# Program to demonstrate working with dictionaries in Python

# Creating a dictionary
student = {'stdno': '532', 'stdname': 'Naveen', 'stdage': 21, 'stdcity': 'Hyderabad'}

print("\nDictionary is:", student)

# Accessing specific values
print("\nStudent Name is:", student['stdname'])
print("Student City is:", student['stdcity'])

# Display all keys
print("\nAll Keys in Dictionary:")
for key in student.keys(): 
    print(key)

# Display all values
print("\nAll Values in Dictionary:")
for value in student.values():
    print(value)

# Adding new item
student['phno'] = 9876543210
print("\nDictionary after adding phone number:", student)

# Changing a value
student['stdname'] = 'Madhu'
print("\nDictionary after changing name:", student)

# Removing an item
student.pop('stdage')
print("\nDictionary after removing age:", student)

# Length of dictionary
print("\nLength of Dictionary:", len(student))

# Copying the dictionary
student_copy = student.copy()
print("\nCopied Dictionary:", student_copy)

# Clearing all items
student.clear()
print("\nDictionary after clearing all items:", student)
