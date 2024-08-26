OS := $(shell uname -s)
CC = gcc
FLAG_C = -c -Wall -Werror -Wextra -std=c11 -pedantic
FUNCS_DIR = functions
TESTS_DIR = tests
ALL_FILES = $(wildcard $(FUNCS_DIR)/*.c)
ALL_TEST_FILES = $(wildcard $(TESTS_DIR)/*.c)
ALL_FILE_O = $(ALL_FILES:.c=.o)

ifeq ($(OS), Darwin)
	FLAGS_PLATFORM = -lcheck
	GCOV_REPORT_OPEN = open ./gcov_report/index.html
else
	FLAGS_PLATFORM = -lcheck -lrt -lm -lpthread -lsubunit
	GCOV_REPORT_OPEN = xdg-open ./gcov_report/index.html
endif

all: gcov_report

s21_matrix.a: $(ALL_FILE_O)
	@ar rcs s21_matrix.a $(ALL_FILE_O)

%.o: %.c
	@$(CC) $(FLAG_C) $< -o $@

test: s21_matrix.a
	@echo "┏=========================================┓"
	@echo "┃    Reviewing and testing your code ...  ┃"
	@echo "┗=========================================┛"
	@gcc $(ALL_TEST_FILES) s21_matrix.a $(FLAGS_PLATFORM) -g -o tests.o
	@./tests.o

gcov_report: $(ALL_FILES) $(ALL_TEST_FILES)
	@echo "┏=========================================┓"
	@echo "┃     Generating your html report ...     ┃"
	@echo "┗=========================================┛"
	@$(CC) --coverage $(ALL_FILES) $(ALL_TEST_FILES) $(FLAGS_PLATFORM) -o gcov_report.o
	@./gcov_report.o
	@lcov -t s21_matrix_tests -o s21_matrix_tests.info -c -d .
	@genhtml -o gcov_report s21_matrix_tests.info
	@$(GCOV_REPORT_OPEN)

valgrind: s21_matrix.a
	@gcc $(ALL_TEST_FILES) s21_matrix.a $(FLAGS_PLATFORM) -g -o valgrind_tests.o
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./valgrind_tests.o

clean:
	@rm -f *.a
	@rm -f *.o
	@rm -f *.txt
	@rm -f *.gcda
	@rm -f *.gcno
	@rm -f *.info
	@rm -rf *.dSYM
	@rm -rf ./gcov_report
	@rm -f $(FUNCS_DIR)/*.o
	@rm -f $(TESTS_DIR)/*.o

clang:
	@echo "┏=========================================┓"
	@echo "┃  Formatting your code for Google Style  ┃"
	@echo "┗=========================================┛"
	@clang-format -i $(FUNCS_DIR)/*.c $(FUNCS_DIR)/*.c $(TESTS_DIR)/*.c *.h
	@clang-format -n $(FUNCS_DIR)/*.c $(FUNCS_DIR)/*.c $(TESTS_DIR)/*.c *.h
	@clang-format -i *.h
	@clang-format -n *.h
