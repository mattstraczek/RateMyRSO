#include "event.hpp"
#include "review.hpp"
#include "rso.hpp"
#include "user.hpp"
#include <iostream>
#include "home.hpp"

int main() {


    //----------------------TESTING USER IMPLEMENTATION---------------------------
    //initializing home_screen
    Home home_screen = Home();
    std::cout << "home screen initialized" << std::endl;

    home_screen.InitUsers("user_name_file.txt");

    //adding users that have valid usernames
    std::cout << home_screen.Register("junryuf2", "verysafepassword2021") << std::endl;
    std::cout << home_screen.Register("matt2", "matt'spassword")<< std::endl;
    std::cout << home_screen.Register("ggad2", "cs225")<< std::endl;
    std::cout << home_screen.Register("max", "aerospacerocks")<< std::endl;

    std::cout << "--------------------------------------------------------------------------------------" << std::endl;
    std::cout << "now inserting a copy file with same directory. No new addition should be made here" << std::endl;
    home_screen.InitUsers("user_name_file_copy.txt");

    std::cout << "--------------------------------------------------------------------------------------" << std::endl;
    std::cout << "now inserting a copy file with edited directory. new addition should be made here" << std::endl;
    home_screen.InitUsers("user_name_file_with_new_users.txt");

    std::cout << "--------------------------------------------------------------------------------------" << std::endl;

    //adding users with repeated usernames, that should print unsuccessful messages rather than throw an error
    std::cout << home_screen.Register("max", "dfsdsdfs")<< std::endl;
    std::cout << home_screen.Register(" max", "dfsdsdfs")<< std::endl;

    home_screen.UpdateUsers();
    
    
    //----------------------TESTING RSO IMPLEMENTATION---------------------------

    home_screen.InitRSOs("rso_file.txt");
    Rso RSOtemp1("Awesome Club", 5, "We are the best club in the world. Our ratings are always 5 out of 5!", 10, 5.0);
    home_screen.addToRSOList(RSOtemp1);

    std::cout << "---------------------------------Printing the list of RSO's saved on to the home screen-----------------------------" << std::endl;
    for (size_t i = 0; i < home_screen.getRSOList().size(); i++) {
        std::cout << home_screen.getRSOList()[i].GetName() << std::endl;
    }

    home_screen.SortRSOsRating();

    std::cout << "---------------------------------Printing the list of RSO's saved on to the home screen-----------------------------" << std::endl;
    for (size_t i = 0; i < home_screen.getRSOList().size(); i++) {
        std::cout << home_screen.getRSOList()[i].GetName() << std::endl;
    }

    // home_screen.SortRSOsMembers();

    // std::cout << "---------------------------------Printing the list of RSO's saved on to the home screen-----------------------------" << std::endl;
    // for (size_t i = 0; i < home_screen.getRSOList().size(); i++) {
    //     std::cout << home_screen.getRSOList()[i].GetName() << std::endl;
    // }

    Review my_review = Review("junryuf2", "this club is amazing!");
    home_screen.getRSOList()[0].AddReview(my_review);


    std::cout << "--------------------------------RSO is getting updated to latest--------------------------------" << std::endl;
    home_screen.UpdateRSOs();

}