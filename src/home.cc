#include "home.hpp"
#include "rso.hpp"
#include <stdexcept>
#include <fstream>
#include <iostream>

Home::Home() {
    screen_on = true;
}

//if the user has an account, they will be able to log in by accessing the user map stored in home class
void Home::LogIn(std::string u, std::string p) {
    if (users.count(u) > 0) {
        if (users[u] == p) {   
            logged_in = true;
            logged_in_name = u;
        }
    }
}

std::string Home::getName() {
    return logged_in_name;
}

//if the user does not have a log in credential, they can add them selves by registering 
//returns the message displayed on the homescreen about whether the username registration was successful or it failed
std::string Home::Register(std::string u, std::string p) {
    //make sure that the newly created account does not overlap with an existing account. 
    if (users.count(u) > 0) {
        return "username already exists";
    } else {
        //if the account username is unique, make sure that the username does not contain any whitespaces
        for(char x : u) {
            if (x == ' ') {
                return "username has invalid character";
            }
        }
        //if the account username is unique and valid, it will save the password on to a map and return that it registered
        users[u] = p;
        return "successfully registered!";
    }
}

void Home::InitUsers(std::string file_name) {
    std::string user_info;
    std::ifstream user_directory(file_name);
    if(user_directory.is_open()) {
        while(getline(user_directory, user_info)) {
            std::string username = user_info.substr(0,user_info.find(","));
            std::string password = user_info.substr(user_info.find(",") + 1, user_info.length() - user_info.find(","));
            if (!(users.contains(username))) {
                std::cout << "found new username and password in input file" << std::endl;
                std::cout << username << " and the password is " << password << std::endl;
                users[username] = password;
            }
        }
        user_directory.close();
    }

}


//update users to a file user_name_file.txt;
void Home::UpdateUsers() {
    std::ofstream user_directory;
    user_directory.open("user_name_file.txt");
    user_directory << extract_user(users);
    user_directory.close();

}

//helper function in iterating through maps which contains users
std::string Home::extract_user(std::map<std::string, std::string> user_map) {
    std::string returning_txt;
    auto iter = user_map.begin();
    while(iter != user_map.end()) {
        returning_txt += iter->first;
        returning_txt += ",";
        returning_txt += iter->second;
        returning_txt += "\n";
        iter++;
    }
    return returning_txt;
}

void Home::InitRSOs(std::string file_name) {
    std::string rso_info;
    std::ifstream rso_directory(file_name);
    std::vector<Rso> empty;
    RSOList = empty;

    if(rso_directory.is_open()) {
        
        while(getline(rso_directory, rso_info)) {
            std::vector<std::string> infos;
            
            //rso name to be created for the rso class declaration below
            std::string rso_name = rso_info.substr(0,rso_info.find(":"));
            std::cout << rso_name << std::endl;

            

            //rso_infos (plural) saves all the associated information that is extracted from txt of the rso
            std::string rso_infos = rso_info.substr(rso_info.find(":") + 1, rso_info.length() - rso_info.find(":"));
            std::cout << "98rso_infos: " << rso_infos << std::endl;
            

            std::string reviews = rso_infos.substr(rso_infos.find(":"), rso_infos.length() - rso_infos.find(":"));
            std::cout << "The extracted review is " << reviews << std::endl;


            int n = 0;
            //extracting all the information of the rso from rso_infos
            std::string temp = rso_infos.substr(0,rso_infos.find(";"));
            n = rso_infos.find(";") + 1;
            //rso category id to be created for the rso class declaration below
            std::cout << temp << std::endl;
            int rso_categ = std::stoi(temp);
            std::cout << rso_categ << std::endl;

            rso_infos = rso_infos.substr(n, rso_infos.length() - n);
            std::cout << "117rso_infos: " << rso_infos << std::endl;
            n = rso_infos.find(";");
            temp = rso_infos.substr(0,n);
            std::string rso_image_file_name = temp;
            std::cout << temp << std::endl;
            n++;

            rso_infos = rso_infos.substr(n, rso_infos.length() - n);
            std::cout << "127rso_infos: " << rso_infos << std::endl;
            n = rso_infos.find(";");
            temp = rso_infos.substr(0,n);
            std::string rso_description = temp;
            std::cout << temp << std::endl;
            n++;


            rso_infos = rso_infos.substr(n, rso_info.length() - n);
            std::cout << "122rso_infos: " << rso_infos << std::endl;
            n = rso_infos.find(";");
            temp = rso_infos.substr(0,n);
            int rso_members = std::stoi(temp);
            std::cout << rso_members << std::endl;
            n++;

            rso_infos = rso_infos.substr(n, rso_info.length() - n);
            std::cout << "130rso_infos: " << rso_infos << std::endl;
            double rso_rating = std::stod(rso_infos);

            std::cout << rso_rating << std::endl;
            
            Rso newly_added_rso(rso_name, rso_categ, rso_description, rso_members, rso_rating);
            newly_added_rso.setRSOImage(rso_image_file_name);

            while(reviews.find("|") != -1) {
                std::cout << "===============beginning of new review===============" << std::endl;
                
                std::cout << "reviews at the beginning is -->" << reviews << std::endl;
                std::string review_author = reviews.substr(0, reviews.find(";"));
                int n = reviews.find(";");
                
                //trim then author from the extracted string
                reviews = reviews.substr(reviews.find(";") + 1, reviews.length() - reviews.find(";"));
                std::cout << "reviews after trimming name is: " << reviews << std::endl;
                
                //now try to extract the review it self
                std::string review_comments = reviews.substr(0, reviews.find(";"));
                std::cout << "review_comments is " << review_comments << std::endl;
                reviews = reviews.substr(reviews.find(";") , reviews.length() - reviews.find(";"));
                std::cout << "reviews after trimming comment is: "<<  reviews << std::endl;
                
                std::cout << reviews.substr(0, reviews.find("|")) << std::endl;
                int review_likes = std::stoi(reviews.substr(1, reviews.find("|")));
                std::cout << "reviews_likes is: "<<  review_likes<< std::endl;
                
                reviews = reviews.substr(reviews.find("|") + 1, reviews.length() - reviews.find("|") +1);
                std::cout << "reviews after trimming likes is: "<<  reviews << std::endl;
                std::cout << " " << std::endl;

                newly_added_rso.AddReview(review_author, review_comments, review_likes);
            }

            std::cout << "parsing is finished for rso "<< std::endl;


            //issue with THIS LINE BELOW
            RSOList.push_back(newly_added_rso);

        }
        rso_directory.close();
    }

}

void Home::UpdateRSOs() {
    std::ofstream user_directory;
    user_directory.open("rso_file_updated.txt");
    user_directory << extract_rso(RSOList);
    user_directory.close();
}

//helper function in iterating through vectors which contain RSOs
std::string Home::extract_rso(std::vector<Rso> rso_list) {
    std::string returning_txt;
    auto iter = rso_list.begin();
    while(iter != rso_list.end()) {

        returning_txt += iter->GetName();
        returning_txt += ":";
        returning_txt += std::to_string(iter->GetCategory());
        returning_txt += ";";
        returning_txt += iter->GetRSOImage();
        returning_txt += ";";
        returning_txt += iter->GetInfo();
        returning_txt += ";";
        returning_txt += std::to_string(iter->GetMembers());
        returning_txt += ";";
        returning_txt += std::to_string(iter->GetRating());
        returning_txt += ":";
        
        std::vector<Review> reviews = iter->GetReviews();
        auto review_iter = reviews.begin();
        while(review_iter != reviews.end()) {
            returning_txt += review_iter->getUserName();
            returning_txt += ";";
            returning_txt += review_iter->getReview();
            returning_txt += ";";
            returning_txt += std::to_string(review_iter->getLikes());
            // returning_txt += ";";
            // returning_txt += review_iter->getDate();
            returning_txt += "|";
            review_iter++;
        }
        returning_txt += "\n";
        iter++;
    }
    std::cout << "THE RETURNING TEXT FOR EACH RSO: " << returning_txt << std::endl;
    return returning_txt;
}

std::vector<Rso> Home::Search(std::string substring) {
    std::vector<Rso> results;
    std::string lowercase;
    std::string temp;
    for (size_t j = 0; j < substring.size(); j++) {
        lowercase.push_back(tolower(substring[j]));
    }
    for (size_t i = 0; i < RSOList.size(); i++) {
        for (size_t j = 0; j < RSOList[i].GetName().size(); j++) {
            temp.push_back(tolower(RSOList[i].GetName()[j]));
        }
        if (temp.find(lowercase) != std::string::npos){
            results.push_back(RSOList[i]);
        }
        temp = "";
    }
    return results;
}

// sorts rso vector by highest rating to lowest
void Home::SortRSOsRating() {
    // loops through the vector size - 1 times
    for (size_t i = 0; i < RSOList.size() - 1; i++) {
        // loops though the vector size - i - 1 times because smallest will be at the back after one loop
        for (size_t j = 0; j < RSOList.size() - i - 1; j++) {
            // if first is smaller than second, they swap
            if (RSOList.at(j).GetRating() < RSOList.at(j+1).GetRating()) {
                // temp for swaping
                Rso temp = RSOList.at(j);
                RSOList.at(j) = RSOList.at(j+1);
                RSOList.at(j+1) = temp;
            }
        }
    }
}

// sorts rso vector by highest member count to lowest
void Home::SortRSOsMembers() {
    // loops through the vector size - 1 times
    for (size_t i = 0; i < RSOList.size() - 1; i++) {
        // loops though the vector size - i - 1 times because smallest will be at the back after one loop
        for (size_t j = 0; j < RSOList.size() - i - 1; j++) {
            // if first is smaller than second, they swap
            if (RSOList.at(j).GetMembers() < RSOList.at(j+1).GetMembers()) {
                // temp for swaping
                Rso temp = RSOList.at(j);
                RSOList.at(j) = RSOList.at(j+1);
                RSOList.at(j+1) = temp;
            }
        }
    }
}

// returns vector of rsos of same category
std::vector<Rso> Home::SortRSOsCategory(rso_category category) {
    //vector to return
    std::vector<Rso> temp;
    for (size_t i = 0; i < RSOList.size(); i++) {
        //if category of rso is category we are looking for, add to vector
        if (RSOList.at(i).GetCategory() == (int)category) {
            temp.push_back(RSOList.at(i));
        }
    }
    return temp;
}



//test setter functions
void Home::addToRSOList(Rso club) {
    RSOList.push_back(club);
}

void Home::addUser(std::string username, std::string password) {
    std::pair<std::string, std::string> user(username, password);
    users.insert(user);
}

//test getter functions
std::vector<Rso>& Home::getRSOList() {
    return RSOList;
}
std::map<std::string, std::string>& Home::getUsers() {
    return users;
}

bool Home::returnLogStatus() {
    if (logged_in) return true;
    return false;
}