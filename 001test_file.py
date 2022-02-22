# Python program to print all
# Strobogrammatic number of length n
  
# strobogrammatic function 
def strobogrammatic_num(n, s):
      
    result = numdef(n, n, s)
    return result
      
# definition function
def numdef(n, length, s):
    if n == 0: return [""]
    if n == 1:
        if s in ["1", "0", "8"]:
            return [s] 
        else:
            return [""]
      
    middles = numdef(n - 2, length, s)
    result = []
      
    for middle in middles:
        if n != length and "0" in s:            
            result.append("0" + middle + "0")
        if '8' in s:
            result.append("8" + middle + "8")
        if '1' in s:
            result.append("1" + middle + "1")
        if '9' in s and '6' in s:
            result.append("9" + middle + "6")
        if '6' in s and '9' in s:
            result.append("6" + middle + "9")
    return result

print(strobogrammatic_num(4, "109"))