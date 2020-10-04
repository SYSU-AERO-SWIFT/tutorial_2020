#include <iostream>
#include <string>
using namespace std;

int min(int x,int y){//返回两个整型变量中的较小值
    if(x<y)return x;
    else return y;
}

string longestPalindrome(string& s){
  int s_len=s.size();
  int i;
  for(i=1;i<=s_len-1;i++){//在S的每两个相邻字符之间插入@
    s.insert(2*i-1,"@");
  }
  s.insert(0,"$");
  s.insert(s.size(),"#");//在S的首位分别插入$,#
  int a[s.size()];//创建数组以存放与以对应字符为中心的回文串的长度相关的特征值
  for(i=0;i<s.size();i++){
    a[i]=0;
  }
  int right=0,middle=0;//right左侧所有点已被目前为止的回文串覆盖，middle为其中覆盖最靠右元素的回文串的中心
  int max_str=0,max_str_len=-1;//max_str存放最长回文串的中心，max_str_len存放它的长度
  for(i=0;i<s.size();i++){
    if(i==0||i==s.size()-1)continue;
    if(i<right)
      a[i]=min(right-i,a[2*middle-i]);//如果a[i]已经被已有的回文串覆盖,则由回文串的性质可以得到
    else
      a[i]=1;
    while(s[i-a[i]]==s[i+a[i]])
      a[i]++;
    if(right<i+a[i]){//如果以i为中心的回文串可以覆盖更靠右的元素,就更新middle和right
      middle=i;
      right=i+a[i];
    }
    int len;
    if(s[i+a[i]-1]=='@'&&s[i]=='@')len=a[i]-1;//分为四种情况计算对应字符串的实际长度
    else if(s[i+a[i]-1]=='@'&&s[i]!='@')len=a[i]-1;
    else if(s[i+a[i]-1]!='@'&&s[i]!='@')len=a[i];
    else len=a[i];
    if(len>max_str_len){//如果当前的字符串为已知的最长字符串，则更新max_str和max_str_len
      max_str_len=len;
      max_str=i;
    } 
  } 
  string answer;
  for(i=1;s[max_str+i]==s[max_str-i];i++){}//计算以max_str为中心的回文串的长度
  int j;
  for(j=max_str-i+1;j<=max_str+i-1;j++){//得到对应回文串
    if(j%2)answer.push_back(s[j]);
  }
  return answer;
}