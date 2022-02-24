#ifndef TEXTBUTTON_HPP
#define TEXTBUTTON_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <sstream>
#include <iostream>

enum keys{DELETE = 8, ENTER = 13, ESCAPE = 27};

class TextButton {
    private:
    
    size_t limit;
    bool has_limit = false;
    bool selected = false;

    std::ostringstream text_out;

    sf::RectangleShape shape;
    sf::Text default_text;
    sf::Text textbox;
    sf::Font font;

    sf::Color idle;

    public:
    TextButton(int char_size, float x, float y, float width, float height, sf::Font font, std::string text, sf::Color idle_col);
    TextButton() {
        limit = 0;
    };
    //general textbutton behaviors
    void update(const sf::Vector2f mouse_pos);
    void draw(sf::RenderTarget* target);
    const bool isPressed() const;
    void toggle();
    void checkInput(int char_);
    void deleteLastChar();
    void type(sf::Event input);

    //setters
    void changeColor(sf::Color color);
    void changeTextColor(sf::Color color);
    void changeTextBold();
    void changeLimit(bool choice, int lim);

    //getters
    std::string getString();
    sf::Text getTextBox();
    sf::RectangleShape getShape();
    sf::Text getDefaultText();
    bool getSelected();

    TextButton& operator=(const TextButton& rhs) {
        limit = rhs.limit;
        has_limit = rhs.limit;
        selected = rhs.limit;
        shape = rhs.shape;
        default_text = rhs.default_text;
        textbox = rhs.textbox;
        font = rhs.font;
        idle = rhs.idle;

        return *this;
    };
};

#endif