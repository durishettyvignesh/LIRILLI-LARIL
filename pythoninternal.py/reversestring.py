class py_reverse:
    def revr(self, strs):
        sp = strs.split()       # split the string into words
        sp.reverse()            # reverse the list of words
        res = " ".join(sp)      # join them back with spaces
        return res


str1 = input("Enter a string with 2 or more words: ")
print("Reverse of string word by word:\n", py_reverse().revr(str1))
