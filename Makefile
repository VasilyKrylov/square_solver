FLAGS = -O2

all: arg_parser.o logger.o test_library.o buffer_clean.o main.o test_solve_quadr.o compare_double.o \
show_results.o get_data.o solve_quadr.o
	g++ $(FLAGS) arg_parser.o logger.o test_library.o buffer_clean.o main.o \
	test_solve_quadr.o compare_double.o show_results.o get_data.o solve_quadr.o -o square

arg_parser.o: ./souce/arg_parser.cpp
	g++ $(FLAGS) -c -I./include/ ./souce/arg_parser.cpp -o arg_parser.o

logger.o: ./souce/logger.cpp
	g++ $(FLAGS) -c -I./include/ ./souce/logger.cpp -o logger.o

test_library.o: ./souce/logger.cpp
	g++ $(FLAGS) -c -I./include/ ./souce/test_library.cpp -o test_library.o

buffer_clean.o: ./souce/buffer_clean.cpp
	g++ $(FLAGS) -c -I./include/ ./souce/buffer_clean.cpp -o buffer_clean.o

main.o: ./souce/main.cpp
	g++ $(FLAGS) -c -I./include/ ./souce/main.cpp -o main.o

test_solve_quadr.o: ./souce/test_solve_quadr.cpp
	g++ $(FLAGS) -c -I./include/ ./souce/test_solve_quadr.cpp -o test_solve_quadr.o

compare_double.o: ./souce/compare_double.cpp
	g++ $(FLAGS) -c -I./include/ ./souce/compare_double.cpp -o compare_double.o

show_results.o: ./souce/show_results.cpp
	g++ $(FLAGS) -c -I./include/ ./souce/show_results.cpp -o show_results.o

get_data.o: ./souce/get_data.cpp
	g++ $(FLAGS) -c -I./include/ ./souce/get_data.cpp -o get_data.o

solve_quadr.o: ./souce/solve_quadr.cpp
	g++ $(FLAGS) -c -I./include/ ./souce/solve_quadr.cpp -o solve_quadr.o