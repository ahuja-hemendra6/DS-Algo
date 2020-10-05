class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        def solve(ind, le, curr):
            if le == len(curr):
                # curr and curr[:] are different as curr returns reference. So change is reflected
                # in the array. But curr[:] returns a new array
                output.append(curr[:])
                return
            for i in range(ind, n):
                curr.append(nums[i])
                solve(i+1, l, curr)
                curr.pop()
        
        n = len(nums)
        output = [[]]
        for l in range(1, n+1):
            solve(0, l, [])
        return output