#include "Longest_Palindrome.h"

string longestPalindrome(string& str)
{
    if(str.size() == 0)
        return str;
    
    //begin and end are used to record
    //the index of the longest palindrome substring
    int begin = 0; 
    int end = 0;

    //Create a two-dimension array dp
    //dp is used for dynamic programming
    int len = str.length();
    bool dp[len][len];

    //Initialize dp with value false
    for(int i = 0; i < len; i++)
        for(int j = 0; j < len; j++)
            dp[i][j] = false;

    for(int i = 0; i < len; i++)
    //i is the distance between the first character and the last character
    //of the substring
    {
        for(int j = 0; j < len - i; j++)
        //j is the index of the first character of the substring
        {
            if(i == 0) //if the length of substring is 1, which is i = 0
                dp[j][j + i] = true;
            else if(i == 1 && str[j] == str[j + 1]) //if the length of substring is 2, and the first and the second character are the same
                dp[j][j + i] = true; 
            else if(dp[j + 1][j + i - 1] == true && str[j] == str[j + i]) //if the substring from index j+1 to j+i-1 is palindrome, and the first and the last character are the same
                dp[j][j + i] = true; //then the string from index j to j+i is palindrome

            if(dp[j][j + i] == true) //We traverse the string accroding to the length of substring i, so the longest palindrome substring must be the last being traversed
            {
                begin = j;
                end = j + i;
            }
        }
    }

    return str.substr(begin, end - begin + 1); //return the longest palidnrome substring
}
