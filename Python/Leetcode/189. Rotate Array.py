class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # C++ approach
        '''def rev(start, end):
            ee = (end-start)//2+1
            for i in range(ee):
                nums[start+i], nums[end-i] = nums[end-i], nums[start+i]
        
        n = len(nums)
        k = k % n
        ind = n-k
        rev(0, ind-1)
        rev(ind, n-1)
        rev(0, n-1)'''
        
        # Python approach
        n = len(nums)
        k = k % n
        ind = n-k
        nums[:ind] = nums[:ind][::-1]
        nums[ind:] = nums[ind:][::-1]
        nums[:] = nums[::-1]