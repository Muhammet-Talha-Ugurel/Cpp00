#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    this->index = 0;
	while (!std::cin.eof()) {
        std::system("clear");
		std::cin.clear();
		std::cout << TEXT_GREEN;
		std::cout << "\n       ┌──────────────────────────┐\n";
		std::cout << "───────┤ WELCOMDE TO MY PHONEBOOK ├───────\n";
		std::cout << "┌──────────────┬─────────────────────────┐\n";
		std::cout << "│ ADD          │ To add a contact.       │\n";
		std::cout << "├──────────────┼─────────────────────────┤\n";
		std::cout << "│ SEARCH       │ To search for a contact.│\n";
		std::cout << "├──────────────┼─────────────────────────┤\n";
		std::cout << "│ EXIT         │ To quite the PhoneBook. │\n";
		std::cout << "└──────────────┴─────────────────────────┘\n";
		std::cout << TEXT_RESET;
		std::cout << "\nSelect to enter the menu" << TEXT_GREEN << " ▷ " << TEXT_BLUE;
		std::getline(std::cin, this->prompt);
		if (std::cin.eof())
			return ;
		std::cout << TEXT_RESET;
		if (!this->prompt.empty())
		{
			if (this->prompt == "ADD")
				this->addContact();
			else if (this->prompt == "SEARCH")
				this->searchContact();
			else if (this->prompt == "EXIT")
				return ;
			else
				continue;
		}
	}
}

void PhoneBook::addContact() {
    Contact contact;
	std::string name;
	std::string lastname;
	std::string username;
	std::string phone;
	std::string darkestsecret;

    std::system("clear");
	std::cout << TEXT_GREEN;
	std::cout << "            ┌───────────────┐" << std::endl;
	std::cout << "────────────┤  ADD TO BOOK  ├────────" << std::endl;
	std::cout << "┌────────────┬──────────────────────┐" << std::endl;
	std::cout << "│ NAME :     │ "; std::cin >> name;
	std::cout << TEXT_GREEN << "├────────────┼──────────────────────┤" << std::endl;
	std::cout << "│ LASTNAME : │ "; std::cin >> lastname;
	std::cout << TEXT_GREEN << "├────────────┼──────────────────────┤" << std::endl;
	std::cout << "│ USERNAME : │ "; std::cin >> username;
	std::cout << TEXT_GREEN << "├────────────┼──────────────────────┤" << std::endl;
	std::cout << "│ PHONE :    │ "; std::cin >> phone;
	std::cout << TEXT_GREEN << "├────────────┼──────────────────────┤" << std::endl;
	std::cout << "│ DARKEST SECRET : │ "; std::cin >> darkestsecret;
	std::cout << TEXT_GREEN << "└────────────┴──────────────────────┘" << std::endl << TEXT_RESET << std::endl;
	contact.setName(name);
	contact.setSurname(lastname);
	contact.setNickname(username);
	contact.setPhone(phone);
	contact.setDarkestSecret(darkestsecret);
    this->index = this->index % 8;
    contacts[this->index] = contact;
	this->index++;
}

void PhoneBook::searchContact() {
    int index_num;
    int i;

    if (contacts[0].getName().empty()) {
        std::system("clear");
	    std::cout << TEXT_RED;
	    std::cout << "        ┌───────────────────────┐" << std::endl;
	    std::cout << "────────┤  PHONE BOOK IS EMPTY  ├────────" << std::endl;
	    std::cout << TEXT_RESET;
        std::cin.ignore();
        std::system("clear");
        return ;
    }
	while (!std::cin.eof()) {
		i = 0;	
    	std::system("clear");
    	std::cout << TEXT_GREEN;
		std::cout << "        ┌───────────────────────┐" << std::endl;
		std::cout << "────────┤     PHONEBOOK LIST    ├────────" << std::endl;
		std::cout << "┌───┬───────────┬───────────┬───────────┐" << std::endl;
		std::cout << "│ ID│ Name      │ Lastname  │ Username  │" << std::endl;
    	while (contacts[i].getName().empty() == false){
      		std::cout << "├───┼───────────┼───────────┼───────────┤" << std::endl;
      		std::cout << "│ "<< i + 1  << " │" << \
      		std::setw(11) << fixedStr(contacts[i].getName()) << "│" << \
      		std::setw(11) << fixedStr(contacts[i].getSurname()) << "│" << \
      		std::setw(11) << fixedStr(contacts[i].getNickname()) << "│" << std::endl;
      		i++;
			if (i >= 8)
				break;
    	}
		std::cout << "└───┴───────────┴───────────┴───────────┘\n\n";
		std::cout << TEXT_RESET;
		std::cout << "Please enter a the index : " << TEXT_BLUE;
		std::cin >> index_num;
		index_num -= 1;
		if (std::cin.fail()) {
 	       std::cout << TEXT_RED << "\nERROR:" << TEXT_RESET << " incorrect data " << TEXT_L_RED << "\n─────────────────────────────────────\n" << TEXT_RESET;
 	       return;
		}
		if (std::cin.eof())
 	       return ;
		else if (index_num < 0 || index_num > 7 || contacts[index_num].getName().empty())
 	       std::cout << TEXT_RED << "\nERROR:" << TEXT_RESET << "incorrect data" << TEXT_L_RED <<"TRY AGAIN !!!" << "\n─────────────────────────────────────\n" << TEXT_RESET;
		else if (index_num >= 0 && index_num <= 7 )
			break;
	}
	std::string texts[5] = {
		contacts[index_num].getName(),
		contacts[index_num].getSurname(),
		contacts[index_num].getNickname(),
		contacts[index_num].getDarkestSecret(),
		contacts[index_num].getPhone()};
	int spacelen = findLongestStringLength(texts, sizeof(texts) / sizeof(texts[0]));
	int _spacelen = spacelen;
	std::string _draw = "";
	while (spacelen--)
		_draw += "─";
	int titleSpace = contacts[index_num].getNickname().length();
	std::string _titleDraw = "";
	while (titleSpace--)
		_titleDraw += "─";
	std::cout << TEXT_GREEN;
	std::cout << "\n\n        ┌──" << _titleDraw << "───────┐\n";
	std::cout << "────────┤  "<< contacts[index_num].getNickname() << " LIST  ├────────\n";
	std::cout << "┌──────────┬─" << _draw << "─┐\n";
	std::cout << "│       ID │ " << __space(_spacelen, 1)<< TEXT_RED << index_num + 1 << TEXT_GREEN << " │\n";
	std::cout << "├──────────┼─" << _draw << "─┤\n";
	std::cout << "│     NAME │ "  << __space(_spacelen, contacts[index_num].getName().length()) << TEXT_RED << contacts[index_num].getName()<< TEXT_GREEN << " │\n";
	std::cout << "├──────────┼─" << _draw << "─┤\n";
	std::cout << "│ LASTNAME │ " << __space(_spacelen, contacts[index_num].getSurname().length())<< TEXT_RED << contacts[index_num].getSurname()  << TEXT_GREEN << " │\n";
	std::cout << "├──────────┼─" << _draw << "─┤\n";
	std::cout << "│ USERNAME │ "  << __space(_spacelen, contacts[index_num].getNickname().length() )<< TEXT_RED << contacts[index_num].getNickname() << TEXT_GREEN << " │\n";
	std::cout << "├──────────┼─" << _draw << "─┤\n";
	std::cout << "│    PHONE │ "  << __space(_spacelen, contacts[index_num].getPhone().length() ) << TEXT_RED << contacts[index_num].getPhone()<< TEXT_GREEN <<  " │\n";
	std::cout << "├──────────┼─" << _draw << "─┤\n";
	std::cout << "│ DARKNESS │ " << __space(_spacelen, contacts[index_num].getDarkestSecret().length())<< TEXT_RED << contacts[index_num].getDarkestSecret()  << TEXT_GREEN <<  " │\n";
	std::cout << "└──────────┴─" << _draw << "─┘\n\n\n";
	std::cout << TEXT_RESET;
	std::cout << "Press any key to continue...";
    std::cin.ignore();
    std::cin.get();
}

std::string __space(int max, int min)
{
	std::string space = "";
	max -= min;
	while (max--)
		space += " ";
	return space;
}

std::string	fixedStr(std::string str)
{
	if (str.size() >= 11)
		return str.substr(0, 10) + ".";
	else
    return str;
}

int findLongestStringLength(const std::string strings[], size_t size)
{
    size_t maxLength = 0;
    for (size_t i = 0; i < size; ++i) {
        if (strings[i].length() > maxLength) {
            maxLength = strings[i].length();
        }
    }
    return maxLength;
}
