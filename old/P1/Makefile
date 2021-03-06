# Makefile de P0
DIR=../dsl-comprobaciones/
CXX = clang++
CXXFLAGS = -g -Wall -std=c++14 -pedantic
CPPFLAGS = -DP1 -I ../Tests-auto -I. -I${DIR} $(shell llvm-config --cppflags)
LLVMLDFLAGS := $(shell llvm-config --libs) $(LDFLAGS)
COMMONSRCS  := $(DIR)caclibrary.cpp $(DIR)execute.cpp $(DIR)matchers.cpp
SOURCES     := fecha_check.cpp cadena_check.cpp ${COMMONSRCS}
COMMONHDRS  := $(COMMONSRCS:.cpp=.h) $(DIR)info.h
COMMONOBJS  := $(COMMONSRCS:.cpp=.o)
OBJETOS = test-caso0-fecha-auto.o test-caso0-cadena-auto.o \
	test-auto.o cadena.o fecha.o
OBJECTS     := $(SOURCES:.cpp=.o)
EXES        := fecha_check cadena_check
CLANGLIBS   := -lclangFrontend -lclangSerialization -lclangDriver \
			-lclangTooling -lclangParse -lclangSema -lclangAnalysis \
			-lclangEdit -lclangAST -lclangASTMatchers -lclangLex \
			-lclangBasic -lclangRewrite

.PHONY: clean all
VPATH = ../Tests-auto:.

all: test-P0-auto #$(EXES)

fecha_check: fecha_check.o $(COMMONOBJS)
		@echo "(LINK) fecha_check.o"
		@$(CXX) -o $@ $^ $(CLANGLIBS) $(LLVMLDFLAGS)

fecha_check.o: $(COMMONHDRS) fecha.hpp fecha.cpp

cadena_check: cadena_check.o $(COMMONOBJS)
		@echo "(LINK) cadena_check.o"
		@$(CXX) -o $@ $^ $(CLANGLIBS) $(LLVMLDFLAGS)

cadena_check.o: $(COMMONHDRS) cadena.hpp cadena.cpp

check_Fecha: fecha_check
		@echo Verificando fecha.cpp ...
		@./fecha_check -extra-arg="-std=c++11" fecha.cpp --

check_Cadena: cadena_check
		@echo Verificando cadena.cpp ...
		@./cadena_check -extra-arg="-std=c++11" cadena.cpp --

checks: check_Fecha check_Cadena

test-P0-auto: $(OBJETOS)
	$(CXX) -o $@ $(LDFLAGS) $(OBJETOS)

test-caso0-fecha-auto.o test-caso0-cadena-auto.o test-auto.o: \
	test-caso0-fecha-auto.cpp test-caso0-cadena-auto.cpp \
	test-auto.cpp test-auto.hpp fecha.hpp cadena.hpp
fecha.o: fecha.hpp fecha.cpp
cadena.o: cadena.hpp cadena.cpp

clean:
	@echo "Limpiando."
	@${RM} $(EXES) $(OBJECTS)
	$(RM) test-P0-auto $(OBJETOS) core *~
