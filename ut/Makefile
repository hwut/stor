vpath ../utils

objects = ut.o test_simple_string.o
utils = ../utils/*.o
exe = ut

ut : $(objects) $(utils)
	g++ -o $(exe) $(objects) $(utils) -lCppUnitLite

$(objects) : %.o : %.cpp
	g++ -std=c++11 -c $< -o $@

$(utils) : $(utils)%.cpp) $(utils)%.h
	g++ -std=c++11 -c $< -o $@
	#cd ../utils && $(MAKE)

.PHONY : clean
clean :
	-rm $(exe) $(objects)
	cd ../utils && $(MAKE) clean

