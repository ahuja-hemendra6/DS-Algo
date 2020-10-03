class Solution {
public:
    
    void swap (int &a, int &b)
    {
        int temp=a;
        a=b;
        b=temp;
    }
    
    void sortColors(vector<int>& nums) {
        int len=nums.size();
        int low=0, mid=0, high=len-1;
        
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[mid], nums[low]);
                low++; mid++;
            }
            else if(nums[mid]==2)
            {
                swap(nums[mid], nums[high]);
                high--;
            }   
            else
                mid++;
        }
    }
};