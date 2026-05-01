#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    cout << "猜數字遊戲開始！我選了一個1到100之間的數字。你最多只能猜10次。" << endl;
    while (attempts < 10) {
        cout << "請輸入你的猜測: ";
        cin >> guess;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "輸入無效，請輸入數字。" << endl;
            continue;
        }

        attempts++;
        if (guess > secretNumber) {
            cout << "太大了!" << endl;
        } else if (guess < secretNumber) {
            cout << "太小了!" << endl;
        } else {
            cout << "恭喜你!猜對了!" << endl;
            cout << "你總共猜了 " << attempts << "次。" << endl;
            break;
        }
    }
    if (attempts == 10) {
        cout << "很遺憾，你已經猜了10次，仍然沒有猜中。" << endl;
        cout << "正確答案是" << secretNumber << "。" << endl;
    }
    return 0;
}

