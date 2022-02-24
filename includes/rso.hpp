#ifndef RSO_HPP
#define RSO_HPP

#include <string>
#include "review.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

enum class rso_category {Academic, Academic_Business, Academic_Engineering, Athletics, Cultural, Social, Governance};

class Rso {
    public:
    Rso() = default;
    Rso(std::string club_name, int category, std::string club_info, int member, double rating);

    //setters
    void AddReview(Review review);
    void AddReview(std::string author, std::string review);
    void AddReview(std::string author, std::string review, int likes);
    void setInfo(std::string info);
    void setName(std::string name);
    void setCategory(int n);
    void setRSOImage(std::string file_name);
    void setLogo(std::string filename);

    //getters
    sf::Sprite& getLogo();
    std::string GetName();
    int GetCategory();
    std::string GetInfo();
    int GetRating();
    int GetMembers();
    std::vector<Review> GetReviews();
    std::string GetRSOImage();

    
    private:
    std::string name_ = "";
    std::string info_ = "";
    int member_ = -1;
    double rating_ = -1;
    std::vector<Review> reviews_;
    bool no_reviews = true;
    rso_category category_;
    std::string rso_image_;
    

    sf::Texture temp_texture_;
    sf::Sprite logo_;
    // LinkedList<Events> events_;
};

#endif