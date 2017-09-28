UNAME=$(shell uname)
CXXFLAGS=-std=c++1z -Wall -pedantic -g
CXXFLAGS+=-I include
CXXFLAGS+=-I ../Chipmunk2D/include/chipmunk/
CXXFLAGS+=-I ../chipmunk-wrapper/include/
LDLIBS+=../Chipmunk2D/build/src/libchipmunk.a
LDLIBS+=-lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
ifeq ($(UNAME),Darwin))
	LDLIBS+=-framework GLUT -framework OpenGL -framework Cocoa
endif
TARGET=escape
OBJS=$(patsubst %.cc, %.o, $(wildcard src/*.cc))

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(TARGET) $(OBJS) $(LDLIBS)

animation.o: entitity_game.h

entitity_game: asset_manager.h helper.h

game.o: helper.h player.h

player.o: entitity_game.h

clean:
	rm $(TARGET) $(OBJS)
