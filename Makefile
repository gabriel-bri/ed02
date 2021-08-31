all:
	g++ main.cpp Fila.h Fila.cpp arvore.h arvore.cpp –o projeto
run:
	./projeto
clean:
	rm ./projeto
