//Leetcode link: https://leetcode.com/problems/implement-strstr/

class Solution {
public:
    void create_lps(string pat, int lps[])
    {
        int len=0;
        lps[0]=0;
        for (int i=1; i<pat.length();)
        {
            if(pat[i]==pat[len])
                lps[i++]=++len;
            else
            {
                if(len==0)
                    lps[i++]=0;
                else
                    len=lps[len-1];
            }
        }
    }
    
    int strStr(string haystack, string needle) {
        int pat_len=needle.length(), text_len=haystack.length();
        if(pat_len==0)
            return 0;
        int lps[pat_len];
        create_lps(needle, lps);
        
        int i=0, j=0;
        for (; i<text_len;)
        {
            if(haystack[i]==needle[j])
            {   
                i++;
                j++;
            }
            
            if(j==pat_len)
                return (i-j);
            else if(i<text_len && haystack[i]!=needle[j])
            {
                if(j==0)
                    i++;
                else
                    j=lps[j-1];
            }
        }
        return -1;
    }
};