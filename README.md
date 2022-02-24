# Rate My RSO final Project
final-project-thethreeamigos created by GitHub Classroom

Group: Max Hartmann, Matt Straczek, Junryu Fu, Grace Gad

Quad day can be overwhelming, and with so many different clubs, you don't always find the club that you want to look for. Just like registering for class, you want to know how the professor for the class teaches the class. 

That is why we are creating <ins>**RateMyRSO**</ins>, a portal to easily find, review, and comment on RSOs on campus (a replica written in C++, running as a Windows Application).

**Features**

**Home Page:**

+ Search for RSOs by name
+ Sort RSOs by Ratings, Number of Members, Categories
+ Register an account or login to a previous account
+ Ensures users are logged in to do any further actions such as commenting and liking reviews
+ Regular Users can submit applications to upload a new RSO
+ Initiate and Export Users from and to .txt file
+ Initiate and Export RSOs from and to .txt file
+ Access inidividual RSO pages

**RSO Page:**

+ RSO info
+ RSO ratings
+ RSO category
+ RSO number of members
+ User-submitted reviews (can be liked, have a date posted)
+ Can sort reviews by likes or date
+ Post or like comment if you are logged in

**RUNNING THE GUI**

+ This will require installation of the SFML library to run the interface
+ This will only work if you enable X11 forwarding **if** run on virtual machine
+ **Else** It can also be ran locally without the virtual machine (X11 forwarding should be enabled)
+ All txt files need to be included, as well as other relevant resource files in order to run the GUI properly
+ To run the program, use ./bin/exec2 in terminal
+ To run test cases, use ./bin/tests


**Third Party Libraries**
+ [SFML GUI](https://www.sfml-dev.org/download.php)
