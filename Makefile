
build:
	$(MAKE) a.out

a.out: $(TARGET)
	g++ -std=gnu++1y -O2 -I/usr/local/Cellar/boost/1.72.0/include -L/usr/local/Cellar/boost/1.72.0/lib -o ./a.out ./$(TARGET)

run: a.out
	./a.out

test: a.out
	cat test_file.txt | ./a.out
