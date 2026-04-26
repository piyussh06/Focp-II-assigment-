#include <iostream>
using namespace std;

class Bank {
private:
    int balance[1001] = {0}; // stores balance
    bool exists[1001] = {0}; // checks if user exists

public:

    bool CREATE(int user, int money) {
        if (!exists[user]) {
            exists[user] = true;
            balance[user] = money;
            return true; // new account created
        } else {
            balance[user] += money;
            return false; // already exists
        }
    }

    bool DEBIT(int user, int money) {
        if (!exists[user] || balance[user] < money) {
            return false;
        }

        balance[user] -= money;
        return true;
    }

    bool CREDIT(int user, int money) {
        if (!exists[user]) {
            return false;
        }

        balance[user] += money;
        return true;
    }

    int BALANCE(int user) {
        if (!exists[user]) {
            return -1;
        }

        return balance[user];
    }
};

int main() {
    int Q;
    cin >> Q;

    Bank bank;

    while (Q--) {
        string query;
        cin >> query;

        if (query == "CREATE") {
            int X, Y;
            cin >> X >> Y;
            cout << (bank.CREATE(X, Y) ? "true" : "false") << endl;
        }
        else if (query == "DEBIT") {
            int X, Y;
            cin >> X >> Y;
            cout << (bank.DEBIT(X, Y) ? "true" : "false") << endl;
        }
        else if (query == "CREDIT") {
            int X, Y;
            cin >> X >> Y;
            cout << (bank.CREDIT(X, Y) ? "true" : "false") << endl;
        }
        else if (query == "BALANCE") {
            int X;
            cin >> X;
            cout << bank.BALANCE(X) << endl;
        }
    }

    return 0;
}