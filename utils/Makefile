objects = simple_string.o

$(objects) : %.o : %.cpp %.h 
	g++ -std=c++11 -c $< -o $@

.PHONY : clean
clean :
	-rm $(objects)
