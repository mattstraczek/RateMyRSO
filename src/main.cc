#include <SFML/Graphics.hpp>
#include "button.hpp"
#include "textbutton.hpp"
#include "review.hpp"
#include "rso.hpp"
#include "user.hpp"
#include <iostream>
#include <string>
#include "rsowidget.hpp"
#include "home.hpp"
#include "reviewwidget.hpp"

int main()
{
    //window and target for functions
    sf::RenderWindow window(sf::VideoMode(1280, 700), "RateMyRSO");
    sf::RenderTarget* target = &window;

    //taskbar
    sf::RectangleShape taskbar_background;
    taskbar_background.setPosition(sf::Vector2f(0,0));
    taskbar_background.setSize(sf::Vector2f(window.getSize().x, 70));
    taskbar_background.setFillColor(sf::Color(95,100,255,255));

    //general font
    sf::Font font;
    if (!font.loadFromFile("OpenSans-Regular.ttf")) {
        throw "Could not open file";
    }

    //buttons
    Button rso_home(30, (window.getSize().x / 2) - 115.f, 10.f, 200, 50, font, "RateMyRSO", sf::Color(95,100,255,200), sf::Color(95,100,255,200), sf::Color(95,100,255,200));
    rso_home.changeTextColor(sf::Color(240,210,255,255));
    rso_home.changeTextBold();
    rso_home.changeColor(sf::Color(95,100,255,255));
    
    TextButton username(12, 20, 20, 100, 30, font, "Username", sf::Color(70,70,70,200));
    username.changeLimit(true, 8);
    TextButton password(12, 130, 20, 100, 30, font, "Password", sf::Color(70,70,70,200));
    password.changeLimit(true, 8);
    Button login(10, 260, 20, 40, 30, font, "Login", sf::Color(240,210,255,255), sf::Color(150,150,150,255), sf::Color(20,20,20,200));
    Button reg(10, 310, 20, 40, 30, font, "Register", sf::Color(62,255,26,200), sf::Color(150,150,150,255), sf::Color(20,20,20,200));
    TextButton search_bar(14, (window.getSize().x / 2) - 105.f, 90, 200, 30, font, "Search", sf::Color(70,70,70,200));
    search_bar.changeLimit(true, 30);
    Button search(14, (window.getSize().x / 2) + 105.f, 90, 30, 30, font, "->", sf::Color(62,255,26,200), sf::Color(150,150,150,255), sf::Color(20,20,20,200));
    Button rso_app(12, window.getSize().x - 170, 20, 140, 30, font, "RSO Application", sf::Color(70,70,70,200), sf::Color(150,150,150,255), sf::Color(20,20,20,200));
    
    //sorting buttons
    Button sort(16, window.getSize().x - 70, 90, 50, 50, font, "Sort", sf::Color(70,70,70,200), sf::Color(150,150,150,255), sf::Color(20,20,20,200));
    Button sort_category(12, window.getSize().x - 220, 90, 100, 30, font, "Sort by category", sf::Color(70,70,70,200), sf::Color(150,150,150,255), sf::Color(20,20,20,200));
    Button sort_rating(12, window.getSize().x - 220, 125, 100, 30, font, "Sort by rating", sf::Color(70,70,70,200), sf::Color(150,150,150,255), sf::Color(20,20,20,200));
    Button sort_members(12, window.getSize().x - 220, 160, 100, 30, font, "Sort by members", sf::Color(70,70,70,200), sf::Color(150,150,150,255), sf::Color(20,20,20,200));

    //category buttons
    Button sort_aca(10, window.getSize().x - 90, 90, 15, 15, font, "Aca", sf::Color(70,70,70,200), sf::Color(150,150,150,255), sf::Color(20,20,20,200));
    Button sort_aca_bus(10, window.getSize().x - 90, 110, 15, 15, font, "Bus", sf::Color(70,70,70,200), sf::Color(150,150,150,255), sf::Color(20,20,20,200));
    Button sort_aca_eng(10, window.getSize().x - 90, 130, 15, 15, font, "Eng", sf::Color(70,70,70,200), sf::Color(150,150,150,255), sf::Color(20,20,20,200));
    Button sort_ath(10, window.getSize().x - 90, 150, 15, 15, font, "Ath", sf::Color(70,70,70,200), sf::Color(150,150,150,255), sf::Color(20,20,20,200));
    Button sort_cul(10, window.getSize().x - 110, 90, 15, 15, font, "Cul", sf::Color(70,70,70,200), sf::Color(150,150,150,255), sf::Color(20,20,20,200));
    Button sort_soc(10, window.getSize().x - 110, 110, 15, 15, font, "Soc", sf::Color(70,70,70,200), sf::Color(150,150,150,255), sf::Color(20,20,20,200));
    Button sort_gov(10, window.getSize().x - 110, 130, 15, 15, font, "Gov", sf::Color(70,70,70,200), sf::Color(150,150,150,255), sf::Color(20,20,20,200));

    //rso application display box
    sf::RectangleShape rso_app_display;
    rso_app_display.setFillColor(sf::Color(70,70,70,200));
    rso_app_display.setSize(sf::Vector2f(200,200));
    rso_app_display.setPosition(sf::Vector2f(window.getSize().x - 350, 50));

    TextButton club_name(12, window.getSize().x - 335, 80, 170, 30, font, "Club Name", sf::Color(70,70,70,200));
    club_name.changeLimit(true, 18);
    TextButton contact_info(12, window.getSize().x - 335, 120, 170, 30, font, "Contact Information", sf::Color(70,70,70,200));
    contact_info.changeLimit(true, 18);
    Button send_app(12, window.getSize().x - 335, 180, 170, 40, font, "Send Application", sf::Color(62,255,26,200), sf::Color(150,150,150,255), sf::Color(20,20,20,200));

    //testing home screen
    Home home_screen;
    home_screen.InitRSOs("rso_file_updated.txt");
    std::vector<Rso> temp_2 = home_screen.getRSOList();

    home_screen.InitUsers("user_name_file.txt");

    RSOWidget rsos(temp_2, font);

    //general toggle helpers
    std::string status;
    bool sort_toggle = false;
    bool category_toggle = false;
    bool rso_toggle = false;

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                home_screen.UpdateRSOs();
                home_screen.UpdateUsers();
                window.close();
            }
            if (event.type == sf::Event::TextEntered) {
                username.type(event);
                password.type(event);
                search_bar.type(event);
                club_name.type(event);
                contact_info.type(event);
            }
        }
        
        //background and taskbar
        window.clear(sf::Color(240, 210, 255, 255));
        window.draw(taskbar_background);
        
        //updating mouse position
        sf::Vector2f mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        
        //drawing all buttons
        rso_home.draw(target);
        search_bar.draw(target);
        rso_app.draw(target);
        sort.draw(target);
        search.draw(target);
        
        if (!home_screen.returnLogStatus()) {
            username.draw(target);
            password.draw(target);
            login.draw(target);
            reg.draw(target);
        } else {
            sf::Text user;
            user.setString("Hello, " + username.getString() + "!");
            user.setFont(font);
            user.setFillColor(sf::Color(240,210,255,255));
            user.setCharacterSize(16);
            user.setPosition(sf::Vector2f(20,20));
            window.draw(user);
        }
        
        //updating mouse position 
        search_bar.update(mouse_pos);
        rso_app.update(mouse_pos);
        sort.update(mouse_pos);
        rso_home.update(mouse_pos);
        search.update(mouse_pos);
        
        if (!home_screen.returnLogStatus()) {
            username.update(mouse_pos);
            password.update(mouse_pos);
            login.update(mouse_pos);
            reg.update(mouse_pos);
        }

        //rso widget
        rsos.draw(target);
        rsos.update(home_screen.getName(), mouse_pos);
        rsos.Pressed(target, window);

        //presses
        if (rso_app.isPressed()) {
            if (rso_toggle) rso_toggle = false;
            else if (!rso_toggle) rso_toggle = true;
        }

        if (rso_toggle) {
            window.draw(rso_app_display);
            club_name.draw(target);
            contact_info.draw(target);
            send_app.draw(target);

            club_name.update(mouse_pos);
            contact_info.update(mouse_pos);
            send_app.update(mouse_pos);
        }

        //login/register control
        if (login.isPressed()) {
            home_screen.LogIn(username.getString(), password.getString());
        }
        
        if (reg.isPressed()) {
            status = home_screen.Register(username.getString(), password.getString());
        }
        
        if (status != "" && !home_screen.returnLogStatus()) {
            sf::Text user;
            user.setString(status);
            user.setFont(font);
            user.setFillColor(sf::Color::Red);
            user.setCharacterSize(10);
            user.setPosition(sf::Vector2f(380,30));
            window.draw(user);
        }

        //search
        if (search.isPressed()) {
            rsos.changeRSOList(home_screen.Search(search_bar.getString()));
        }

        //sorting control
        if (sort.isPressed()) {
            if (!sort_toggle) sort_toggle = true;
            else if (sort_toggle) sort_toggle = false;
        }

        //display sort options
        if (sort_toggle) {
            sort_category.draw(target);
            sort_members.draw(target);
            sort_rating.draw(target);

            sort_category.update(mouse_pos);
            sort_members.update(mouse_pos);
            sort_rating.update(mouse_pos);

            if (sort_category.isPressed()) {
                if (!category_toggle) category_toggle = true;
                else if (category_toggle) category_toggle = false;
                
            }

            //display individual category buttons
            if (category_toggle) {
                sort_aca.draw(target);
                sort_aca_bus.draw(target);
                sort_aca_eng.draw(target);
                sort_ath.draw(target);
                sort_cul.draw(target);
                sort_gov.draw(target);
                sort_soc.draw(target);

                sort_aca.update(mouse_pos);
                sort_aca_bus.update(mouse_pos);
                sort_aca_eng.update(mouse_pos);
                sort_ath.update(mouse_pos);
                sort_cul.update(mouse_pos);
                sort_gov.update(mouse_pos);
                sort_soc.update(mouse_pos);

                if (sort_aca.isPressed()) {
                    rsos.changeRSOList(home_screen.SortRSOsCategory(rso_category::Academic));
                }
                if (sort_aca_bus.isPressed()) {
                    rsos.changeRSOList(home_screen.SortRSOsCategory(rso_category::Academic_Business));
                }
                if (sort_aca_eng.isPressed()) {
                    rsos.changeRSOList(home_screen.SortRSOsCategory(rso_category::Academic_Engineering));
                }
                if (sort_ath.isPressed()) {
                    rsos.changeRSOList(home_screen.SortRSOsCategory(rso_category::Athletics));
                }
                if (sort_cul.isPressed()) {
                    rsos.changeRSOList(home_screen.SortRSOsCategory(rso_category::Cultural));
                }
                if (sort_gov.isPressed()) {
                    rsos.changeRSOList(home_screen.SortRSOsCategory(rso_category::Governance));
                }
                if (sort_soc.isPressed()) {
                    rsos.changeRSOList(home_screen.SortRSOsCategory(rso_category::Social));
                }
            }

            if (sort_members.isPressed()) {
                home_screen.SortRSOsMembers();
                rsos.changeRSOList(home_screen.getRSOList());
            }

            if (sort_rating.isPressed()) {
                home_screen.SortRSOsRating();
                rsos.changeRSOList(home_screen.getRSOList());
            }
        }
        window.display();
    }
    return 0;
}