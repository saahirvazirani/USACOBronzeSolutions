#include <iostream>
#include <string>

std::string removeOccurrences(std::string &S, const std::string &T) {
    std::string result;
    for (char &c : S) {
        result.push_back(c);

        if (result.size() >= T.size() && result.substr(result.size() - T.size()) == T) {
            result.resize(result.size() - T.size());
        }
    }
    return result;
}

int main() {
    std::string S, T;

    std::getline(std::cin, S);
    std::getline(std::cin, T);

    std::string result = removeOccurrences(S, T);
    std::cout << result << std::endl;

    return 0;
}
