#include<iostream>
#include<string>
#include<vector>
using namespace std;


/* the interface of function */

string longestPalindromeSingle(string str);
/* the function return the longest palindrome of the single input string*/


vector<string> longestPalindrome(vector<string>& strs);
/* the function process with the input of an array of string*/



vector<string> longestPalindrome(vector<string>& strs){
    vector<string> results; // store the longest palindrome  of each string in strs 
    
    for (int i=0; i<strs.size(); i++){
        // divid into single string for function "longestPalindromeSingle" to processing
        results.push_back(longestPalindromeSingle(strs[i]));
    }
    return results;
}

string longestPalindromeSingle(string orig_str){
    /* @param:      orig_str:    the original string to find its longest palindrome
     * @return:     max_sub_str: the longest palindrome of orig_str
     * @algorithm:  tranverse all postions as center of symmetry, and increase the search length gradually, find the longest palindrome
     */
    
    /* because the center of symmetry may be not the character of input string, (like "abba"), so insert some other character as the symmetry center */
     string str;
    int orig_str_len = orig_str.length();
    for (int i=0; i<orig_str_len; i++){
           str += '#';
           str += orig_str[i];
    }
    str += '#';
    
    // use for recording the maximum infomation
    int max_len = 0;
    string max_sub_str = "";

    for (int center_pos=0; center_pos < str.length(); center_pos++){
        int search_length = 1; // current searching length (reflect the radius of current palindrome)
        
        // the condions consist of index-overflow and palindrome judgement
        while (center_pos >= search_length && center_pos+search_length < str.length() && str[center_pos-search_length] == str[center_pos+search_length])
        {
            search_length += 1;
        }
        
        // repeat once extractly, so decrease by 1
        search_length -= 1;
        
        //update
        if (max_len < search_length*2+1){
            max_len = 2*search_length+1;
            max_sub_str = str.substr(center_pos-search_length, max_len);
        }
    }

    /* delete the assistant characters */
    int del = max_sub_str.find("#");
    while (del != string::npos){
        max_sub_str.replace(del,1, "");
        del = max_sub_str.find("#");
    }
    return max_sub_str;
}

