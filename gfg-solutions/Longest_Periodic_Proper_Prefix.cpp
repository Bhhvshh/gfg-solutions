// Problem: Longest_Periodic_Proper_Prefix
// Description: Given a string s, find the length of longest periodic proper prefix of s. If no such prefix exists, return -1.
A periodic proper prefix is a non empty prefix of s (but not the whole string), such that repeating this prefix enough times produces a string that starts with s. Examples: Input: s = "aaaaaa"
Output: 5
Explanation: Repeating the proper prefix "aaaaa" forms "aaaaaaaaaa...", which contains "aaaaa" as a prefix. No longer proper prefix satisfies this. Input: s = "abcab"
Output: 3
Explanation: Repeating the proper prefix "abc" forms "abcabc., which contains "abcab" as a prefix. No longer proper prefix satisfies this. Input: s = "ababd"
Output: -1
Explanation: No proper prefix satisfying the given condition. Constraints:
1 ≤ s.size() ≤ 105
s consists of lowercase English alphabets
// GeeksforGeeks Solution

public:
    int getLongestPrefix(string &s) {
        // code here
        
        int ans = -1;
        int i = 0;
        int n = s.size();
        long long p1 = 1, p2 = 1;
        long long base1 = 31, base2 = 37;
        long long mod1 = 1e9 + 1, mod2 = 1e9 + 7;
        vector<long long> hash1(2,0);
        vector<long long> hash2(2,0);
        
        while(i<n-1){
            
             hash1[0] = (hash1[0] + (((s[i]-'a'+1)*p1) %mod1)) % mod1;
             hash1[1] = (hash1[1] + (((s[i]-'a'+1)*p2) %mod2)) % mod2;
             hash2[0] = ((hash2[0]*base1)%mod1 + (s[n-i-1]-'a'+1)) % mod1;
             hash2[1] = ((hash2[1]*base2)%mod2 + (s[n-i-1]-'a'+1)) % mod2;
             
             if(hash1 == hash2){
                 ans = n-i-1;
                 break;
             }
             
             
             p1=(p1*base1)%mod1;
             p2=(p2*base2)%mod2;
             i++;
             
             
            
        }
        
        return ans;
        
    }
};