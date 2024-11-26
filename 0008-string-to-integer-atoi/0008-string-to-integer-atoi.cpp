class Solution {
public:
    int myAtoi(string s) {

        int num = 0;
        int i = 0;
        int sign = 1; // positive

        // Ignore leading spaces
        while(i < s.size() && s[i] == ' '){
            i++;
        }

        // Handle optional sign
        if(i < s.size() && (s[i] == '-' || s[i] == '+')){
            sign  = (s[i] == '+') ? 1 : -1;
            ++i;
        }

        // Convert digits to integer
        while(i < s.size() && isdigit(s[i])){
            // Check for overflow/underflow
            if(num > INT_MAX / 10 || (num == INT_MAX / 10 && (s[i] - '0') > 7)){
                return (sign == -1) ? INT_MIN : INT_MAX;
            }
            num = num * 10 + (s[i] - '0');
            ++i;
        }

        return num * sign;
    }
};
