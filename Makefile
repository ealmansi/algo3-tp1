SRC_DIR						= src
OBJ_DIR 					= obj
BIN_DIR						= bin
TEX_DIR						= tex
TESTS_DIR					= tests
MEDICIONES_DIR		= mediciones
GRAFICOS_DIR			= graficos

MAKE	 = Makefile

BIN_P1 = $(BIN_DIR)/problema1
BIN_P2 = $(BIN_DIR)/problema2
BIN_P3 = $(BIN_DIR)/problema3
BIN_MP = $(BIN_DIR)/medir_performance

OBJ_P1 		= $(OBJ_DIR)/problema1.o
OBJ_P1_I 	= $(OBJ_DIR)/problema1_impl.o
OBJ_P2 		= $(OBJ_DIR)/problema2.o
OBJ_P2_I 	= $(OBJ_DIR)/problema2_impl.o
OBJ_P3 		= $(OBJ_DIR)/problema3.o
OBJ_P3_I 	= $(OBJ_DIR)/problema3_impl.o
OBJ_MP 		= $(OBJ_DIR)/medir_performance.o

SRC_P1 		= $(SRC_DIR)/problema1/problema1.cpp
SRC_P1_I 	= $(SRC_DIR)/problema1/problema1_impl.cpp
SRC_P2 		= $(SRC_DIR)/problema2/problema2.cpp
SRC_P2_I 	= $(SRC_DIR)/problema2/problema2_impl.cpp
SRC_P3 		= $(SRC_DIR)/problema3/problema3.cpp
SRC_P3_I 	= $(SRC_DIR)/problema3/problema3_impl.cpp
SRC_MP 		= $(SRC_DIR)/medir_performance.cpp

HDR_P1 		= $(SRC_DIR)/problema1/problema1.h
HDR_P2 		= $(SRC_DIR)/problema2/problema2.h
HDR_P3 		= $(SRC_DIR)/problema3/problema3.h

CXX     	= g++
CXXFLAGS	= -g -Wall -Wno-unused-parameter -Wextra
LDFLAGS 	= -lrt

all: crear_carpetas $(BIN_P1) $(BIN_P2) $(BIN_P3) $(BIN_MP)

$(BIN_P1): $(OBJ_P1) $(OBJ_P1_I)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(BIN_P2): $(OBJ_P2) $(OBJ_P2_I)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(BIN_P3): $(OBJ_P3) $(OBJ_P3_I)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(BIN_MP): $(OBJ_MP) $(OBJ_P1_I) $(OBJ_P2_I) $(OBJ_P3_I)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(OBJ_P1): $(SRC_P1) $(HDR_P1) $(MAKE)
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(OBJ_P1_I): $(SRC_P1_I) $(HDR_P1) $(MAKE)
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(OBJ_P2): $(SRC_P2) $(HDR_P2) $(MAKE)
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(OBJ_P2_I): $(SRC_P2_I) $(HDR_P2) $(MAKE)
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(OBJ_P3): $(SRC_P3) $(HDR_P3) $(MAKE)
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(OBJ_P3_I): $(SRC_P3_I) $(HDR_P3) $(MAKE)
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(OBJ_MP): $(SRC_MP) $(HDR_P1) $(HDR_P2) $(HDR_P3) $(MAKE)
	$(CXX) -c $(CXXFLAGS) -o $@ $<

informe: $(TEX_DIR)/informe.tex
	cd $(TEX_DIR); \
	pdflatex informe.tex; \
	mv informe.pdf ..; \
	cd ..

.PHONY: crear_carpetas clean clean_ejecutables clean_mediciones clean_graficos clean_tex clean_todo

crear_carpetas:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(TESTS_DIR)
	@mkdir -p $(TESTS_DIR)/problema1
	@mkdir -p $(TESTS_DIR)/problema2
	@mkdir -p $(TESTS_DIR)/problema3
	@mkdir -p $(MEDICIONES_DIR)
	@mkdir -p $(MEDICIONES_DIR)/problema1
	@mkdir -p $(MEDICIONES_DIR)/problema2
	@mkdir -p $(MEDICIONES_DIR)/problema3
	@mkdir -p $(GRAFICOS_DIR)
	@mkdir -p $(GRAFICOS_DIR)/problema1
	@mkdir -p $(GRAFICOS_DIR)/problema2
	@mkdir -p $(GRAFICOS_DIR)/problema3

clean:
	rm -f $(OBJ_DIR)/*.o

clean_ejecutables:
	rm -f $(BIN_DIR)/*

clean_mediciones:
	rm -f $(MEDICIONES_DIR)/problema1/*
	rm -f $(MEDICIONES_DIR)/problema2/*
	rm -f $(MEDICIONES_DIR)/problema3/*

clean_graficos:
	rm -f $(GRAFICOS_DIR)/problema1/*
	rm -f $(GRAFICOS_DIR)/problema2/*
	rm -f $(GRAFICOS_DIR)/problema3/*

clean_tex:
	rm -f $(TEX_DIR)/*.aux
	rm -f $(TEX_DIR)/*.toc
	rm -f $(TEX_DIR)/*.log
	
clean_todo: clean clean_ejecutables clean_mediciones clean_graficos clean_tex
