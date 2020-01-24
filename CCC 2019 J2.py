#CCC 2019 J2

L=int(input()) #L is the input
linesL=[] #List of lines
for lines in range(L): #For lines in range L (input)
    line=input() #Line is the input
    linesL.append(line) #Adds line to the list
for objects in linesL: #For objects in the list
    howMany=int((objects.split(" "))[0]) #Number of a certain character is the first part of the split with space
    character=(objects.split(" "))[1] #The character is the second part of the split with space
    print(character*howMany) #Prints the character "howMany" times