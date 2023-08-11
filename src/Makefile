CC			=	g++ -Wall -Wextra -Werror -std=c++17 -pedantic # -fsanitize=address

TEST_SRC	=	./project/controller/*.cc ./project/model/*.cc ./tests/tests.cc

TEST_FLAGS	=	-lgtest -lgtest_main -lpthread

all: 		    install open

install:		uninstall    
			    cd build && cmake ../
			    make -C ./build/

uninstall:	    clean
			    rm -Rf build/*

open:
				build/Maze.app/Contents/MacOS/Maze

dvi:
		        doxygen ./Doxygen
		        open html/index.html

dist:           
				mkdir distributive
				cp Makefile ./distributive/Makefile
				cp -R ./project ./distributive/project
				cp -R ./build ./distributive/build
				cp ./CMakeLists.txt ./distributive/CMakeLists.txt
	            tar -cf ./Maze.tar ./distributive
				rm -rf ./distributive

tests:			
				$(CC) $(TEST_SRC) $(TEST_FLAGS) -o ./tests/test_result
				./tests/test_result

leaks:			tests
				leaks -atExit -- ./tests/test_result

gcov_report:
				$(CC) -lgcov -coverage $(TEST_SRC) $(TEST_FLAGS) -o ./tests/test_covering
				./tests/test_covering
				lcov -t "test_covering" --no-external  -o test.info -c -d .
				genhtml -o test_output_list test.info
				@cd ./test_output_list ; open index.html
				rm -rf *.gcno *.gcda

clang:			clean
				cp ../materials/linters/.clang-format ./.clang-format
				clang-format -n --verbose project/*/*.h project/*/*.cc
				clang-format -i --verbose project/*/*.h project/*/*.cc
				make clean

clean:			
				rm -rf ./a.out* ./.clang-format ./Maze.tar
				rm -rf CMakeLists.txt.user html/ latex/ ./project/files/*
				rm -rf *.gcno *.gcda ./tests/test_* ./test_output_list ./test.info

.PHONY: tests
