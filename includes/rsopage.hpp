#ifndef RSOPAGE_HPP
#define RSOPAGE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include "rso.hpp"
#include "button.hpp"
#include <iostream>
#include "rsobutton.hpp"
#include "textbutton.hpp"
#include "reviewwidget.hpp"

class RSOPage {
    private:
    
    Rso rso;
    sf::Font font;

    sf::RectangleShape desc_background;
    sf::Text name;
    sf::Text rating;
    sf::Text members;
    std::vector<sf::Text> desc;
    sf::Sprite logo;
    sf::Texture texture;

    sf::Text description_label;


    Button prev;
    Button next;
    Button sort_likes;
    Button sort_date;

    //TextButton add_review;

    sf::Text reviews;
    ReviewWidget rev_widget;

    public:
    RSOPage(Rso &rso_, sf::Font &font_);

    void update(std::string name, const sf::Vector2f mouse_pos);
    void draw(sf::RenderTarget* target);

    void presses(sf::RenderTarget* target, sf::RenderWindow &window);
    void type(sf::Event input);
};

#endif