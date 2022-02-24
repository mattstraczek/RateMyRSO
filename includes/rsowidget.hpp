#ifndef RSOWIDGET_HPP
#define RSOWIDGET_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include "rso.hpp"
#include "button.hpp"
#include <iostream>
#include "rsobutton.hpp"
#include "rsopage.hpp"

class RSOWidget {
    private:
    
    std::vector<Rso> rso_list;
    int window_state = 0;
    int max_state = 0;

    sf::RectangleShape background;
    std::vector<RSOButton> buttons;
    Button prev;
    Button next;

    sf::Text text;
    sf::Font font_;

    std::string user_name;
    
    public:
    RSOWidget(std::vector<Rso> rso_list, sf::Font &font);
    void changeRSOList(std::vector<Rso> rso_list_);
    void InitNavigationButtons(sf::Font font);

    void update(std::string name, const sf::Vector2f mouse_pos);
    void draw(sf::RenderTarget* target);

    void Pressed(sf::RenderTarget* target, sf::RenderWindow &window);
    
};

#endif