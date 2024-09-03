with open("../test-cases/inp2.txt", "r") as inpfile:
    sumofpower = id = 0
    
    def check_minVal(words):
        minRed = minGreen = minBlue = 0
        
        for i in range(len(words)):
            if words[i] in ["red", "red;", "red,"]:
                if int(words[i-1]) > minRed:
                    minRed = int(words[i-1])
            elif words[i] in ["green", "green;", "green,"]:
                if int(words[i-1]) > minGreen:
                    minGreen = int(words[i-1])
            elif words[i] in ["blue", "blue;", "blue,"]:
                if int(words[i-1]) > minBlue:
                    minBlue = int(words[i-1])
        
        return minRed*minGreen*minBlue
    
    for line in inpfile:
        id += 1
        words = line.split()
        
        sumofpower += check_minVal(words)

print(f"\nSum of power is: {sumofpower}")
inpfile.close()
        