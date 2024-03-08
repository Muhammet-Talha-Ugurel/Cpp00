#include <iostream>

class Contact {
    private :
        std::string name;
        std::string surname;
        std::string phone;
        std::string nick_name;
        std::string darkest_secret;
    public:
        void setName(std::string name);
        void setSurname(std::string surname);
        void setPhone(std::string phone);
        void setNickname(std::string nick_name);
        void setDarkestSecret(std::string darkest_secret);
        std::string getName();
        std::string getSurname();
        std::string getPhone();
        std::string getNickname();
        std::string getDarkestSecret();
};
