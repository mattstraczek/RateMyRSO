#include "button.hpp"


Button::Button(int char_size, float x, float y, float width, float height, sf::Font font, std::string text, sf::Color idle_col, sf::Color hover_col, sf::Color activate_col) {
    button_state = button_states::BTN_IDLE;
    this->font = font;
    shape.setPosition(sf::Vector2f(x,y));
    shape.setSize(sf::Vector2f(width, height));
    this->text.setFont(this->font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::Black);
    this->text.setCharacterSize(char_size);
    this->text.setPosition(shape.getPosition().x + (shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f, shape.getPosition().y + (shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f);
    idle = idle_col;
    hover = hover_col;
    activate = activate_col;
    shape.setFillColor(idle);


}

void Button::update(const sf::Vector2f mouse_pos) {
    button_state = button_states::BTN_IDLE;

    if (shape.getGlobalBounds().contains(mouse_pos)) {
        button_state = button_states::BTN_HOVER;

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            button_state = button_states::BTN_ACTIVE;
        }
    }

    switch (button_state) {
        case button_states::BTN_IDLE:
            shape.setFillColor(idle);
            break;
        case button_states::BTN_HOVER:
            shape.setFillColor(hover);
            break;
        case button_states::BTN_ACTIVE:
            shape.setFillColor(activate);
            break;
        default:
            shape.setFillColor(sf::Color::Red);
            break;
    }
}

void Button::draw(sf::RenderTarget* target) {
    target->draw(shape);
    target->draw(text);
}

const bool Button::isPressed() const {
    if (button_state == button_states::BTN_ACTIVE) {
        return true;
    }
    return false;
}

// void Button::changePosition(float x, float y) {

// }

void Button::changeColor(sf::Color color) {
    shape.setFillColor(color);
}

void Button::changeTextColor(sf::Color color) {
    text.setFillColor(color);
}

void Button::changeTextBold() {
    text.setStyle(sf::Text::Bold);
}

void Button::setFont(sf::Font font_) {
    font = font_;
}

sf::RectangleShape& Button::getShape() {
    return shape;
}
sf::Text& Button::getText(){
    return text;
}

int Button::getState() {
    return button_state;
}