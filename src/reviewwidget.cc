#include "reviewwidget.hpp"

ReviewWidget::ReviewWidget() {

}

ReviewWidget::ReviewWidget(std::vector<Review> review_list_, sf::Font &font) {
    this->review_list = review_list_;
    this->font_ = font;
    window_state = 1;
    if (review_list.size() % 5 > 0) {
        max_state = review_list.size()/5 + 1;
    } else {
        max_state = review_list.size()/5;
    }
    
    text.setString("Test");

    background.setSize(sf::Vector2f(650,600));
    background.setFillColor(sf::Color(95,100,255,200));
    background.setPosition(sf::Vector2f(600, 85));

    TextButton temp(12, 610, 605, 560, 70, font, "Type review...", sf::Color(240, 210, 255, 255));
    add_review = temp;

    Button temp2(12, 1180, 605, 60, 70, font, "Add review", sf::Color(62,255,26,200), sf::Color(150,150,150,255), sf::Color(20,20,20,200));
    add_review_button = temp2;

    InitButtons(font);

    for (size_t i = 0; i < 5; i++) {
        if (i < review_list.size()) {
            review_list.at(i).positionLike(960, 205 + (90*i), font);
        }
    }

}

void ReviewWidget::InitButtons(sf::Font font) {
    Button prev_(14, 1170.f, 565.f, 30, 30, font, "<", sf::Color(70,70,70,200), sf::Color(150,150,150,255), sf::Color(20,20,20,200));
    Button next_(14, 1210.f, 565.f, 30, 30, font, ">", sf::Color(70,70,70,200), sf::Color(150,150,150,255), sf::Color(20,20,20,200));
    prev = prev_;
    next = next_;
    Button sort_likes_(12, 850, 565, 100, 30, font, "Sort by likes", sf::Color(70,70,70,200), sf::Color(150,150,150,255), sf::Color(20,20,20,200));
    Button sort_date_(12, 970, 565, 100, 30, font, "Sort by date", sf::Color(70,70,70,200), sf::Color(150,150,150,255), sf::Color(20,20,20,200));
    sort_likes = sort_likes_;
    sort_date = sort_date_;
    int j = 0;
    j++;
}

void ReviewWidget::update(std::string name, const sf::Vector2f mouse_pos) {
    user_name = name;

    int j = 0;
    for (size_t i = (5*(window_state - 1)); i < (5*(window_state - 1)) + 5; i++) {
        if (i < review_list.size()) {
            review_list.at(i).updateLike(mouse_pos);
        }
        j++;
    }
    next.update(mouse_pos);
    prev.update(mouse_pos);
    sort_likes.update(mouse_pos);
    sort_date.update(mouse_pos);
    add_review.update(mouse_pos);
    add_review_button.update(mouse_pos);
}

void ReviewWidget::type(sf::Event input) {
    add_review.type(input);
}

void ReviewWidget::draw(sf::RenderTarget* target) {
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
    
    //sort buttons
    target->draw(sort_likes.getShape());
    temp = sort_likes.getText();
    temp.setFont(font_);
    target->draw(temp);

    target->draw(sort_date.getShape());
    temp = sort_date.getText();
    temp.setFont(font_);
    target->draw(temp);

    //add review
    target->draw(add_review.getShape());
    temp = add_review.getTextBox();
    temp.setFont(font_);
    target->draw(temp);

    // if (!add_review.getSelected() && add_review.getString().size() <= 1) {
    //     temp = add_review.getDefaultText();
    //     temp.setFont(font_);
    //     target->draw(temp);
    // }

    target->draw(add_review_button.getShape());
    temp = add_review_button.getText();
    temp.setFont(font_);
    target->draw(temp);

    //reviews
    int z = 0;
    z++;
    int j = 0;
    for (size_t i = (5*(window_state - 1)); i < (5*(window_state - 1)) + 5; i++) {
        if (i < review_list.size()) {
            //general box for review
            sf::RectangleShape shape;
            shape.setSize(sf::Vector2f(625,85));
            shape.setPosition(sf::Vector2f(610, 105 + (90*j)));
            shape.setFillColor(sf::Color(240, 210, 255, 255));
            target->draw(shape);
            //review text
            sf::Text rev;
            rev.setString(review_list.at(i).getReview());
            rev.setFont(font_);
            rev.setFillColor(sf::Color::Black);
            rev.setCharacterSize(12);
            rev.setPosition(sf::Vector2f(630, 135 + (90*j)));
            target->draw(rev);
            //review username
            sf::Text user_name;
            user_name.setString(review_list.at(i).getUserName());
            user_name.setFont(font_);
            user_name.setStyle(sf::Text::Bold);
            user_name.setFillColor(sf::Color::Black);
            user_name.setCharacterSize(14);
            user_name.setFont(font_);
            user_name.setPosition(sf::Vector2f(630, 115 + (90*j)));
            target->draw(user_name);
            //review date
            sf::Text date;
            date.setString(review_list.at(i).getDate());
            date.setFont(font_);
            date.setFillColor(sf::Color::Black);
            date.setCharacterSize(12);
            date.setFont(font_);
            date.setPosition(sf::Vector2f(1090, 115 + (90*j)));
            target->draw(date);
            //review like button
            review_list.at(i).positionLike(1170, 145 + (90*j), font_);
            review_list.at(i).getLikeButton().setFont(font_);
            target->draw(review_list.at(i).getLikeButton().getShape());
            sf::Text temp = review_list.at(i).getLikeButton().getText();
            temp.setFont(font_);
            target->draw(temp);
            //reviews likes
            temp.setString(std::to_string(review_list.at(i).getLikes()));
            temp.setFont(font_);
            temp.setFillColor(sf::Color::Black);
            temp.setCharacterSize(12);
            temp.setFont(font_);
            temp.setPosition(sf::Vector2f(1205, 145 + (90*j)));
            target->draw(temp);
        }
        j++;
    }

}

void ReviewWidget::Pressed(sf::RenderTarget* target, sf::RenderWindow &window) {
    sf::CircleShape shape(400.f);
    shape.setFillColor(sf::Color::Green);

    //change state of windows
    if (prev.getState() == button_states::BTN_ACTIVE) {
        if (window_state > 1) {
            window_state--;
        }
    }

    if (next.isPressed()) {
        if (window_state < max_state) {
            window_state++;
        }
    }

    if (sort_likes.isPressed()) {
        SortLikes();
    }

    if (sort_date.isPressed()) {
        SortDate();
    }

    for (size_t i = (5*(window_state - 1)); i < (5*(window_state - 1)) + 5; i++) {
        if (i < review_list.size()) {
            if (user_name != "" && review_list.at(i).getLikeButton().isPressed()) {
                review_list.at(i).incLikes();
            }
        }
    }

    if (add_review_button.isPressed()) {
        if (user_name != "") {
            Review temp(user_name, add_review.getString(), 0);
            review_list.push_back(temp);
            if (review_list.size() % 5 > 0) {
                max_state = review_list.size()/5 + 1;
            } else {
                max_state = review_list.size()/5;
            }
        }
    }
}

void ReviewWidget::SortLikes() {
    // loops through the vector size - 1 times
    for (size_t i = 0; i < review_list.size() - 1; i++) {
        // loops though the vector size - i - 1 times because smallest will be at the back after one loop
        for (size_t j = 0; j < review_list.size() - i - 1; j++) {
            // if first is smaller than second, they swap
            if (review_list.at(j).getLikes() < review_list.at(j+1).getLikes()) {
                // temp for swaping
                Review temp = review_list.at(j);
                review_list.at(j) = review_list.at(j+1);
                review_list.at(j+1) = temp;
            }
        }
    }
}

void ReviewWidget::SortDate() {
    // loops through the vector size - 1 times
    for (size_t i = 0; i < review_list.size() - 1; i++) {
        // loops though the vector size - i - 1 times because smallest will be at the back after one loop
        for (size_t j = 0; j < review_list.size() - i - 1; j++) {
            // if first is smaller than second, they swap
            if (review_list.at(j).getDate() < review_list.at(j+1).getDate()) {
                // temp for swaping
                Review temp = review_list.at(j);
                review_list.at(j) = review_list.at(j+1);
                review_list.at(j+1) = temp;
            }
        }
    }
}
