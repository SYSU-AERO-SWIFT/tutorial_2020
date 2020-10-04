/*
运行方法，使用命令行: ./longestPalindrome str1 str2 ...
将会输出str1 str2 ... 中的最长回文子串
*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

string longestPalindrome(vector<string>& strs);//获取最长子回文串函数
void getPalind(string str,string &Padm); //获取单个字符串的最长子回文串
void copp(string &A, string &B,int m,int n);

int main(int argc, char ** argv) {
	vector<string>strs(argc-1);
	for (int i = 0; i < argc-1; i++) {
		strs[i] = argv[i+1];
	}//获取字符串
	
	string out = longestPalindrome(strs);
	if (out != "")
		cout << "the longestPalindrome is " << out << endl;
		
	return 0;

}

//采用遍历对称法寻找回文子串，特殊情况为中心为2个重复字母
//使用二维vector存储每一个传入字符串的回文子串
string longestPalindrome(vector<string>& strs) {
	int n = strs.size();//strs数量
	vector<string> Padm(n);//储存子最长回文串的容器
	for(int i = 0; i < n; i++) {
		getPalind(strs[i], Padm[i]);//获取子最长回文串
	}

	string out=Padm[0];//迭代到最终结果
	for (int i = 1; i < n;i++) {
		if (out.size() < Padm[i].size()) {
			out = Padm[i]; //选取最长的回文串
		}
	}
	
	return out;
}

void getPalind(string str, string &Padm) {
	int n = str.size();//str长度
	Padm = "";
	for (int i = 0; i < n-1; i++) {
		if (str[i] == str[i + 1]) {//中心多同字母情况
			int a = i, b = i+1;
			while ( ++b  != n && str[i] == str[b]);//下一个字母也是相同,中心同字母+1
			b--;//b为中心同字母有边界
			while (a - 1 != -1 && b + 1 != n && str[a - 1] == str[b + 1]) {
				a--; b++;
			}//左右也是对称

			if(b-a>Padm.size())copp(Padm, str, a, b);//把该字母位置的子回文串设置为目前最长回文串
		}
		else {//中心单字母情况
			int a = i, b=i;
			while (a - 1 != -1 && b + 1 != n && str[a - 1] == str[b + 1]) {
				a--; b++;
			}//左右也是对称

			if (b - a > Padm.size())copp(Padm, str, a, b);//把该字母位置的子回文串设置为目前最长回文串
		}
	}//遍历到倒数第二个字符
}//获取单个字符串的最长子回文串

void copp(string &A, string &B, int m,int n) {
	A = "";
	for (int i = m; i < n+1; i++) {
		A += B[i];
	}
}//把B的m，n段字符给A
