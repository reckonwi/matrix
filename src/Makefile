G=g++
FLAGS=-Wall -Wextra -Werror
HEADER=s21_matrix_oop.h
SOURCE=s21_matrix_oop.cpp
SOURCES_ALL=*.cpp
TEST=s21_matrix_oop_test.cpp

all: clean s21_matrix_oop.a test gcov_report

s21_matrix_oop.a:
	$(G) $(FLAGS) -c $(SOURCE)
	ar rc s21_matrix_oop.a s21_matrix_oop.o
	ranlib s21_matrix_oop.a
	rm -rf *.o

test:
	$(G) --coverage $(TEST) $(SOURCE) -o test -lgtest -lgmock -pthread -fno-elide-constructors
	./test

clean:
	rm -rf *.o *.a test *.txt *.gcda *.gcno report *.info *.log

gcov_report:
	lcov -t "test" -o test.info -c -d . --no-external
	lcov --remove test.info 'c++/11/*'
	genhtml -o report test.info
	open report/index.html

check_style:
	clang-format -n -style=google *.h $(SOURCES_ALL)

correct_style:
	clang-format -i -style=google *.h $(SOURCES_ALL)

leak:
	valgrind --leak-check=full -s --track-origins=yes --log-file=leak.log ./test

valgrind_macos:
	leaks -atExit -- ./test | grep LEAK:

