#ifndef RSOBUTTON_HPP
#define RSOBUTTON_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include "button.hpp"
#include "rso.hpp"
#include <sstream>
#include <iomanip>
#include "home.hpp"

class RSOButton : public Button {
    private:
    
    Rso rso;

    sf::Text name;
    sf::Text desc;
    sf::Text desc2;
    sf::Text members;
    sf::Text rating;
    sf::Sprite logo;
    sf::Text category;
    sf::Texture texture;
    std::string texture_file;

    std::string arr_categories[7] = {"Aca", "Bus", "Eng", "Ath", "Cul", "Soc", "Gov"};

    public:
    RSOButton() : Button() {};
    RSOButton(int char_size, float x, float y, float width, float height, sf::Font font, std::string text, sf::Color idle_col, sf::Color hover_col, sf::Color activate_col, Rso rso_) 
        : Button(char_size, x, y, width, height, font, text, idle_col, hover_col, activate_col) {
            name.setString(rso_.GetName());
            name.setFont(font);
            name.setCharacterSize(14);
            name.setStyle(sf::Text::Bold);
            name.setFillColor(sf::Color::Black);

            //first line of desc
            std::string temp_desc = rso_.GetInfo();
            std::string new_temp = "";
            bool need_second_line = false;
            for (size_t i = 0; i < 42; i++) {
                if (i < temp_desc.size()) {
                    new_temp += temp_desc[i];
                }
            }
            desc.setString(new_temp);
            desc.setFont(font);
            desc.setCharacterSize(12);
            desc.setFillColor(sf::Color::Black);
            //75
            //second line of desc
            if (temp_desc.size() >= 42) {
                new_temp = "";
                for (size_t i = 42; i < 82; i++) {
                    if (i < temp_desc.size()) {
                        new_temp += temp_desc[i];
                    } else {
                        break;
                    }
                    if (i == 81) {
                        new_temp += "...";
                    }
                }
                desc2.setString(new_temp);
                desc2.setFont(font);
                desc2.setCharacterSize(12);
                desc2.setFillColor(sf::Color::Black);
            }

            members.setString(std::to_string(rso_.GetMembers()) + " members");
            members.setFont(font);
            members.setCharacterSize(12);
            members.setFillColor(sf::Color::Black);
            
            std::stringstream ss;
            ss << std::to_string(rso_.GetRating()) << std::setprecision(2) << std::fixed;
            rating.setString("Rating: " + ss.str() + "/5");
            rating.setFont(font);
            rating.setCharacterSize(14);
            rating.setFillColor(sf::Color::Black);
            
            int category_ = rso_.GetCategory();
            category.setString("Category: " + arr_categories[category_]);
            category.setFont(font);
            category.setCharacterSize(12);
            category.setFillColor(sf::Color::Black);

            texture_file = rso_.GetRSOImage();
            texture.loadFromFile(texture_file);
            logo.setTexture(texture);
            logo.setScale(0.65,0.65);
            
            rso = rso_;
        }
    //void update(const sf::Vector2f mouse_pos);
    //void draw(sf::RenderTarget* target);
    //const bool isPressed() const;

    //setters
    void changeTextPosition(float x, float y);
    void changeTextPosition2(float x, float y);
    void positionImage(float x, float y);
    void positionName(float x, float y);
    void positionCategory(float x, float y);
    void positionRating(float x, float y);
    void positionMembers(float x, float y);

    //getters
    sf::Sprite& getImage();
    sf::Text getName();
    sf::Text getRating();
    sf::Text getDesc();
    sf::Text getDesc2();
    sf::Text getMembers();
    sf::Text getCategory();
    std::string getTextureFile();
    Rso getRSO();
};

#endif