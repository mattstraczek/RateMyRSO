#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <map>

class User {
    public:
    User();
    User(std::string username, std::string password);
    
    private:
    std::string username_;
    std::string password_;

};

#endif