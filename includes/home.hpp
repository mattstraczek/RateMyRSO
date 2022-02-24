#ifndef HOME_HPP
#define HOME_HPP

#include <string>
#include <vector>
#include <map>
#include <cctype>

#include "rso.hpp"
#include "user.hpp"
#include "stdexcept"

class Home {
    public:
    Home();
    void LogIn(std::string u, std::string p); //log in if you have an account where u is username and p is password

    //creates an accounti where u is username and p is password
    //returns the status of the registration
    //if registration fails, it will say "username already exists, please type in a different username"
    //otherwise it will say successful
    std::string Register(std::string u, std::string p); 

    //sort functions
    void SortRSOsRating();
    std::vector<Rso> SortRSOsCategory(rso_category category);
    std::vector<Rso> Search(std::string substring);
    void SortRSOsMembers();

    void InitRSOs(std::string file_name); //initializes rso list upon open
    void UpdateRSOs(); //updates rso text file upon closing

    void InitUsers(std::string file_name); //initializes user list upon open
    void UpdateUsers(); //updates user text file upon closing

    std::string extract_user(std::map<std::string, std::string> user_map); // helper function in iterating through maps
    std::string extract_rso(std::vector<Rso> rso_list); //

    //test setter functions
    void addToRSOList(Rso club);
    void addUser(std::string username, std::string password);

    //test getter functions
    std::vector<Rso>& getRSOList();
    std::map<std::string, std::string>& getUsers();
    bool returnLogStatus();
    std::string getName();
    
    private:
    std::vector<Rso> RSOList;
    //this changes to false when real review is added. Until then, there will be an NA review

    std::map<std::string, std::string> users;
    bool screen_on = false;
    
    //this status tells the viewer whether they can add comments or post reviews
    //initialized when valid log in happens
    bool logged_in = false;
    std::string logged_in_name;
};

#endif