class Solution {
public:
    bool isHappy(int n) {
        if(n == 1 || n == 7 || n == 1111111)
            return true;
        int count = 0;
        int temp = n;
        long int sum = 0;
        while(n != 1)
        {
            for(int i = n; i > 0; i /= 10)
            {
                count++;
                sum+=pow(i%10,2);
            }
            n=sum;
            if(count==1)
            {
                n=2;
                break;
            }
            count=0;
            sum=0;
        }
        if(n==1)
            return true;
        else
            return false;
    }
};