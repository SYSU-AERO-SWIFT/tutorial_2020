 string longestPalindrome(string s) {
        int size = s.size();
        string ans = "";
        int max = 0;
        for(int i = 0;i < size;i++){
            int count = 0;
            int front = i - 1;
            int back = i + 1;
            string tmp = "";
            tmp.push_back(s[i]);
            count++;
            while (front >= 0 && s[front] == s[i]){
                tmp.push_back(s[front--]);
                count++;
            }
            while (back < size && s[back] == s[i]){
                tmp.push_back(s[back++]);
                count++;
            }
            while (front >=0 && back < size){
                if (s[front] == s[back]){
                    count += 2;
                    tmp.push_back(s[back]);
                    tmp.insert(tmp.begin(),s[front]);
                    front--;
                    back++;
                }
                else break;
            }
            if (count > max) {
                max = count;
                ans = tmp;

            }
        }
        return ans;
    }