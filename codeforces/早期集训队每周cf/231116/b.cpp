#include <iostream>
#include <cctype>

int main() {
    std::string a;
    std::cin >> a;

    std::string result;

    for (char& ch : a) {
        char lowercaseCh = std::tolower(ch);

        if (lowercaseCh != 'a' && lowercaseCh != 'e' && lowercaseCh != 'i' &&
            lowercaseCh != 'o' && lowercaseCh != 'u' && lowercaseCh != 'y') {
            result += '.';
            result += lowercaseCh;
        }
    }

    std::cout << result << std::endl;

    return 0;
}
