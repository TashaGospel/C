LINK_TARGET = thing-demo

OBJS = thing-demo.o thing.o

all: $(LINK_TARGET)

$(LINK_TARGET): $(OBJS)
	g++ $^ -o $@

%.o: %.cpp
	g++ -c $<

clean: 
	rm *.o
