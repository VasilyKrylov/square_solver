CXX = g++
CXXFLAGS ?= _DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations -Wc++14-compat -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector -fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer -Wlarger-than=8192 -Wstack-usage=8192 -pie -fPIE -Werror=vla -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr
COMMONOTIC = -I./include

override CXXFLAGS += $(COMMONOTIC)

.PHONY: all
all: square

square: arg_parser.o logger.o test_library.o buffer_clean.o main.o test_solve_quadr.o compare_double.o \
show_results.o get_data.o solve_quadr.o
    $(CXX) $^ -o $@ $(LDFLAGS)

arg_parser.o: ./src/arg_parser.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

logger.o: ./src/logger.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

test_library.o: ./src/logger.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

buffer_clean.o: ./src/buffer_clean.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

main.o: ./src/main.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

test_solve_quadr.o: ./src/test_solve_quadr.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

compare_double.o: ./src/compare_double.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

show_results.o: ./src/show_results.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

get_data.o: ./src/get_data.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

solve_quadr.o: ./src/solve_quadr.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

.PHONY: clean
clean:
    rm -rf *.o