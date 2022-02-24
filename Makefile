INCLUDES=-I includes/
CXXFLAGS=-std=c++20 -g -O0 -pedantic $(INCLUDES)
CXX=clang++

exec: bin/exec
tests: bin/tests
exec2: bin/exec2

clean:
	rm -f bin/*

bin/exec: src/driver.cc src/review.cc src/user.cc src/rso.cc src/home.cc -lsfml-graphics -lsfml-window -lsfml-system
	$(CXX) $(CXXFLAGS) $(INCLUDES) src/driver.cc src/review.cc src/user.cc src/rso.cc src/home.cc -lsfml-graphics -lsfml-window -lsfml-system -o bin/exec

bin/tests: obj/catch.o tests/tests.cc src/review.cc src/user.cc src/rso.cc src/home.cc
	$(CXX) $(CXXFLAGS) $^ -o $@

obj/catch.o: tests/catch.cc
	$(CXX) $(CXXFLAGS) -c $^ -o $@

bin/exec2: src/main.cc src/review.cc src/user.cc src/rso.cc src/home.cc src/button.cc src/textbutton.cc src/rsowidget.cc src/rsobutton.cc src/rsopage.cc src/reviewwidget.cc -lsfml-graphics -lsfml-window -lsfml-system
	$(CXX) $(CXXFLAGS) $(INCLUDES) src/main.cc src/review.cc src/user.cc src/rso.cc src/home.cc src/button.cc src/textbutton.cc src/rsowidget.cc src/rsobutton.cc src/rsopage.cc src/reviewwidget.cc -lsfml-graphics -lsfml-window -lsfml-system -o bin/exec2

.DEFAULT_GOAL := exec
.PHONY: clean exec tests exec2