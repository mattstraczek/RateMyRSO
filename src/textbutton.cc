#include "textbutton.hpp"


TextButton::TextButton(int char_size, float x, float y, float width, float height, sf::Font font, std::string text, sf::Color idle_col) {
    this->font = font;
    shape.setPosition(sf::Vector2f(x,y));
    shape.setSize(sf::Vector2f(width, height));
    
    this->default_text.setFont(this->font);
    this->default_text.setString(text);
    this->default_text.setFillColor(sf::Color::Black);
    this->default_text.setCharacterSize(char_size);
    this->default_text.setPosition(shape.getPosition().x + (shape.getGlobalBounds().width / 2.f) - this->default_text.getGlobalBounds().width / 2.f, shape.getPosition().y + (shape.getGlobalBounds().height / 2.f) - this->default_text.getGlobalBounds().height / 2.f);
    
    this->textbox.setFont(this->font);
    this->textbox.setString("");
    this->textbox.setFillColor(sf::Color::Black);
    this->textbox.setCharacterSize(char_size);
    this->textbox.setPosition(shape.getPosition().x + 5.f, shape.getPosition().y + 8.f);
    // + (shape.getGlobalBounds().width / 2.f) - this->textbox.getGlobalBounds().width / 2.f, (shape.getGlobalBounds().height / 2.f) - this->textbox.getGlobalBounds().height / 2.f
    idle = idle_col;
    shape.setFillColor(idle);

}

//general textbutton behaviors

void TextButton::type(sf::Event input) {
    if (selected == true) {
        if (has_limit == true && text_out.str().length() < limit) {
            checkInput(input.text.unicode);
        } else if (has_limit == true && text_out.str().length() >= limit && input.text.unicode == keys::DELETE) {
            deleteLastChar();
        } else if (has_limit == false) {
            checkInput(input.text.unicode);
        }
    }
}

void TextButton::checkInput(int char_) {
    if (char_ != keys::DELETE && char_ != keys::ENTER && char_ != keys::ESCAPE && char_ < 128) {
        text_out << static_cast<char>(char_);
    } else if (char_ == keys::DELETE && text_out.str().length() > 0) {
        deleteLastChar();
    }
    textbox.setString(text_out.str() + "_");
}

void TextButton::deleteLastChar() {
    std::string temp = text_out.str();
    std::string new_str = "";
    for (int i = 0; i < temp.length() - 1; i++) {
        new_str += temp[i];
    }
    text_out.str("");
    text_out << new_str;
    textbox.setString(text_out.str() + "_");
}

void TextButton::update(const sf::Vector2f mouse_pos) {
    
    if (!shape.getGlobalBounds().contains(mouse_pos)) {

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            selected = false;
        }
    }

    if (shape.getGlobalBounds().contains(mouse_pos)) {

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            selected = true;
        }
    }

}

void TextButton::draw(sf::RenderTarget* target) {
    target->draw(shape);
    if (selected == false && textbox.getString().getSize() <= 1) {
        target->draw(default_text);
    } else {
        target->draw(textbox);
    }
}

//setters

void TextButton::changeColor(sf::Color color) {
    shape.setFillColor(color);
}

void TextButton::changeTextColor(sf::Color color) {
    default_text.setFillColor(color);
    textbox.setFillColor(color);
}

void TextButton::changeTextBold() {
    default_text.setStyle(sf::Text::Bold);
    textbox.setStyle(sf::Text::Bold);
}

void TextButton::changeLimit(bool choice, int lim) {
    has_limit = choice;
    if (has_limit) {
        limit = lim - 1;
    }
}

//getters

std::string TextButton::getString() {
    std::string temp = textbox.getString();
    std::string new_str = "";
    for (int i = 0; i < temp.length() - 1; i++) {
        new_str += temp[i];
    }
    return new_str;
}

sf::Text TextButton::getTextBox() {
    return textbox;
}

sf::RectangleShape TextButton::getShape() {
    return shape;
}

sf::Text TextButton::getDefaultText() {
    return default_text;
}

bool TextButton::getSelected() {
    return selected;
}