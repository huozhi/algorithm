/*
Given a string, 
determine if it is a palindrome, 
considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? 
This is a good question to ask during an interview.

For the purpose of this problem, 
we define empty string as valid palindrome.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = (int)s.length() - 1;
        while (i < j) {
            while (i < j && !isalnum(s[i])) i++;
            while (i < j && !isalnum(s[j])) j--;
            if (tolower(s[i]) != tolower(s[j]))
                return false;
            i++; j--;
        }
        
        return true;
    }
};