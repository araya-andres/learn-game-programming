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

animation.o: entitity_game.h

bullet.o: entitity_game.h

enemy.o: entitity_game.h

explosion: animation.h

entitity_game: asset_manager.h helper.h

game.o: bullet.h helper.h enemy.h explosion.h player.h

player.o: entitity_game.h

clean:
	rm $(TARGET) $(OBJS)
