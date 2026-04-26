#include <bits/stdc++.h>
using namespace std;

class MovieTicket {
private:
    unordered_map<int, unordered_set<int>> movieBookings;
    const int MAX_TICKETS = 100;

public:

    bool BOOK(int userId, int movieId) {
        // If already booked
        if (movieBookings[movieId].count(userId)) {
            return false;
        }

        // If full
        if (movieBookings[movieId].size() >= MAX_TICKETS) {
            return false;
        }

        // Book ticket
        movieBookings[movieId].insert(userId);
        return true;
    }

    bool CANCEL(int userId, int movieId) {
        // If not booked
        if (!movieBookings[movieId].count(userId)) {
            return false;
        }

        // Cancel booking
        movieBookings[movieId].erase(userId);
        return true;
    }

    bool IS_BOOKED(int userId, int movieId) {
        return movieBookings[movieId].count(userId);
    }

    int AVAILABLE_TICKETS(int movieId) {
        return MAX_TICKETS - movieBookings[movieId].size();
    }
};

int main() {
    int Q;
    cin >> Q;

    MovieTicket system;

    while (Q--) {
        string query;
        cin >> query;

        if (query == "BOOK") {
            int X, Y;
            cin >> X >> Y;
            cout << (system.BOOK(X, Y) ? "true" : "false") << endl;
        }
        else if (query == "CANCEL") {
            int X, Y;
            cin >> X >> Y;
            cout << (system.CANCEL(X, Y) ? "true" : "false") << endl;
        }
        else if (query == "IS_BOOKED") {
            int X, Y;
            cin >> X >> Y;
            cout << (system.IS_BOOKED(X, Y) ? "true" : "false") << endl;
        }
        else if (query == "AVAILABLE_TICKETS") {
            int Y;
            cin >> Y;
            cout << system.AVAILABLE_TICKETS(Y) << endl;
        }
    }

    return 0;
}