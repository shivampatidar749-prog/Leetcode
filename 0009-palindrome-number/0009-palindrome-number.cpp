class Solution {
public:
    
    bool isPalindrome(int x) {
        int y=x;
        long rev = 0;
       if (x < 0 || (x % 10 == 0 && x != 0))
        return false;

       int digit;
        while (x > 0) {
            digit=x%10;
            rev = (rev*10)+digit;
            x /= 10;
        }
        if(rev==y){
            return true;
        }
        else{
            return false;
        }
    }
};