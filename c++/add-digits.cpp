class Solution {
public:
    int addDigits(int num) {
        if (num<10) return num;
        int sums = 0;
        while (num) {
            sums += num % 10;
            num /= 10;
        }
        return addDigits(sums);
    }
};