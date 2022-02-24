#include "review.hpp"
#include <ctime>

Review::Review() {
    submitter_username_ = "";
    review_ = "";

    time_t now = std::time(0);
    
    // convert now to string form
    char* dt = std::ctime(&now);
    // convert now to tm struct for UTC
    tm *gmtm = std::gmtime(&now);
    dt = std::asctime(gmtm);

    date_ = dt;
}
Review::Review(std::string username, std::string review) : submitter_username_(username), review_(review) {
    
    time_t now = std::time(0);
    
    // convert now to string form
    char* dt = std::ctime(&now);
    // convert now to tm struct for UTC
    tm *gmtm = std::gmtime(&now);
    dt = std::asctime(gmtm);
    date_ = dt;
}
Review::Review(std::string username, std::string review, int likes) : submitter_username_(username), review_(review), likes_(likes) {
    
    time_t now = std::time(0);
    
    // convert now to string form
    char* dt = std::ctime(&now);
    // convert now to tm struct for UTC
    tm *gmtm = std::gmtime(&now);
    dt = std::asctime(gmtm);
    date_ = dt;
}

std::string Review::getUserName() {
    return submitter_username_;
}
std::string Review::getReview() {
    return review_;
}
std::string Review::getDate() {
    return date_;
}

int Review::getLikes() {
    return likes_;
}

Button& Review::getLikeButton() {
    return like;
}

void Review::incLikes() {
    likes_++;
}

void Review::positionLike(float x, float y, sf::Font font) {
    Button temp(12, x, y, 25, 25, font, "Like", sf::Color(70,70,70,200), sf::Color(150,150,150,255), sf::Color(20,20,20,200));
    like = temp;
}

void Review::updateLike(const sf::Vector2f mouse_pos) {
    like.update(mouse_pos);
}