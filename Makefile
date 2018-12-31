CXX = g++ -std=c++14 
SRC1 = main.cpp
OBJ1 = $(SRC1:%.cpp=%.o) 
TARGET1 = $(SRC1:%.cpp=%) 

all: $(TARGET1)

.c .o:
	$(CXX) -c $< 

$(TARGET1): $(OBJ1)
	$(CXX) -o $@ $^ -lm -lncursesw

clean :
	rm -f $(TARGET1) $(OBJ1) 
