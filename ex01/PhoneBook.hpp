#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

# define TEXT_RED       "\x1b[31m"
# define TEXT_GREEN     "\x1b[32m"
# define TEXT_YELLOW    "\x1b[33m"
# define TEXT_BLUE      "\x1b[34m"
# define TEXT_MAGENTA   "\x1b[35m"
# define TEXT_CYAN      "\x1b[36m"
# define TEXT_L_RED     "\x1b[91m"
# define TEXT_L_GREEN   "\x1b[92m"
# define TEXT_L_YELLOW  "\x1b[93m"
# define TEXT_L_BLUE    "\x1b[94m"
# define TEXT_L_MAGENTA "\x1b[95m"
# define TEXT_L_CYAN    "\x1b[96m"
# define TEXT_RESET     "\x1b[0m"

std::string	fixedStr(std::string str);
std::string __space(int max, int min);
int findLongestStringLength(const std::string strings[], size_t size);

class PhoneBook {
    private:
        int index;
    	std::string	prompt;
        Contact contacts[8];
    public:
        PhoneBook();
        void addContact();
        void searchContact();
};
