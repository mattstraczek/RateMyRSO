

#include "catch.hpp"
#include "review.hpp"
#include "user.hpp"
#include "event.hpp"
#include "rso.hpp"
#include "home.hpp"
#include <iostream>
 
TEST_CASE("testing home log in" "[test login]") {
  Home gracesHome = Home();
  std::string userg = "Grace";
  std::string passg = "Axios";
  Rso newClub = Rso();
  std::string newUser = "Verena";
  std::string newPass = "imnotadriver";
  gracesHome.LogIn(userg, passg);
  REQUIRE(false == gracesHome.returnLogStatus());
};




  TEST_CASE("Home::Register", "[test register]") {
    Home gracesHome = Home();
    std::string userg = "Grace";
    std::string passg = "Axios";
    Rso newClub = Rso();
    std::string newUser = "Verena";
    std::string newPass = "imnotadriver";
    gracesHome.LogIn(userg, passg);
    std::string rg = gracesHome.Register(userg, passg);
    REQUIRE("successfully registered!" ==  rg);
    std::string exists = gracesHome.Register(userg, passg);
    REQUIRE("username already exists" == exists);
    std::string invalid = gracesHome.Register("grace gad", passg);
    REQUIRE("username has invalid character" == invalid);
  };
  TEST_CASE("Home::InitRSOs", "[testing initRSOs]") {
    Home gracesHome = Home();
    std::string userg = "Grace";
    std::string passg = "Axios";
    Rso newClub = Rso();
    std::string newUser = "Verena";
    std::string newPass = "imnotadriver";
    gracesHome.LogIn(userg, passg);
    gracesHome.InitRSOs("rso_file_updated.txt");
    REQUIRE(0 != (gracesHome.getRSOList()).size());
  };

  
  TEST_CASE("Home::SortRSOsRating", "[Testing sortRSOsRating]") {
    Home gracesHome = Home();
    std::string userg = "Grace";
    std::string passg = "Axios";
    Rso newClub = Rso();
    std::string newUser = "Verena";
    std::string newPass = "imnotadriver";
    gracesHome.InitRSOs("rso_file.txt");
    gracesHome.SortRSOsRating();
    std::vector<Rso> studentOrg = gracesHome.getRSOList();
    for (int i = 0; i < gracesHome.getRSOList().size() - 1; i++) {
      REQUIRE(gracesHome.getRSOList().at(i).GetRating() >= gracesHome.getRSOList().at(i+1).GetRating());
    }
  };
 TEST_CASE("Home::SortRSOsCategory", "[tesing SortRSOsCategory]") {
    Home gracesHome = Home();
    std::string userg = "Grace";
    std::string passg = "Axios";
    Rso newClub = Rso();
    std::string newUser = "Verena";
    std::string newPass = "imnotadriver";
    gracesHome.InitRSOs("rso_file.txt");
    gracesHome.SortRSOsRating();
    std::vector<Rso> toReturn = gracesHome.SortRSOsCategory(rso_category::Academic);
    for (size_t i = 0; i < toReturn.size(); i++) {
      REQUIRE(toReturn[i].GetCategory() == 0);
    }
  };
//   // TEST_CASE_METHOD(Home::Search) {

//   // }
  TEST_CASE("Home::SortRSOsMembers", "[testing sorting rso members]") {
    Home gracesHome = Home();
    std::string userg = "Grace";
    std::string passg = "Axios";
    Rso newClub = Rso();
    std::string newUser = "Verena";
    std::string newPass = "imnotadriver";
    gracesHome.InitRSOs("rso_file.txt");
    gracesHome.SortRSOsRating();
    gracesHome.SortRSOsMembers();
    std::vector<Rso>& orgMembers = gracesHome.getRSOList();
     for (size_t i = 0; i < orgMembers.size() - 1; i++) {
      REQUIRE(gracesHome.getRSOList().at(i).GetMembers() >= gracesHome.getRSOList().at(i+1).GetMembers());
    }
  }
  
  TEST_CASE("Home::UpdateRSOs", "[testing updating RSOs]") {
    Home gracesHome = Home();
    std::string userg = "Grace";
    std::string passg = "Axios";
    Rso newClub = Rso();
    std::string newUser = "Verena";
    std::string newPass = "imnotadriver";
    gracesHome.InitRSOs("rso_file.txt");
    gracesHome.SortRSOsRating();
    gracesHome.SortRSOsMembers();
    
    gracesHome.UpdateRSOs();
    REQUIRE(7 == (gracesHome.getRSOList()).size());
  }
  TEST_CASE("Home::InitUsers", "[testing initusers]") {
    Home gracesHome = Home();
    std::string userg = "Grace";
    std::string passg = "Axios";
    Rso newClub = Rso();
    std::string newUser = "Verena";
    std::string newPass = "imnotadriver";
    gracesHome.InitRSOs("rso_file.txt");
    gracesHome.SortRSOsRating();
    gracesHome.SortRSOsMembers();
    gracesHome.InitUsers("user_name_file_with_new_users.txt");
    REQUIRE(0 != (gracesHome.getUsers()).size());
  }
  TEST_CASE("Home::UpdateUsers", "[testing update users]") {
    Home gracesHome = Home();
    std::string userg = "Grace";
    std::string passg = "Axios";
    Rso newClub = Rso();
    std::string newUser = "Verena";
    std::string newPass = "imnotadriver";
    gracesHome.InitRSOs("rso_file.txt");
    gracesHome.InitUsers("user_name_file_with_new_users.txt");
    gracesHome.SortRSOsRating();
    gracesHome.SortRSOsMembers();
    gracesHome.UpdateUsers();
    REQUIRE(5 == (gracesHome.getUsers()).size());
  }

  TEST_CASE("Home::addToRSOList", "[testing addTORSOList]") {
    Home gracesHome = Home();
    std::string userg = "Grace";
    std::string passg = "Axios";
    Rso newClub = Rso();
    std::string newUser = "Verena";
    std::string newPass = "imnotadriver";
    gracesHome.InitRSOs("rso_file.txt");
    gracesHome.SortRSOsRating();
    gracesHome.SortRSOsMembers();
    REQUIRE(7 == (gracesHome.getRSOList()).size());
    gracesHome.addToRSOList(newClub);
    REQUIRE(8 == (gracesHome.getRSOList()).size());
  }
  TEST_CASE("Home::addUser", "[testing add user]") {
    Home gracesHome = Home();
    std::string userg = "Grace";
    std::string passg = "Axios";
    Rso newClub = Rso();
    std::string newUser = "Verena";
    std::string newPass = "imnotadriver";
    gracesHome.InitRSOs("rso_file.txt");
    gracesHome.InitUsers("user_name_file_with_new_users.txt");
    gracesHome.SortRSOsRating();
    gracesHome.SortRSOsMembers();
    REQUIRE(5 == gracesHome.getUsers().size());
    gracesHome.addUser(newUser, newPass);
    REQUIRE(6 == (gracesHome.getUsers().size()));
  }
  TEST_CASE("Rso::Rso", "[testing constructor]") {
    std::string coptClub = "COCF";
    int i = 4;
    std::string coptInfo = "Coptic Orthodox Christian Fellowship";
    int people = 25;
    double r = 4.5;
    Rso club = Rso(coptClub, i, coptInfo, people, r);

    REQUIRE(coptClub == club.GetName());
    REQUIRE(coptInfo == club.GetInfo());
    REQUIRE(people == club.GetMembers());
    REQUIRE(int(r) == club.GetRating());
    REQUIRE(i == club.GetCategory());

    REQUIRE(0 == club.GetReviews().size());
  }
  TEST_CASE("Rso::AddReview", "[testing add review]") {
    std::string coptClub = "COCF";
    int i = 4;
    std::string coptInfo = "Coptic Orthodox Christian Fellowship";
    int people = 25;
    double r = 4.5;
    Rso club = Rso(coptClub, i, coptInfo, people, r);
    Review newRevw = Review();
    club.AddReview(newRevw);
    REQUIRE(1 == club.GetReviews().size());
  }
  TEST_CASE("AddReview", "[testing add review overload]") {
    std::string coptClub = "COCF";
    int i = 4;
    std::string coptInfo = "Coptic Orthodox Christian Fellowship";
    int people = 25;
    double r = 4.5;
    Rso club = Rso(coptClub, i, coptInfo, people, r);
    std::string auth = "Grace";
    std::string rev = "Wonderful RSO, met many people in it";
    club.AddReview(auth, rev);
    std::vector<Review> reviews = club.GetReviews();
    REQUIRE(rev == reviews[0].getReview());
  }



  TEST_CASE("Review::Review", "[testing the constructor]") {
    std::string user_ = "gracegad";
    std::string review_ = "great RSO met many new people and learned a lot";
    int l = 7;
    Review gracesReview = Review(user_, review_, l);
    REQUIRE(user_ == gracesReview.getUserName());
    REQUIRE(review_ == gracesReview.getReview());
    REQUIRE(l == gracesReview.getLikes());
  }
