output: Final.o classFile.o
	g++ Final.o classFile.o -o output

Final.o: Final.cpp
	g++ -c Final.cpp

classFile.o: classFile.cpp
	g++ -c classFile.cpp

clean:
	rm *.o output