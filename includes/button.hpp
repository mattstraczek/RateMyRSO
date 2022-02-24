#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>

enum button_states{BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE};

class Button {
    private:
    
    int button_state;

    sf::RectangleShape shape;
    sf::Text text;
    sf::Font font;

    sf::Color idle;
    sf::Color hover;
    sf::Color activate;

    public:
    Button() : button_state(0), shape(), text(), font(), idle(sf::Color::White), hover(sf::Color::White), activate(sf::Color::White) {};
    Button(int char_size, float x, float y, float width, float height, sf::Font font, std::string text, sf::Color idle_col, sf::Color hover_col, sf::Color activate_col);
    
    void update(const sf::Vector2f mouse_pos);
    void draw(sf::RenderTarget* target);
    const bool isPressed() const;
    //void changePosition(float x, float y);

    void changeColor(sf::Color color);
    void changeTextColor(sf::Color color);
    void changeTextBold();
    void setFont(sf::Font font_);

    sf::RectangleShape& getShape();
    sf::Text& getText();
    int getState();
};

#endif