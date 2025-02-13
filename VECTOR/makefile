COM = g++
SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)
TARGET = a.out

all: $(TARGET)

$(TARGET): $(OBJS)
	$(COM) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(COM) -c $< -o $@

clean:
	rm -f *.o $(TARGET)
