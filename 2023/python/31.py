with open("../test-cases/inp3.txt", "r") as inpfile:
    lines = inpfile.readlines()
    sumofpartno = 0
    symbols = ["-", "#", "=", "*", "+", "@", "$", "&", "/", "%"]
    
    def checkfornum(mL, j):
        
        try:
            if mL[j:j+3].isdigit():
                num = mL[j:j+3]
            elif mL[j:j+2].isdigit() and not mL[j-1].isdigit():
                num = mL[j:j+2]
            elif mL[j].isdigit() and not mL[j-1].isdigit():
                num = mL[j]
            else:
                return ""
        except IndexError:
            pass
        
        return num
    
    for i in range(len(lines)):
        pL = lines[i-1] if i-1 >= 0 else ""
        mL = lines[i]
        nL = lines[i+1] if i+1 < len(lines) else ""
        
        for j in range(len(mL)):
            num = checkfornum(mL, j)
            if num != "":
                if (j-1 >= 0 and (mL[j-1] in symbols)) or (j+len(num) < len(lines) and (mL[j+len(num)] in symbols)):
                    sumofpartno += int(num)
                    print(num)
                else:
                    for k in range(max(j-1, 0), min(j+len(num)+1, len(lines))):
                        if (k < len(pL) and pL[k] in symbols) or (k < len(nL) and nL[k] in symbols):
                            sumofpartno += int(num)
                            print(num)
                            break

print(f"Sum of part numbers is: {sumofpartno}")
inpfile.close()
                    
         
