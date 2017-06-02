SRC= Md_file.cpp convertToHTML.cpp main.cpp
OBJ= $(SRC:.c=.o)

all: markdown-cpp

markdown-cpp: $(OBJ)
	g++ -std=gnu++11 -o $@ $^

%.o: %.cpp
	g++ -std=gnu++11 -o $@ -c $^ -W -Wall -ansi -pedantic
	
remove: clean realclean

clean:
	rm -f *.o

rmprg:
	rm -f markdown-cpp	

realclean: clean rmprg
