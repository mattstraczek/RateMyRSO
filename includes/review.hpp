#ifndef REVIEW_HPP
#define REVIEW_HPP

#include <string>
#include "button.hpp"

class Review {
    public:
    Review();
    Review(std::string username, std::string review);
    Review(std::string username, std::string review, int likes);

    //getters
    std::string getUserName();
    std::string getReview();
    std::string getDate();
    int getLikes();
    Button& getLikeButton();

    //setters
    void incLikes();
    void positionLike(float x, float y, sf::Font font);

    void updateLike(const sf::Vector2f mouse_pos);

    private:
    std::string submitter_username_ = "USERNAME";
    std::string review_ = "REVIEW";
    std::string date_ = "DATE POSTED";
    int likes_ = 0;
    Button like;
    
};

#endif