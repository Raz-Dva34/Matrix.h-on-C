C = gcc
FLAGCOMP = -Wall -Werror -Wextra -std=c11
FLAG_O = -o
FLAG_C = -c
FLAG_T = -t
FLAG_D = -d
WAY_FUN = ./s21_functions/
WAY_TEST = ./s21_tests/
OS := $(shell uname)

ifeq ($(OS),Linux)
FLAGS = -lcheck -lm -lpthread -lrt -lsubunit -fprofile-arcs -ftest-coverage
OPENF = xdg-open
else
FLAGS = -lcheck -lm -lpthread -fprofile-arcs -ftest-coverage
OPENF = open
endif

all: clean s21_matrix.a
	@mkdir spare_files
	@mv *.o spare_files
	@mv *.a spare_files
	@-rm -rf ./spare_files/*.o
	@make gcov_report

test: s21_matrix.a
	$(CC) $(FLAGCOMP) s21_tests.c $(WAY_TEST)s21_*.c  s21_matrix.a $(FLAGS) $(FLAG_O) unit_test
	./unit_test

s21_matrix.a: clean
	$(CC) $(FLAGCOMP) $(FLAG_C) $(WAY_FUN)s21_*.c
	ar -crs s21_matrix.a s21_*.o
	ranlib s21_matrix.a

gcov_report: s21_matrix.a
	@gcc $(FLAGCOMP) --coverage s21_tests.c $(WAY_TEST)s21_*.c $(WAY_FUN)s21_*.c  s21_matrix.a -lcheck -lm -lpthread -o gcov_test
	@chmod +x *
	@./gcov_test
	@lcov -t "gcov_test" -o gcov_test.info --no-external -c -d .
	@genhtml -o report/ gcov_test.info
	@$(OPENF) ./report/index.html

clean:
	-rm -rf *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg *.txt *.gch unit_test gcov_test
	-rm -rf tests
	-rm -rf report
	-rm -rf spare_files
	-rm -rf .clang-format
	find . -type d -name 'tests.dSYM' -exec rm -r {} +

install_brew:
	cd ~
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	brew install lcov

check:
	clang-format -style=Google -n *.c *.h ./s21_functions/*.c ./s21_tests/*.c

vg:
	@CK_FORK=no valgrind --verbose --leak-check=full --show-leak-kinds=all ./unit_test


rebuild: clean all
