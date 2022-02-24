#include "rsobutton.hpp"

//setters
void RSOButton::changeTextPosition(float x, float y) {
    desc.setPosition(sf::Vector2f(x,y));
}
void RSOButton::changeTextPosition2(float x, float y) {
    desc2.setPosition(sf::Vector2f(x,y));
}
void RSOButton::positionImage(float x, float y) {
    logo.setPosition(sf::Vector2f(x,y));
    int j = 0;
    j++;
}
void RSOButton::positionName(float x, float y) {
    name.setPosition(sf::Vector2f(x,y));
}

void RSOButton::positionCategory(float x, float y) {
    category.setPosition(sf::Vector2f(x,y));
}
void RSOButton::positionRating(float x, float y) {
    rating.setPosition(sf::Vector2f(x,y));
}
void RSOButton::positionMembers(float x, float y) {
    members.setPosition(sf::Vector2f(x,y));
}

//getters

sf::Text RSOButton::getCategory() {
    return category;
}
sf::Sprite& RSOButton::getImage() {
    return logo;
}
sf::Text RSOButton::getName() {
    return name;
}
sf::Text RSOButton::getRating() {
    return rating;
}
sf::Text RSOButton::getDesc() {
    return desc;
}
sf::Text RSOButton::getDesc2() {
    return desc2;
}
sf::Text RSOButton::getMembers() {
    return members;
}

Rso RSOButton::getRSO() {
    return rso;
}

std::string RSOButton::getTextureFile() {
    return texture_file;
}