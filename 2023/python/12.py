with open("../test-cases/inp1.txt", "r") as inpfile:
    sumofcalibval = 0
    wordtonum = {
        "one": "1",
        "two": "2",
        "three": "3",
        "four": "4",
        "five": "5",
        "six": "6",
        "seven": "7",
        "eight": "8",
        "nine": "9"
    }
 
    for line in inpfile:
        digits = []

        for i in range(len(line)): 
            if line[i].isdigit():
                digits.append(line[i])
            elif line[i:i+3] in wordtonum:
                digits.append(wordtonum[line[i:i+3]])
            elif line[i:i+4] in wordtonum:
                digits.append(wordtonum[line[i:i+4]])
            elif line[i:i+5] in wordtonum:
                digits.append(wordtonum[line[i:i+5]])
            
        sumofcalibval += int(digits[0]+digits[-1])

print(f"Sum of all Calibaration Value is: {sumofcalibval}")
inpfile.close()
            
    