#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed random generator (ensures different output every run)
    srand(time(0));

    string name;

    cout << "Enter your name: ";
    getline(cin, name);

    // Handle empty input
    if (name.empty()) {
        cout << "Please enter a valid name 😅" << endl;
        return 0;
    }

    // Excuse templates
    vector<string> excuses = {
        "{name} couldn't finish the assignment because the laptop updated for 6 hours.",
        "{name} tried finishing homework, but the Wi-Fi disappeared suddenly.",
        "{name} was about to submit when the file vanished mysteriously.",
        "{name}'s keyboard stopped working right before submission.",
        "{name} lost all work due to a sudden power cut.",
        "{name} accidentally deleted the assignment at the last moment.",
        "{name}'s system froze just before saving the file.",
        "{name} couldn't complete homework because the charger stopped working.",
        "{name} was ready, but the internet refused to cooperate.",
        "{name}'s file got corrupted and wouldn't open."
    };

    // Random selection
    int index = rand() % excuses.size();
    string excuse = excuses[index];

    // Replace {name} with actual name
    size_t pos = excuse.find("{name}");
    while (pos != string::npos) {
        excuse.replace(pos, 6, name);
        pos = excuse.find("{name}");
    }

    cout << "\n📢 Generated Excuse:\n";
    cout << excuse << endl;

    return 0;
}