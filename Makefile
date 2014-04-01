SRC						= src
BIN						= bin
TEX						= tex
LIB						= lib
TESTS					= tests
MEDICIONES		= mediciones
GRAFICOS			= graficos

CXX     	= g++
CXXFLAGS	= -Wall -Wno-unused-parameter -Wextra -I$(LIB)
LDFLAGS 	= -I$(LIB) -lrt

all: crear_carpetas problema1 problema2 problema3 medir_performance

problema1: $(SRC)/problema1/problema1.o $(SRC)/problema1/problema1_impl.o
	$(CXX) -o $(BIN)/$@ $^ $(LDFLAGS)

problema1.o: $(SRC)/problema1/problema1.cpp $(SRC)/problema1/problema1.h
	$(CXX) -c $(CXXFLAGS) $<

problema1_impl.o: $(SRC)/problema1/problema1_impl.cpp $(SRC)/problema1/problema1.h
	$(CXX) -c $(CXXFLAGS) $<

problema2: $(SRC)/problema2/problema2.o $(SRC)/problema2/problema2_impl.o
	$(CXX) -o $(BIN)/$@ $^ $(LDFLAGS)

problema2.o: $(SRC)/problema2/problema2.cpp $(SRC)/problema2/problema2.h
	$(CXX) -c $(CXXFLAGS) $<

problema2_impl.o: $(SRC)/problema2/problema2_impl.cpp $(SRC)/problema2/problema2.h
	$(CXX) -c $(CXXFLAGS) $<

problema3: $(SRC)/problema3/problema3.o $(SRC)/problema3/problema3_impl.o
	$(CXX) -o $(BIN)/$@ $^ $(LDFLAGS)

problema3.o: $(SRC)/problema3/problema3.cpp $(SRC)/problema3/problema3.h
	$(CXX) -c $(CXXFLAGS) $<

problema3_impl.o: $(SRC)/problema3/problema3_impl.cpp $(SRC)/problema3/problema3.h
	$(CXX) -c $(CXXFLAGS) $<

medir_performance: $(SRC)/medir_performance.o $(SRC)/problema1/problema1_impl.o $(SRC)/problema2/problema2_impl.o $(SRC)/problema3/problema3_impl.o
	$(CXX) -o $(BIN)/$@ $^ $(LDFLAGS)

medir_performance.o: $(SRC)/medir_performance.cpp $(SRC)/problema1/problema1.h $(SRC)/problema2/problema2.h $(SRC)/problema3/problema3.h
	$(CXX) -c $(CXXFLAGS) $<

informe: $(TEX)/informe.tex
	cd $(TEX); \
	pdflatex informe.tex; \
	mv informe.pdf ..; \
	cd ..

.PHONY: crear_carpetas clean clean_ejecutables clean_mediciones clean_graficos clean_tex clean_todo

crear_carpetas:
	mkdir -p $(BIN)
	mkdir -p $(TESTS)/problema1
	mkdir -p $(TESTS)/problema2
	mkdir -p $(TESTS)/problema3
	mkdir -p $(MEDICIONES)/problema1
	mkdir -p $(MEDICIONES)/problema2
	mkdir -p $(MEDICIONES)/problema3
	mkdir -p $(GRAFICOS)/problema1
	mkdir -p $(GRAFICOS)/problema2
	mkdir -p $(GRAFICOS)/problema3

clean:
	rm -f $(SRC)/*.o
	rm -f $(SRC)/problema1/*.o
	rm -f $(SRC)/problema2/*.o
	rm -f $(SRC)/problema3/*.o

clean_ejecutables:
	rm -f $(BIN)/*

clean_mediciones:
	rm -f $(MEDICIONES)/problema1/*
	rm -f $(MEDICIONES)/problema2/*
	rm -f $(MEDICIONES)/problema3/*

clean_graficos:
	rm -f $(GRAFICOS)/problema1/*
	rm -f $(GRAFICOS)/problema2/*
	rm -f $(GRAFICOS)/problema3/*

clean_tex:
	rm -f $(TEX)/*.aux
	rm -f $(TEX)/*.toc
	rm -f $(TEX)/*.log
	
clean_todo: clean clean_ejecutables clean_mediciones clean_graficos clean_tex
