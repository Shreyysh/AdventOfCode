with open("../test-cases/inp2.txt", "r") as inpfile:
    sumofid = id = 0
    
    def checkValidity(words):
        for i in range(len(words)):
            if words[i] in ["red", "red;", "red,"]:
                if int(words[i-1]) > 12:
                    return False
            elif words[i] in ["green", "green;", "green,"]:
                if int(words[i-1]) > 13:
                    return False
            elif words[i] in ["blue", "blue;", "blue,"]:
                if int(words[i-1]) > 14:
                    return False
        return True
    
    for line in inpfile:
        id += 1
        words = line.split()
        
        if checkValidity(words):
            sumofid += id

print(f"Sum of IDs of all valid game: {sumofid}")
inpfile.close()        