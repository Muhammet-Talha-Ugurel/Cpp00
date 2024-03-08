#include <iostream>
#include <cctype>

int main(int ac, char** arg) {
    if (ac < 2) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 1;
    }
    else {
        for (int i = 1; i < ac; i++) {
            for (int j = 0; arg[i][j]; j++) {
                std::cout << (char)toupper(arg[i][j]);
            }
        }
    }
    std::cout << std::endl;
    return (0);
}