class Solution {
public:
    int sumOfSquaresOfDigits(int num)
    {
        int sum = 0;

        while (num > 0)
        {
            int digit = num % 10;
            sum += (digit * digit);
            num /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n, fast = n;

        while (1)
        {
            slow = sumOfSquaresOfDigits(slow);
            fast = sumOfSquaresOfDigits(sumOfSquaresOfDigits(fast));

            if (slow == fast)
                break;
        }

        return slow == 1;
    }
};
