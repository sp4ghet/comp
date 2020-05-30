
build:
	$(MAKE) a.out

a.out: $(TARGET)
	g++ -std=gnu++17 -O2 -I/usr/local/Cellar/boost/1.72.0/include -L/usr/local/Cellar/boost/1.72.0/lib -o ./a.out ./$(TARGET)

%: %.cpp 
	g++ $< \
	-std=gnu++1y \
	-O2 \
	-Wall \
	-I/usr/local/Cellar/boost/1.72.0/include \
	-L/usr/local/Cellar/boost/1.72.0/lib \
	-o ./a.out \
	-Wshadow \
	-Wno-unknown-pragmas  \
	-fsanitize=undefined \
	-D_GLIBCXX_DEBUG \
	# -fsanitize=address

run: a.out
	./a.out

test: a.out
	cat test_file.txt | ./a.out
