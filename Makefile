

ifeq ($(shell uname -s),Linux)
	TEST = -lcheck -lsubunit -lrt -lm -lpthread -fprofile-arcs -ftest-coverage --coverage


else ifeq ($(shell uname -s),Darwin)
	TEST = -lcheck -lpthread -fprofile-arcs -ftest-coverage


endif

####### Test

all: gcov_report install

test:
	gcc test.c  s21_shunting_yard.c ${TEST} -o test
	./test

clean:
	rm -f *.o
	rm -f *.g*
	rm -f test
	rm -f *.tar
	rm -dfr ./latex

style: clean
	cppcheck s21_shunting_yard.h s21_shunting_yard.c
	chmod 777 ../materials/linters/.clang-format
	cp ../materials/linters/.clang-format .clang-format 
	clang-format -i *.c
	clang-format -i *.h
	clang-format -n *.c
	clang-format -n *.h

gcov_report: test
	gcov *s21_shunting_yard.gcno && gcovr --html > report.html
	make clean

install:
	mkdir -p SmartCalc
	cd ./SmartCalc && qmake ../ && make
	

uninstall:
	rm -dfr ./SmartCalc

dist:
	tar -cf projects.tar ./s21_* ./SmartCalc.pro ./qcustomplot.* ./Makefile

dvi:
	open ./html/annotated.html

