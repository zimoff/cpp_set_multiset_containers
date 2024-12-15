CC = g++ -m64 -Wall -Wextra -Werror -std=c++17
LIBS = -I/usr/local/include/ -L/usr/local/lib -lgtest -lpthread
TESTS = tests.cpp

all: gcov_report

build:
	g++ -g main.cpp -o build_set

test:
	g++ -g tests.cpp -o test_set -lgtest 
	./test_set

hard_test:
	g++ -m64 -Wall -Wextra -Werror -std=c++17 tests.cpp -o test_set -lgtest
	./test_set

gcov_report: clean_test
	$(CC) --coverage $(TESTS) -lstdc++ -o test.out $(LIBS)
	./test.out
	lcov -t "./test.out" --ignore-errors mismatch source -o report.info --no-external -c -d .
	genhtml --ignore-errors source -o report report.info
	open ./report/index.html

clean: clean_test
	rm -rf ./report

clean_test:
	rm -f *.o *.a *.gcno *.gcda *.info *.out *.gcov *.gch

