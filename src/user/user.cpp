#include "user.h"

User::User() {}

User::~User() 
{
    this->users.clear();
}

bool User::create_user(std::string name, std::string pass)
{
    bool user_created = false;
    if (this->users.count(name) < 1) {
        this->users.insert({name, pass});
        user_created = true;
    } else {
        user_created = false;
    }
    return user_created;
}

std::map<std::string, std::string>& User::get_users()
{
    return this->users;
}

