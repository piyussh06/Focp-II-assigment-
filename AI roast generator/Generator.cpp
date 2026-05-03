#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed random generator (IMPORTANT for different output each run)
    srand(time(0));

    string name;

    cout << "Enter your name: ";
    getline(cin, name);

    // Handle empty input (basic bug prevention)
    if (name.empty()) {
        cout << "Bro at least type something 💀" << endl;
        return 0;
    }

    // Roast templates
    vector<string> roasts = {
        "{name} writes code so slow that even a turtle switched to Python.",
        "If procrastination were an Olympic sport, {name} would win gold.",
        "{name}'s debugging technique is just staring at the screen.",
        "{name} doesn't write bugs, bugs write themselves out of fear.",
        "{name}'s code has more errors than a failed exam paper.",
        "Even Google asks {name} for better search results.",
        "{name} once tried to fix a bug and created 10 new features.",
        "{name}'s logic is like WiFi — weak and unstable.",
        "{name} doesn't crash programs, programs crash themselves to escape.",
        "If laziness had a face, it would be {name}."
    };

    // Random index
    int randomIndex = rand() % roasts.size();

    string roast = roasts[randomIndex];

    // Replace {name} with actual name
    size_t pos = roast.find("{name}");
    while (pos != string::npos) {
        roast.replace(pos, 6, name);
        pos = roast.find("{name}");
    }

    cout << "\n🔥 Roast Generated:\n";
    cout << roast << endl;

    return 0;
}