class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        bool check = true;
        int ten = 0;
        int five = 0;
        for (int i = 0; i < bills.size(); i++) {
            int refund = 0;
            if (bills[i] > 5) {
                refund = bills[i] - 5;
                if (refund == 5) {
                    if (five == 0)
                        check = false;
                    else {
                        ten++;
                        five--;
                    }
                } else if (refund == 15) {
                    if (five > 0 && ten > 0) {
                        ten--;
                        five--;
                    } else if (five >= 3) {
                        five -= 3;
                    } else {
                        check = false;
                    }
                }
            } else {
                five++;
            }
        }
        return check;
    }
};