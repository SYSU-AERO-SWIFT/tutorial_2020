#include<iostream>
#include"longestPalindrome.h"
using namespace std;
int main(int argc, char** argv)
{
	// Test fot function 'longestPalindrome'
	
	string sample;
	if (argc > 1)
	{
		sample = argv[1];
	}
	else
	{
		sample = "testabccbaabccba";
	}
	cout << "\nThe longest palindrome in string:\n" << sample << "\nis:\n" << longestPalindrome(sample) << endl;
	return 0;
}
