#include "rsopage.hpp"

RSOPage::RSOPage(Rso &rso_, sf::Font &font_) {
    rso = rso_;
    font = font_;

    name.setString(rso_.GetName());
    name.setFont(font);
    name.setCharacterSize(32);
    name.setStyle(sf::Text::Bold);
    name.setFillColor(sf::Color::Black);
    name.setPosition(sf::Vector2f(65,80));

    desc_background.setSize(sf::Vector2f(500,500));
    desc_background.setPosition(sf::Vector2f(5, 185));
    desc_background.setFillColor(sf::Color(70,70,70,200));

    description_label.setString("Description:");
    description_label.setFont(font);
    description_label.setCharacterSize(14);
    description_label.setStyle(sf::Text::Bold);
    description_label.setFillColor(sf::Color::Black);
    description_label.setPosition(sf::Vector2f(10,190));

    //desc w/ wrap text
    std::string temp_desc = rso_.GetInfo();
    size_t num_lines = 0;
    if (temp_desc.size()%75 > 0) num_lines = temp_desc.size()/75 + 1;
    else num_lines = temp_desc.size()/75;
    for (size_t j = 0; j < num_lines; j++) {
        std::string new_temp = "";
        for (size_t i = 0; i < 75; i++) {
            if (i + (j*75) < temp_desc.size()) {
                new_temp += temp_desc[i + (j*75)];
            }
        }
        sf::Text temp_desc;
        temp_desc.setString(new_temp);
        temp_desc.setFont(font);
        temp_desc.setCharacterSize(12);
        temp_desc.setFillColor(sf::Color::Black);
        temp_desc.setPosition(sf::Vector2f(10,210 + (15*j)));
        desc.push_back(temp_desc);
    }

    members.setString(std::to_string(rso_.GetMembers()) + " members");
    members.setFont(font);
    members.setCharacterSize(12);
    members.setFillColor(sf::Color::Black);
    members.setPosition(sf::Vector2f(10, 670));

    rating.setString(std::to_string(rso_.GetRating()) + "/5 Stars");
    rating.setFont(font);
    rating.setCharacterSize(26);
    rating.setFillColor(sf::Color::Black);
    rating.setPosition(sf::Vector2f(65, 130));
            
    reviews.setString("Reviews:");
    reviews.setFont(font);
    reviews.setCharacterSize(18);
    reviews.setFillColor(sf::Color::Black);
    reviews.setPosition(sf::Vector2f(520, 80));

    std::string texture_file = rso.GetRSOImage();
    texture.loadFromFile(texture_file);
    logo.setTexture(texture);
    logo.setScale(0.65,0.65);
    logo.setPosition(sf::Vector2f(5,80));

    ReviewWidget temp(rso.GetReviews(), font);
    rev_widget = temp;
}

void RSOPage::update(std::string name, const sf::Vector2f mouse_pos) {
    rev_widget.update(name, mouse_pos);
}

void RSOPage::draw(sf::RenderTarget* target) {
    target->draw(name);
    target->draw(desc_background);
    target->draw(description_label);
    for (size_t i = 0; i < desc.size(); i++) {
        target->draw(desc[i]);
    }
    target->draw(reviews);
    target->draw(logo);
    target->draw(rating);
    target->draw(members);
    rev_widget.draw(target);

}

void RSOPage::presses(sf::RenderTarget* target, sf::RenderWindow &window) {
    rev_widget.Pressed(target, window);
}

void RSOPage::type(sf::Event input) {
    rev_widget.type(input);
}