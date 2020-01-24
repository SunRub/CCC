#CCC 2019 J1

a3=int(input()) #Team A 3 pointers
a2=int(input()) #Team A 2 pointers
a1=int(input()) #Team A 1 pointers
b3=int(input()) #Team B 3 pointers
b2=int(input()) #Team B 2 pointers
b1=int(input()) #Team B 1 pointers
asum=3*a3+2*a2+a1 #Sum of points for team A
bsum=3*b3+2*b2+b1 #Sum of points for team B
if asum>bsum: #If A has more overall points
    print("A") #Prints A
elif asum<bsum: #Else, if B has more overall points
    print("B") #Prints B
else: #Else (they are equal in points)
    print("T") #Prints T (for tie)