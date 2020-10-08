class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        q = [0]
        ans = []
        n = len(nums)
        for i in range(1, k):
            while len(q) > 0 and nums[q[-1]] <= nums[i]:
                q.pop()
            q.append(i)
        ans.append(nums[q[0]])
        for i in range(k, n):
            if q[0] + k == i:
                q.pop(0)
            while len(q) > 0 and nums[q[-1]] <= nums[i]:
                q.pop()
            q.append(i)
            ans.append(nums[q[0]])
        return ans