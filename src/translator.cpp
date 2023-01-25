#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <vector>

using namespace std;

set<string> make_exit_commands() {
    set<string> exit_commands = { "q", "quit", "e", "exit" };
    return exit_commands;
}

void add(map<string, string>& map, vector<pair<string, string>>& history, string w1, string w2) {
    if (map.find(w1) != map.end()) {
        map[w1] = w2;
    }
    else {
        map.emplace(w1, w2);
    }
    history.emplace_back(w1, w2);
}

void translate(map<string, string>& map, string s) {
    getline(cin, s);
    auto ss = stringstream {};
    ss << s;
    while (!ss.eof()) {
        ss >> s;
        const auto it = map.find(s);
        cout << (it == map.end() ? "???" : it->second) << " ";
    }
    cout << endl;
}

void print(map<string, string>& map) {
    cout << "Traductions:" << endl;
    for (auto elem : map) {
        cout << elem.first << "=>" << elem.second << endl;
    }
}

void print_history(vector<pair<string, string>>& history) {
    cout << "History:" << endl;
    for (auto elem : history) {
        cout << elem.first << "=>" << elem.second << endl;
    }
}

void save(vector<pair<string, string>>& history, string name) {
    ofstream f { name + ".txt" };

    if (f.is_open()) {
        for (auto elem : history) {
            f << elem.first << " " << elem.second << endl;
        }
    }
}

void load(map<string, string>& map, vector<pair<string, string>>& history, string name) {
    map.clear();
    history.clear();

    ifstream f { name + ".txt" };
    string   s {};
    string   s2 {};

    if (f.is_open()) {
        while (f.good()) {
            getline(f, s);
            auto ss = stringstream {};
            ss << s;
            while (!ss.eof()) {
                ss >> s;
                ss >> s2;
                add(map, history, s, s2);
            }
        }
        cout << endl;
    }
}

int main() {
    const auto                   exit_commands = make_exit_commands();
    map<string, string>          map;
    vector<pair<string, string>> history;

    while (true) {
        auto s = string {};
        cin >> s;

        if (exit_commands.find(s) != exit_commands.end()) {
            return 0;
        }
        else if (s == "add") {
            string w1, w2;
            cin >> w1;
            cin >> w2;
            add(map, history, w1, w2);
        }
        else if (s == "translate") {
            translate(map, s);
        }
        else if (s == "print") {
            print(map);
        }
        else if (s == "history") {
            print_history(history);
        }
        else if (s == "save") {
            cin >> s;
            save(history, s);
        }
        else if (s == "load") {
            cin >> s;
            load(map, history, s);
        }
    }

    return 0;
}