
build:
	$(MAKE) a.out

a.out: $(TARGET)
	g++ -std=gnu++1y -O2 -I/opt/boost/gcc/include -L/opt/boost/gcc/lib -o ./a.out ./$(TARGET)

run: a.out
	./a.out

test: a.out
	cat test_file.txt | ./a.out