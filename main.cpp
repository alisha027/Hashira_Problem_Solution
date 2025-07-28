#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <nlohmann/json.hpp>
#include <cctype>
#include <cmath>

using namespace std;
using json = nlohmann::json;
typedef long long ll;

// Decode any base-N string to decimal
ll convertToDecimal(const string& str, int base) {
    ll number = 0;
    for (char ch : str) {
        int digit = isdigit(ch) ? ch - '0' : tolower(ch) - 'a' + 10;
        number = number * base + digit;
    }
    return number;
}

// Lagrange interpolation to compute f(0)
ll computeConstantTerm(const vector<pair<ll, ll>>& coords) {
    int total = coords.size();
    ll result = 0;

    for (int i = 0; i < total; ++i) {
        ll xi = coords[i].first;
        ll yi = coords[i].second;

        ll numerator = 1, denominator = 1;

        for (int j = 0; j < total; ++j) {
            if (i == j) continue;
            numerator *= -coords[j].first;
            denominator *= (xi - coords[j].first);
        }

        result += yi * (numerator / denominator);
    }

    return result;
}

// Process one JSON test case and return the secret
ll handleTestcase(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Failed to open: " << filename << endl;
        return -1;
    }

    json inputJson;
    inputFile >> inputJson;

    int requiredPoints = inputJson["keys"]["k"];
    vector<pair<ll, ll>> values;

    for (auto& entry : inputJson.items()) {
        if (entry.key() == "keys") continue;

        int x = stoi(entry.key());
        int base = stoi(entry.value()["base"].get<string>());
        string encoded = entry.value()["value"];
        ll y = convertToDecimal(encoded, base);

        values.push_back({x, y});
    }

    vector<pair<ll, ll>> selected(values.begin(), values.begin() + requiredPoints);
    return computeConstantTerm(selected);
}

int main() {
    ll answer1 = handleTestcase("testcase1.json");
    ll answer2 = handleTestcase("testcase2.json");

    cout << "Result for Testcase 1: " << answer1 << endl;
    cout << "Result for Testcase 2: " << answer2 << endl;

    return 0;
}
