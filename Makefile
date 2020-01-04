

build:
	g++ -std=gnu++1y -O2 -I/opt/boost/gcc/include -L/opt/boost/gcc/lib -o ./a.out ./$(TARGET)
run:
	$(MAKE) build && ./a.out

test:
	$(MAKE) build && cat test_file.txt | ./a.out