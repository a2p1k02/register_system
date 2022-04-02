#ifndef USER_H_
#define USER_H_

#include <map>
#include <string>

class User {
private:
    std::map<std::string, std::string> users;
public:
    explicit User();
    ~User();
    std::map<std::string, std::string>& get_users();
    bool create_user(std::string name, std::string pass);
};

#endif //USER_H_

