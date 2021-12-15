assignment5: mainfile.o system.o user.o post.o
	g++ mainfile.o system.o user.o post.o -o assignment5

mainfile.o: mainfile.cpp
	g++ -c mainfile.cpp

system.o: system.cpp system.h
	g++ -c system.cpp

user.o:user.cpp user.h
	g++ -c user.cpp

post.o:post.cpp post.h
	g++ -c post.cpp

clean:
	-rm mainfile.o system.o user.o post.o assignment5