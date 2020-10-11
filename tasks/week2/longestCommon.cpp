/*
运行方法，使用命令行: ./longestPalindrome str1 str2 ...
将会输出str1 str2 ... 中的最大公共后缀
*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

string longestCommon(vector<string>& strs);//目标获取最公共后缀函数
string rev(string str); //辅助获字符串的翻转
void copp(string &A, string &B,int n);

int main(int argc, char ** argv) {
	vector<string>strs(argc-1);
	for (int i = 0; i < argc-1; i++) {
		strs[i] = argv[i+1];
	}//获取字符串
	
	string out = longestCommon(strs);// 获取最大公共后缀
	if (out != "")
		cout << "the longestCommon is " << out << endl; //输出后缀
		
	return 0;


}

string longestCommon(vector<string>& strs) {
	int size = strs.size();
	vector<string>revstr(size); 
	for (int i = 0; i < size; i++) {
		revstr[i] = rev(strs[i]);
	}//获取strs的翻转字符串，方便比较前几位的相同
	string out = revstr[0];
	int size_max = revstr[0].size();
	for (int i = 0; i < size - 1; i++) {//对每一个字符串逐次比较
		
		int var;//检测指标
		
		if (size_max > revstr[i + 1].size()) {
			size_max = revstr[i + 1].size();
		}//设定最大后缀长度
		
		int j = 1;
		while (j) {

			var = out.compare(0, size_max, revstr[i + 1], 0, size_max);//比较out与i+1
			if (var == 0) {
				copp(out, revstr[i], size_max);
				j = 0;
			}//相同，把共同的给out,转到下一个比较
			else {
				size_max--;
			}//不同，比较的最大长度减小再次比较
			if (size_max == 0) {
				cout << "no longestCommon" << endl;
				out = "";
				return out;
			}//最大长度以及为0，没有公共后缀
		}
	}
	return rev(out);
	
}

string rev(string str) {
	string out("");
	for (int i = str.size() - 1; i >= 0; i--)
	{
		out += str[i];
	}
	return out;	
}

void copp(string &A, string &B, int n) {
	A = "";
	for (int i = 0; i < n; i++) {
		A += B[i];
	}
}
