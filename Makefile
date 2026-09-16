build: bin/main

bin/main: main.cpp
	@mkdir -p bin
	g++ -Wall -O2 $< -o $@

clean:
	rm -rf bin