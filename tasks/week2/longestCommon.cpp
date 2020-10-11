#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string longestCommon(vector<string>& a){
    if(a.empty())return "";//若为空返回空字串
    int min_strlen=a[0].size();
    for(int i=0;i<a.size();i++){//将每个字符串反转并取得长度的最小值
        reverse(a[i].begin(),a[i].end());
        if(a[i].size()<min_strlen){
            min_strlen=a[i].size();
        }
    }
    int flag=1;
    string ans="";
    for(int i=0;flag&&i<min_strlen;i++){
        for(int j=1;j<a.size();j++){
            if(a[j][i]!=a[j-1][i]){
                flag=0;
                break;
            }
        }
        if(flag){//如果所有字符串某一位相同，则再ans中加上对应元素
            ans.push_back(a[0][i]);
        }
    }
    reverse(ans.begin(),ans.end());//反转ans
    return ans;
}