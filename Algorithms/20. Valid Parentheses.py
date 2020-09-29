class Solution:
    def isValid(self, s: str) -> bool:
        d = dict({
            ')':'(',
            '}':'{',
            ']':'['
        })
        close = ['}',')',']']
        stak = []
        l = -1
        for c in s:
            if c in close:
                if len(stak) == 0 or stak[l]!=d[c]:
                    return False
                
                stak.pop()
                l -= 1
            else:
                stak.append(c)
                l += 1
        return len(stak) == 0