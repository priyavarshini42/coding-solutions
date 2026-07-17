class Solution:
    def checkStatus(self, a, b, flag):
        return ((a >= 0) != (b >= 0)) if not flag else (a < 0 and b < 0)