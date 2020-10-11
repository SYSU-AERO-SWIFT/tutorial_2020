#include<iostream>
#include<string>
#include<cstring>		//including memset 
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        const int len = s.size();
        if(len <= 1)return s;
        bool dp[len][len];	//dp[i][j] represent whether s[i..j] is palindrome or not
        
		memset(dp, 0, sizeof(dp));
        int resLeft = 0, resRight = 0;
        dp[0][0] = true;
        
        for(int i = 1; i < len; i++){
            dp[i][i] = true;
            dp[i][i-1] = true;				//initialize
        }
        
        for(int k = 2; k <= len; k++)			//enumerate the length of substrings
            for(int i = 0; i <= len-k; i++){		//enumerate the initial position of substrings
                if(s[i] == s[i+k-1] && dp[i+1][i+k-2]){
                    dp[i][i+k-1] = true;
                    if(resRight-resLeft+1 < k){
                        resLeft = i;
                        resRight = i+k-1;
                    }
                }
            }
        return s.substr(resLeft, resRight-resLeft+1);
    }
};

int main(){
    Solution lp;	//define a Solution class lp
    string str;		
    cin>>str;		
    cout<<lp.longestPalindrome(str)<<endl;		//call the object longestPalindrome 
    return 0;
}

