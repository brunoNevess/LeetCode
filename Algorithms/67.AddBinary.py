class Solution:
    def addBinary(self, a: str, b: str) -> str:
        #maior,menor = None,None
        if len(a) <= len(b):
            a,b = b,a
        n1,n2 = len(a)-1,len(b)-1
        r = 0
        res = []
        while n1 >=0 and n2 >= 0:
            s = int(a[n1])+int(b[n2]) + r
            r = s//2
            res.append(str(s%2))
            n1 -= 1
            n2 -= 1
        while n1>=0:
            s = int(a[n1]) + r
            res.append(str(s%2))
            r = s//2
            n1 -= 1
        if r == 1:
            res.append(str(r))
        res = res[::-1]
        return "".join(res)
        