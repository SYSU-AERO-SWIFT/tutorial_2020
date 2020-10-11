#include<iostream>
#include<string>
#include<vector>
using namespace std;

string longestCommon(vector<string>& strs){
    if (!strs.size()) {
            return "";
    }

    int first_index = 0; // 当前最长后缀在strs[0]中的首位置
    int lenth = strs[0].size(); // 当前最长后缀的长度
    int size = strs[0].size();
    for(int i = 1; i < strs.size(); ++i ){
        if(lenth == 0){
            return "";
        }

        int curr_size = strs[i].size();
        for(int j = 0; j < lenth; ++j ){
            if( j == strs[i].size() ){
                first_index = size-j+1;
                lenth = size-first_index;
            }
            if( strs[0][size-1-j] != strs[i][curr_size-1-j] ){
                //更新first与lenth
                first_index = size-j;
                lenth = size-first_index;
                break;
            }
        }

        if(lenth == 0){
            return "";
        }
    }
    
    return strs[0].substr( first_index, lenth );
}


int main(){
    vector<string> strs;
    int t;
    cin>>t;
    string temp;
    for(int i=0; i<t; ++i){
        cin>>temp;
        strs.push_back(temp);
    }
    cout<<longestCommon(strs)<<endl;
    return 0;
}