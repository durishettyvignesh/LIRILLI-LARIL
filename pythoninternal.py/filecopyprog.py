f1=open('file1.txt','r')
f2=open('f1.txt','w')
data=f1.read()
f2.write(data)
f1.close()
f2.close()

f2.open('f1.txt','r')
c =f2.read()    
print(c)
0