with open("../test-cases/inp1.txt", "r") as inpfile:
    sumofcalibval = 0
    
    for line in inpfile:
        digits = []
        
        for c in line:
            if c.isdigit():
                digits.append(c)
        
        sumofcalibval += int(digits[0] + digits[-1])

print("Sum of Calibaration Value is: " + str(sumofcalibval))
inpfile.close()