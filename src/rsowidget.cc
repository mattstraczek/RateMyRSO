#include "rsowidget.hpp"

RSOWidget::RSOWidget(std::vector<Rso> rso_list, sf::Font &font) {
    this->rso_list = rso_list;
    this->font_ = font;
    window_state = 1;
    if (rso_list.size() % 5 > 0) {
        max_state = rso_list.size()/5 + 1;
    } else {
        max_state = rso_list.size()/5;
    }
    
    text.setString("Test");

    background.setSize(sf::Vector2f(500,550));
    background.setFillColor(sf::Color(95,100,255,200));
    background.setPosition(sf::Vector2f(380, 160));

    InitNavigationButtons(font);

    for (size_t i = 0; i < 5; i++) {
        if (i < rso_list.size()) {
            RSOButton temp(12, 400, 190 + (90*i), 460, 85, font, "", sf::Color(240, 210, 255, 255), sf::Color(150,150,150,255), sf::Color(20,20,20,200), rso_list[i]);
            temp.positionImage(410, 205 + (90*i));
            temp.positionName(480, 200 + (90*i));
            temp.positionRating(780, 200 + (90*i));
            temp.positionMembers(780, 220 + (90*i));
            temp.positionCategory(780, 240 + (90*i));
            temp.changeTextPosition(470, 220 + (90*i));
            temp.changeTextPosition2(470, 235 + (90*i));
            buttons.push_back(temp);
        }
        //temp.setFont(this->font);
        
    }

}

void RSOWidget::changeRSOList(std::vector<Rso> rso_list_) {
    rso_list = rso_list_;
     int j = 0;
    for (size_t i = (5*(window_state - 1)); i < (5*(window_state - 1)) + 5; i++) {
        if (i < rso_list.size()) {
            RSOButton temp(12, 400, 190 + (90*j), 460, 85, font_, "", sf::Color(240, 210, 255, 255), sf::Color(150,150,150,255), sf::Color(20,20,20,200), rso_list[i]);
            temp.positionImage(410, 205 + (90*j));
            temp.positionName(480, 200 + (90*j));
            temp.positionRating(780, 200 + (90*j));
            temp.positionMembers(780, 220 + (90*j));
            temp.changeTextPosition(470, 220 + (90*j));
            temp.changeTextPosition2(470, 235 + (90*i));
            temp.positionCategory(780, 240 + (90*j));
            buttons[j] = temp;
            j++;
        }
    }
}

void RSOWidget::InitNavigationButtons(sf::Font font) {
    Button prev_(14, 780.f, 660.f, 30, 30, font, "<", sf::Color(70,70,70,200), sf::Color(150,150,150,255), sf::Color(20,20,20,200));
    Button next_(14, 820.f, 660.f, 30, 30, font, ">", sf::Color(70,70,70,200), sf::Color(150,150,150,255), sf::Color(20,20,20,200));
    prev = prev_;
    next = next_;
}

void RSOWidget::update(std::string name, const sf::Vector2f mouse_pos) {
    user_name = name;

    int j = 0;
    for (size_t i = (5*(window_state - 1)); i < (5*(window_state - 1)) + 5; i++) {
        if (i < rso_list.size()) {
            buttons[j].update(mouse_pos);
        }
        j++;
    }
    next.update(mouse_pos);
    prev.update(mouse_pos);
}

void RSOWidget::draw(sf::RenderTarget* target) {
    //background
    target->draw(background);

    //next button
    target->draw(next.getShape());
    sf::Text temp = next.getText();
    temp.setFont(font_);
    target->draw(temp);

    //prev button
    target->draw(prev.getShape());
    temp = prev.getText();
    temp.setFont(font_);
    target->draw(temp);
    
    //rso buttons
    int j = 0;
    for (size_t i = (5*(window_state - 1)); i < (5*(window_state - 1)) + 5; i++) {
        if (i < rso_list.size()) {
            target->draw(buttons[j].getShape());

            temp = buttons[j].getText();
            temp.setFont(font_);
            target->draw(temp);

            target->draw(buttons[j].getImage());
            sf::Texture temp_text;
            temp_text.loadFromFile(buttons[j].getTextureFile());
            sf::Sprite logo_;
            logo_.setTexture(temp_text);
            logo_.setScale(0.65,0.65);
            logo_.setPosition(sf::Vector2f(410, 205 + (90*j)));
            target->draw(logo_);

            temp = buttons[j].getName();
            temp.setFont(font_);
            target->draw(temp);

            temp = buttons[j].getRating();
            temp.setFont(font_);
            target->draw(temp);

            temp = buttons[j].getMembers();
            temp.setFont(font_);
            target->draw(temp);

            temp = buttons[j].getDesc();
            temp.setFont(font_);
            target->draw(temp);

            temp = buttons[j].getDesc2();
            temp.setFont(font_);
            target->draw(temp);

            temp = buttons[j].getCategory();
            temp.setFont(font_);
            target->draw(temp);
        }
        j++;
    }

}

void RSOWidget::Pressed(sf::RenderTarget* target, sf::RenderWindow &window) {
    sf::CircleShape shape(400.f);
    shape.setFillColor(sf::Color::Green);

    //change state of windows
    if (prev.getState() == button_states::BTN_ACTIVE) {
        if (window_state > 1) {
            window_state--;
            int j = 0;
            for (size_t i = (5*(window_state - 1)); i < (5*(window_state - 1)) + 5; i++) {
                if (i < rso_list.size()) {
                    RSOButton temp(12, 400, 190 + (90*j), 460, 85, font_, "", sf::Color(240, 210, 255, 255), sf::Color(150,150,150,255), sf::Color(20,20,20,200), rso_list[i]);
                    temp.positionImage(410, 205 + (90*j));
                    temp.positionName(480, 200 + (90*j));
                    temp.positionRating(780, 200 + (90*j));
                    temp.positionMembers(780, 220 + (90*j));
                    temp.changeTextPosition(470, 220 + (90*j));
                    temp.changeTextPosition2(470, 235 + (90*j));
                    temp.positionCategory(780, 240 + (90*j));
                    buttons[j] = temp;
                    j++;
                }
            }
        }
    }

    if (next.isPressed()) {
        if (window_state < max_state) {
            window_state++;
            int j = 0;
            for (size_t i = (5*(window_state - 1)); i < (5*(window_state - 1)) + 5; i++) {
                if (i < rso_list.size()) {
                    RSOButton temp(12, 400, 190 + (90*j), 460, 85, font_, "", sf::Color(240, 210, 255, 255), sf::Color(150,150,150,255), sf::Color(20,20,20,200), rso_list[i]);
                    temp.positionImage(410, 205 + (90*j));
                    temp.positionName(480, 200 + (90*j));
                    temp.positionRating(780, 200 + (90*j));
                    temp.positionMembers(780, 220 + (90*j));
                    temp.changeTextPosition(470, 220 + (90*j));
                    temp.changeTextPosition2(470, 235 + (90*j));
                    temp.positionCategory(780, 240 + (90*j));
                    buttons[j] = temp;
                    j++;
                }
            }
        }
    }

    //enter rso page
    int j = 0;
    for (size_t i = (5*(window_state - 1)); i < (5*(window_state - 1)) + 5; i++) {
        if (i < rso_list.size()) {
            if (buttons[j].getState() == button_states::BTN_ACTIVE) {
                window.clear(sf::Color(240, 210, 255, 255));

                //taskbar
                sf::RectangleShape taskbar_background;
                taskbar_background.setPosition(sf::Vector2f(0,0));
                taskbar_background.setSize(sf::Vector2f(window.getSize().x, 70));
                taskbar_background.setFillColor(sf::Color(95,100,255,255));

                //buttons
                Button rso_home(30, (window.getSize().x / 2) - 115.f, 10.f, 200, 50, font_, "RateMyRSO", sf::Color(95,100,255,200), sf::Color(95,100,255,200), sf::Color(95,100,255,200));
                rso_home.changeTextColor(sf::Color(240,210,255,255));
                rso_home.changeTextBold();
                rso_home.changeColor(sf::Color(95,100,255,255));

                //rso page
                RSOPage rso_page(rso_list[i], font_);

                while (window.isOpen()) {

                    sf::Event event;
                    while (window.pollEvent(event)) {
                        if (event.type == sf::Event::Closed)
                            window.close();
                        if (event.type == sf::Event::TextEntered) {
                            rso_page.type(event);
                        }
        
                    }

                    //updating mouse position
                    sf::Vector2f mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                    //background and taskbar
                    window.clear(sf::Color(240, 210, 255, 255));
                    window.draw(taskbar_background);
                    
                    //renders
                    rso_home.draw(target);
                    rso_page.draw(target);

                    //updates
                    rso_home.update(mouse_pos);
                    rso_page.update(user_name, mouse_pos);

                    //presses
                    if (rso_home.isPressed()) {
                        break;
                    }
                    rso_page.presses(target, window);

                    
        
                    
                    window.display();
                }
                //window.clear(sf::Color(240, 210, 255, 255));
                break;
            }
            j++;
        }
    }
    
}
