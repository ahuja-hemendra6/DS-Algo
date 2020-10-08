class Solution:
    def romanToInt(self, s: str) -> int:
        
        def checkNext(ind):
            if ind == n-1:
                return 0
            if s[ind] == "I":
                if s[ind+1] in ["V", "X"]:
                    return d[s[ind+1]] - d[s[ind]]
            if s[ind] == "X":
                if s[ind+1] in ["L", "C"]:
                    return d[s[ind+1]] - d[s[ind]]
            if s[ind] == "C":
                if s[ind+1] in ["D", "M"]:
                    return d[s[ind+1]] - d[s[ind]]
            return 0
        
        d = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}
        ans = 0
        n = len(s)
        i = 0
        while i < n:
            if s[i] in ["I", "X", "C"]:
                val = checkNext(i)
                if val:
                    ans += val
                    i += 2
                    continue
            ans += d[s[i]]
            i += 1
        
        return ans