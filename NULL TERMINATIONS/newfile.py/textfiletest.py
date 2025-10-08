f1=input();f2=input()
try:open(f2,'w').write(open(f1).read())
except FileNotFoundError:print('Source not found:',f1);import sys;sys.exit(1)
print(open(f2).read())

# Note: To test, create args.txt with two lines: first line is source file name, second line is destination file name.