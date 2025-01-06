#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> lines;
    string line;

    while (getline(cin, line)) {
        lines.push_back(line);
    }

    for (size_t i = 0; i < lines.size(); ++i) {
        if (lines[i].find("[Namespace]-(") != string::npos) {
            size_t start = lines[i].find('(') + 1;
            size_t end = lines[i].find(')');
            string exceptionType = lines[i].substr(start, end - start);
            lines[i] = "[Namespace]";
            for (size_t j = i + 1; j < lines.size(); ++j) {
                if (lines[j] == "[Requirement]") {
                    lines[j] = "[Requirement]-(" + exceptionType + ")";
                    break;
                }
            }
        }
    }

    for (const auto& l : lines) {
        cout << l << endl;
    }

    return 0;
}