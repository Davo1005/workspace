COM = g++
SRCS = add_book.cpp  borrow_a_book.cpp main.cpp print_books.cpp  return_a_book.cpp  search_system.cpp

OBJS = $(SRCS:.cpp=.o)
TARGET = a.out

all: $(TARGET)

$(TARGET): $(OBJS)
	$(COM) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(COM) -c $< -o $@

clean:
	rm -f *.o $(TARGET)

