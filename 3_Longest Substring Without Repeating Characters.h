/**************************************************************************************************
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring
*****************************************************************************************/

class Solution {
public:
//����ַ�������Ascall����
    int lengthOfLongestSubstring(string s) {
        map<char,int> save;
        int len = s.size(), result = 0;
        int start = 0, index = 0;
        while(index < len){
            char c = s[index];
            if(save.find(c) == save.end() || save[c] < start){
            //���û���ҵ�����ַ���˵����ǰ�ַ�û���ظ�
                save[c]= index;
                index++;
            }else{
            //����ҵ�������ַ���˵����ǰ�ַ��ظ�������
                if(result < index - start) result = index - start;
                start = save[c] + 1;
                save[c] = index;
                index++;
            }
        }
        if(result < index - start) result = index - start;
        return result;
    }
};

class Solution {
public:
//����ַ�����Ascall����
    int lengthOfLongestSubstring(string s) {
        vector<int> save(256, -1);
        int len = s.size(), result = 0;
        int start = 0, index = 0;
        while(index < len){
            char c = s[index];
            if(save[c] < start){
            //���û���ҵ�����ַ���˵����ǰ�ַ�û���ظ�
                save[c]= index;
                index++;
            }else{
            //����ҵ�������ַ���˵����ǰ�ַ��ظ�������
                if(result < index - start) result = index - start;
                start = save[c] + 1;
                save[c] = index;
                index++;
            }
        }
        if(result < index - start) result = index - start;
        return result;
    }
};