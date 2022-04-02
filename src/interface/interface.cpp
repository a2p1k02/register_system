#include "interface.h"

#include <fstream>
#include <iostream>
#include <array>
#include <string>

Interface::Interface()
{
    this->commands.push_back("1. Add user");
    this->commands.push_back("2. Show users");
    this->commands.push_back("3. Delete users");
    this->commands.push_back("4. Login");
    this->commands.push_back("5. Logout");
    this->commands.push_back("6. Export to file");
    this->commands.push_back("7. Import from file");
    this->commands.push_back("9. Exit");
}

Interface::~Interface()
{
    std::cout << "Goodbye!" << std::endl;
}

void Interface::run()
{
    while (this->current_command != 9) {
        std::cout << "\n" << current_username << "\n";
        for (auto x : this->commands) {
            std::cout << x << "\n";
        }
        std::cout << "> ";
        std::cin >> this->current_command;

        std::array<std::string, 2> user_data;
        if (this->current_command == 1) {
            std::cout << "Enter username and password: \n";
            std::cout << "Username: ";
            std::cin >> user_data[0];
            std::cout << "Password: ";
            std::cin >> user_data[1];
            if (this->user.create_user(user_data[0], user_data[1])) {
                std::cout << "User added successfully!" << "\n";
            } else {
                std::cout << "User already exists." << "\n";
            }
        } else if (this->current_command == 2) {
            int i = 1;
            for (auto& x : this->user.get_users()) {
                std::cout << "User #" << i << "\nUsername: " << x.first << "\nPassword: " << x.second << "\n";
                i++;
            }
        } else if (this->current_command == 3) {
            std::string user;
            std::cout << "Enter the username what you want to delete: ";
            std::cin >> user;
            if (this->user.get_users().find(user)->first == user) {
                this->user.get_users().erase(user);
                std::cout << "User was deleted.\n";
            } else {
                std::cout << "Something wrong...\n";
            }
        } else if (this->current_command == 4) {
            std::string user;
            std::cout << "Username: ";
            std::cin >> user;
            if (this->user.get_users().find(user)->first == user) {
                std::string password;
                std::cout << "Password: ";
                std::cin >> password;
                if (this->user.get_users().find(user)->second == password) {
                    std::cout << "Login successfully!" << "\n";
                    current_username = user;
                } else {
                    std::cout << "You entered wrong login or password" << "\n";
                }
            }
        } else if (this->current_command == 5) {
            current_username = "guest";
            std::cout << "Logout successfully!" << "\n";
        } else if (this->current_command == 6) {
            std::string file_name;
            std::cout << "Enter file name to export: ";
            std::cin >> file_name;
            std::ofstream file;
            file.open(file_name, std::ios::app);
            for (auto& x : this->user.get_users()) {
                file << x.first << ":" << x.second << std::endl;
            }
            file.close();
        } else if (this->current_command == 7) {
            std::string file_name;
            std::cout << "Enter file name to import: ";
            std::cin >> file_name;
            std::ifstream file;
            std::string line;
            file.open(file_name);
            while (std::getline(file, line, file.widen('\n'))) {
                this->user.create_user(line.substr(0, line.find(":")), 
                        line.substr(line.find(":")+1, line.size()));
            }

            file.close();
        }
    }
}

