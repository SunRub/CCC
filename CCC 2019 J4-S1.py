#CCC 2019 J4-S1

flips=input() #Flips is the input
TL=1 #Top left = 1
TR=2 #Top right = 2
BL=3 #Bottom left = 3
BR=4 #Bottom right = 4
temp=0 #Temporary storage variable
for flip in flips: #For each character in flips
    if flip=="H": #If H = Horizontal
        temp=TL #Temporary is top left
        TL=BL #Top left becomes bottom left
        BL=temp #Bottom left becomes temporary (old top left)
        temp=TR #Temporary is top right
        TR=BR #Top right becomes bottom right
        BR=temp #Bottom right becomes temporary (old top right)
    elif flip=="V": #If V = Vertical
        temp=TL #Temporary is top left
        TL=TR #Top left becomes top right
        TR=temp #Top right becomes temporary (old top left)
        temp=BL  #Temporary is bottom left
        BL=BR #Bottom left becomes bottom right
        BR=temp #Bottom right becomes temporary (old bottom left)
print("%i %i"%(TL,TR)) #Prints Top Left and Top Right
print("%i %i"%(BL,BR)) #Prints Bottom Left and Bottom Right
        