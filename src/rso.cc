#include "rso.hpp"
#include <iostream>

Rso::Rso(std::string club_name, int c, std::string club_info, int member, double rating) {
    name_ = club_name;
    
    info_ = club_info;
    member_ = member;
    rating_ = rating;
    setCategory(c);
    Review empty_review = Review("NA", "NA");
    AddReview(empty_review);
}

//setters
void Rso::AddReview(Review review) {
    
    reviews_.push_back(review);
    if(no_reviews) {
        no_reviews = false;
        reviews_.erase(reviews_.begin());

    }
}

void Rso::AddReview(std::string author, std::string review) {
    Review new_review = Review(author, review);
    reviews_.push_back(new_review);
    if(no_reviews) {
        no_reviews = false;
        reviews_.erase(reviews_.begin());

    }
}

void Rso::AddReview(std::string author, std::string review, int likes) {
    Review new_review = Review(author, review, likes);
    reviews_.push_back(new_review);
    if(no_reviews) {
        no_reviews = false;
        reviews_.erase(reviews_.begin());

    }
}

void Rso::setInfo(std::string info) {
    info_ = info;
}
void Rso::setName(std::string name) {
    name_ = name;
}


void Rso::setCategory(int n) {
    switch(n) {
        case 0:
            category_ = rso_category::Academic;
            break;
        case 1:
            category_ = rso_category::Academic_Business;
            break;
        case 2:
            category_ = rso_category::Academic_Engineering;
            break;
        case 3:
            category_ = rso_category::Athletics;
            break;
        case 4:
            category_ = rso_category::Cultural;
            break;
        case 5:
            category_ = rso_category::Governance;
            break;
        case 6:
            category_ = rso_category::Social; 
            break;
    }
    
}

void Rso::setRSOImage(std::string file_name) {
    rso_image_ = file_name;
}

void Rso::setLogo(std::string filename) {
    temp_texture_.loadFromFile(filename);
   logo_.setTexture(temp_texture_);
   logo_.setScale(0.65,0.65);
}

//getters
sf::Sprite& Rso::getLogo() {
   return logo_;
}
int Rso::GetRating() {
    return rating_;
}

int Rso::GetMembers() {
    return member_;
}

int Rso::GetCategory() {
    return (int)category_;
}

std::string Rso::GetName() {
    return name_;
}
std::string Rso::GetInfo() {
    return info_;
}

std::vector<Review> Rso::GetReviews() {
    return reviews_;
}

std::string Rso::GetRSOImage() {
    return rso_image_;
}