class Solution {
public:
    int myAtoi(string s) {
        stringstream num(s);
        int x = 0;
        num >> x;
        return x;
    }
};