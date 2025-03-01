CC = g++
CFLAGS = -I/usr/include/openssl -L/usr/lib -lssl -lcrypto
SRC = main.cpp user_fun.cpp sha256.cpp
OBJ = $(SRC:.cpp=.o)
OUT = sha256

all: $(OUT)

$(OUT): $(OBJ)
	$(CC) $(OBJ) -o $(OUT) $(CFLAGS)

%.o: %.cpp
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJ) $(OUT)

