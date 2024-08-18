.PHONY: all clean

BANDERAS = -std=c++11 -Wall -g
SALIDA = asistente

all: ejemplo

ejemplo:
	g++ $(BANDERAS) Node.cpp main.cpp  -o $(SALIDA)

clean:
	rm -r *.dSYM $(SALIDA)
