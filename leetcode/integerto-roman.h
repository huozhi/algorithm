/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution {
public:

    const char five[3] = {'V', 'L', 'D'};
    const char one[4] = {'I', 'X', 'C', 'M'};

    string intToRoman(int num) {
        int div = 1000, i = 3;
        int digits[4];
        while (i>=0) {
            digits[i] = num/div;
            num = num - digits[i]*div;
            i--;
            div/=10;
        }
        string roman = "";
        for (i = 3; i >=0; i--) {
            if (digits[i] == 0) continue;
            if (digits[i] == 9) {
                roman += one[i]; roman += one[i+1];
            }
            else if (digits[i]>=5 && digits[i]<=8) {
                roman += five[i]; roman.append(digits[i]-5, one[i]);
            }
            else if (digits[i] == 4) {
                roman += one[i]; roman += five[i];
            }
            else {
                roman.append(digits[i],one[i]);
            }
       }
       return roman;
    }
};