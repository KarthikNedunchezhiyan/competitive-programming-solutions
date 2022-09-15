class Solution {
private:
    vector<int> months_with_31 = {1, 3, 5, 7, 8, 10, 12};

    bool isLeapYear(int year) {
        if (year % 4 != 0) return false;
        if (year % 100 != 0) return true;
        return year % 400 == 0;
    }

public:
    int numberOfDays(int year, int month) {
        if (month == 2)
            return 28 + isLeapYear(year);

        return find(months_with_31.begin(), months_with_31.end(), month) != months_with_31.end() ? 31 : 30;
    }
};
