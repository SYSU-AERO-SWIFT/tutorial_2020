#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string str;     
 string Palindrome(string str,int n);
    cout<<"Please enter a string"<<endl;//提示信息
    getline(cin,str); //输入字符串
    int n=str.size();//获得字符串长度
    cout<<"最大回文子串为:"<<Palindrome(str,n)<<endl;
    return 0;

}

string Palindrome(string str,int n)
{
 string str1;
    string str2;
 string maxpalindrome;
 int length=1;
 for(int i=0;i<n-1;i++)
    {
        for(int j=2;j<=n-i;j++)
        {
            str1=str.substr(i,j); //从i开始截取，每次多截取一个字符长度的字符串
            str2=str.substr(i,j);
            reverse(str1.begin(), str1.end()); //将字符串颠倒
            if(str1==str2) //判断该字符串是否为回文字符串
            {
                if(str2.size()>length) //选取较长的一个作为暂时的最大子串
                {
                    length=str2.size();
                    maxpalindrome=str2;
                }
                 
            }
        }
    }
 return maxpalindrome;
}
