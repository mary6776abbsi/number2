#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int RANGE = 9;
    vector<int> counts(RANGE + 1, 0); // یک بردار از اعداد صحیح به نام counts ایجاد می‌کنیم که تعداد تکرار هر عدد را ذخیره می‌کند

    cout << "Enter numbers between 1 and 9 (enter 0 to stop):" << endl; // درخواست ورود اعداد از کاربر

    // ورودی اعداد و به‌روزرسانی تعداد تکرار
    int num;
    while (true) {
        cin >> num;
        if (num < 1 || num > 9) {
            if (num == 0) {
                break; // در صورت ورود عدد صفر، وارد حلقه بعدی شده و ورودی دیگری نمی‌گیریم
            }
            else {
                cout << "Invalid number! Please enter a number between 1 and 9." << endl; // در صورت ورود عدد نامعتبر، پیام خطا چاپ می‌شود و ادامه حلقه اجرا می‌شود
                continue; // از حلقه برمی‌گردیم
            }
        }
        counts[num]++; // تعداد تکرار عدد ورودی را افزایش می‌دهیم
    }

    // یافتن عدد با بیشترین و کمترین تکرار
    int maxCountIndex = 1, minCountIndex = 1;
    for (int i = 2; i <= RANGE; ++i) {
        if (counts[i] > counts[maxCountIndex]) {
            maxCountIndex = i;
        }
        if (counts[i] < counts[minCountIndex]) {
            minCountIndex = i;
        }
    }

    // چاپ تعداد تکرار هر عدد
    cout << "Occurrences of each number:" << endl;
    for (int i = 1; i <= RANGE; ++i) {
        cout << i << ": " << counts[i] << endl;
    }

    // چاپ عدد با بیشترین و کمترین تکرار
    cout << "Number with maximum occurrences: " << maxCountIndex << " (" << counts[maxCountIndex] << " occurrences)" << endl;
    cout << "Number with minimum occurrences: " << minCountIndex << " (" << counts[minCountIndex] << " occurrences)" << endl;

    return 0;
}
