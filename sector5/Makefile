UNAME=$(shell uname)
CXXFLAGS=-std=c++1z -Wall -pedantic -g -I include
LDLIBS=-lsfml-graphics -lsfml-window -lsfml-system
ifeq ($(UNAME),Darwin))
	LDLIBS+=-framework GLUT -framework OpenGL -framework Cocoa
endif
TARGET=sector5
OBJS=$(patsubst %.cc, %.o, $(wildcard src/*.cc))

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(TARGET) $(OBJS) $(LDLIBS)

enemy.o: entitity_game.c entitity_game.h

game.o: player.c player.h enemy.c enemy.h

player.o: entitity_game.c entitity_game.h

clean:
	rm $(TARGET) $(OBJS)
