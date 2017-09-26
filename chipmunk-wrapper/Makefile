UNAME=$(shell uname)
CXXFLAGS=-std=c++1z -Wall -pedantic -g -I include -I ../Chipmunk2D/include/chipmunk/
LDLIBS=../Chipmunk2D/build/src/libchipmunk.a -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lm
ifeq ($(UNAME),Darwin))
	LDLIBS+=-framework GLUT -framework OpenGL -framework Cocoa
endif
TARGET=app
OBJS=$(patsubst %.cc, %.o, $(wildcard *.cc))

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(TARGET) $(OBJS) $(LDLIBS)

clean:
	rm $(TARGET) $(OBJS)
