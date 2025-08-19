
CC = gcc
CCPP = g++
CFLAGS= -c -std=c17 -fopenmp -march=native -Wall -Wextra -O3 -fdiagnostics-color -fanalyzer -fanalyzer-verbosity=2 -ftree-loop-im -ftree-loop-ivcanon -fvariable-expansion-in-unroller
CPPCFLAGS= -c -fopenmp -march=native -Wall -Wextra -O3 -std=c++20 -fdiagnostics-color -ftree-loop-im -ftree-loop-ivcanon -fvariable-expansion-in-unroller
# LDFLAGS=  -Wall -Wextra -fopenmp -pthread -lm -lntl -lgmp -lgf2x -O3
# LDFLAGS=  -Wall -Wextra -fopenmp -pthread -lm -lntl -lgmp -lbitwuzla -O3
LDFLAGS=  -Wall -Wextra -fopenmp -pthread -lm -O3
MAIN_CPP_SOURCE := main.cpp
C_SOURCES :=
CPP_SOURCES := poly.cpp precalcul.cpp non_lin.cpp lin.cpp get_and_print_implem.cpp
SOURCES = $(MAIN_SOURCE) $(OTHER_SOURCES)
C_OBJECTS  := $(C_SOURCES:%.c=%.o)
CPP_OBJECTS := $(CPP_SOURCES:%.cpp=%.o)
ALL_OBJECTS := $(C_OBJECTS) $(CPP_OBJECTS)
MAIN_CPP_OBJECT := $(MAIN_CPP_SOURCE:%.cpp=%.o)
HOSTNAME := $(shell uname -n)
PROGRAM="implem_${HOSTNAME}"

PRECOMPUTATION_SRC := precomputation/precomputation.cpp
PRECOMPUTATION_OBJECTS := $(PRECOMPUTATION_SRC:%.cpp=%.o)
# MAX_SIZE := 7

all: prog

$(C_OBJECTS): %.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	

clean :
	@rm -f $(PROGRAM)
	@rm -rf *.o
	
launch :
	@make --no-print-directory clean
	@make --no-print-directory all
	$(PROGRAM)

help :
	@cat README.txt

prog: $(C_OBJECTS) $(CPP_OBJECTS) $(MAIN_CPP_OBJECT) $(PROGRAM)

$(MAIN_CPP_OBJECT): %.o : %.cpp
	@$(CCPP) $(CPPCFLAGS) -c $< -o $@

$(CPP_OBJECTS): %.o : %.cpp
	@$(CCPP) $(CPPCFLAGS) -c $< -o $@

$(PROGRAM): $(ALL_OBJECTS) $(MAIN_CPP_OBJECT)
	@$(CCPP) $(ALL_OBJECTS) $(MAIN_CPP_OBJECT) -o $@ $(LDFLAGS)


$(PRECOMPUTATION_OBJECTS): %.o : %.cpp
	@$(CCPP) $(CPPCFLAGS) -c $< -o $@

precomputation_program : $(PRECOMPUTATION_OBJECTS)
	@$(CCPP) $(PRECOMPUTATION_OBJECTS) -o precomputation/$@ $(LDFLAGS)

precomputation_files :
	@cd precomputation; \
	./precomputation_program $(MAX_SIZE)
