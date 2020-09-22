#CCC 2014 J1

A=int(input()) #Input for first angle
B=int(input()) #Input for second angle
C=int(input()) #Input for third angle

if A+B+C!=180: #If the 3 angles do not sum to 180
    print("Error") #Prints error
elif A==B and B==C and A==60: #If A=B=C=60
    print("Equilateral") #Prints equilateral
elif A==B or A==C or B==C: #Not all equal, but if
    print("Isosceles") #Prints isosceles
else: #Else
    print("Scalene") #Prints scalene
