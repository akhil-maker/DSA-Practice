# Python program to print all
# Strobogrammatic number of length n
  
# strobogrammatic function 
from math import log

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

def logLoss(y, yp):
    sum = 0
    for i in range(len(y)):
        if(y[i]==yp[i] or 1-yp[i]<0):
            x = 0
        else:
            x = y[i]*log(yp[i])+(1-y[i])*log(1-yp[i])
        sum += x
    return (-1)*(sum/len(y))

def rsquared(y, yp):
    ym = 0
    for i in y:
        ym += i
    ym = ym/len(y)
    ssr = 0
    sst = 0
    for i in range(len(y)):
        ssr += pow((y[i]-yp[i]), 2)
        sst += pow((y[i]-ym), 2)
    res = ssr/sst
    return 1-res

def adjRsquared(r, n, k):
    res = ((1-pow(r, 2))*(n-1))/(n-k-1)
    return 1-res

# print(strobogrammatic_num(4, "109"))
y = [2, 4, 6, 7]
yp = [2.601, 3.83, 5.059, 7.517]
print(logLoss(y, yp))
print(rsquared(y, yp))
print(adjRsquared(rsquared(y, yp), len(y), 2))