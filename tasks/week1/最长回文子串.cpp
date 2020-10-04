#include<iostream>
#include<string>
#include<vector>

using std::string;
using std::vector;

void matchPalindrome (int&, int&, string&);

string longestPalindrome (vector<string> &strs){
    // max_str：表示最长回文子串所属的字符串
    // max_head: 最长回文子串首下标
    // max_tail：最长回文子串的尾下标
    int max_str, max_head, max_tail, max_len=0;

    for(int i = 0; i < strs.size(); i++) {
        int size = strs[i].size(), head, tail;

        for(int j = 0; j < size; j++) {
            head = j;
            matchPalindrome(head, tail, strs[i]);

            if(tail-head+1 > max_len) {
                max_len = tail-head+1;
                max_str = i;
                max_head = head;
                max_tail = tail;
            }
        }
    }

    return strs[max_str].substr(max_head, max_len);
}

// 利用中心扩散法，匹配查找以head为中心的最大子串
// @param head 最大子串首下标的引用
// @param tail 最大子串尾下标的引用
void matchPalindrome (int &head, int &tail, string &str) {
    int size = str.size();
    tail=head;
    
    // 合并相同的字符
    while (tail < size-1 && str[head] == str[tail+1]) 
        tail++;
    
    // 匹配回文字符
    while (head > 0 && tail < size-1 && str[head-1] == str[tail+1]) {
        tail++;
        head--;
    }

}

int main() {
    vector<string> a;
    a.push_back("ccbabdc");
    std::cout << longestPalindrome (a) << std::endl;
    return 0;
}

