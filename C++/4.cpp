// 练习              给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。

//                   回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。



class Solution {
public:
    bool isPalindrome(int x) {
        // 负数、末尾为0且非0的数，直接不是回文
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        
        int reversedHalf = 0;
        // 反转后半部分数字
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }
        
        // 偶数长度：x == reversedHalf；奇数长度：x == reversedHalf / 10
        return x == reversedHalf || x == reversedHalf / 10;
    }
};