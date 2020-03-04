run: output
	./output

output: *.h *.cpp
	g++ --std=c++1y *.cpp -o output

clear: 
	rm output
