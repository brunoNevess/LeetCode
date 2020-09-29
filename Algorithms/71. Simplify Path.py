class Solution:
    def simplifyPath(self, path: str) -> str:
        
        
        s = []
        v = path.split('/')
        
        #ans = "" 
        for w in v:
                if w == '..':
                        if s:
                                        s.pop()
                elif not w or  w == '.':
                        continue
                else :
                        s.append(w)
        return '/' + '/'.join(s)