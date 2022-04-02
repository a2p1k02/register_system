#ifndef INTERFACE_H_
#define INTERFACE_H_

#include "../user/user.h"

#include <vector>
#include <string>

class Interface {
private:
    User user;
    std::vector<std::string> commands;
    std::string current_username = "guest";
    int current_command;
public:
    explicit Interface();
    ~Interface();

    void run();
};

#endif // INTERFACE_H_

