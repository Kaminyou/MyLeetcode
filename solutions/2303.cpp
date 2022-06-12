class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        if (income == 0) return 0.0;
        double tax = 0.0;
        // first
        int firstTax = brackets[0][0];
        double firstRate = brackets[0][1];
        int firstPay = min(income, firstTax);
        
        tax += (double)firstPay * firstRate / 100;
        income -= firstPay;
        
        int index = 1;
        while (income != 0) {
            int firstTax = brackets[index][0] - brackets[index - 1][0];
            double firstRate = brackets[index][1];
            int firstPay = min(income, firstTax);
            tax += (double)firstPay * firstRate / 100;
            income -= firstPay;
            index++;
        }
        return tax;
    }
};