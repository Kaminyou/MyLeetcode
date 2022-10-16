class Solution {
public:
    int reverse(int x) 
{
	int ans = 0;
	while (x)
	{
		int temp = ans * 10 + x % 10;
		if (temp / 10 != ans)
			return 0;
		ans = temp;
		x /= 10;
	}
	return ans;
}
    bool sumOfNumberAndReverse(int num) {
        for (int i = 0; i <= num; ++i) {
            int rev = reverse(i);
            if (i + rev == num) return true;
        }
        return false;
    }
};