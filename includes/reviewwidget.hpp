#ifndef REVIEWWIDGET_HPP
#define REVIEWWIDGET_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include "rso.hpp"
#include "button.hpp"
#include <iostream>
#include "rsobutton.hpp"
#include "review.hpp"
#include "textbutton.hpp"

class ReviewWidget {
    private:
    
    std::vector<Review> review_list;
    int window_state = 0;
    int max_state = 0;

    sf::RectangleShape background;
    std::vector<Button> buttons;
    Button prev;
    Button next;
    Button sort_likes;
    Button sort_date;

    TextButton add_review;
    Button add_review_button;

    sf::Text text;
    sf::Font font_;

    std::string user_name;

    public:
    ReviewWidget();
    ReviewWidget(std::vector<Review> review_list_, sf::Font &font);
    void InitButtons(sf::Font font);

    void SortLikes();
    void SortDate();

    void update(std::string name, const sf::Vector2f mouse_pos);
    void draw(sf::RenderTarget* target);

    void Pressed(sf::RenderTarget* target, sf::RenderWindow &window);
    void type(sf::Event input);
};

#endif