OPCIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++11
#
# La siguiente instruccion significa:
# para obtener pro2_s8.exe es necesario que exista pro2_s8.o;
# si pro2_s8.exe no existe o es mas antiguo que pro2_s8.o,
# se obtiene con el g++ -o ... (el tabulador antes de g++ es necesario)
#
program.exe: program.o individu.o especie.o cromosoma.o
	g++ -o program.exe program.o individu.o especie.o cromosoma.o
#
# La siguiente instruccion significa:
# para obtener pro2_s8.o es necesario que exista pro2_s8.cc;
# si pro2_s8.o no existe o es mas antiguo que pro2_s8.cc,
# se obtiene con el g++ -c ...
#
especie.o: especie.cc 
	g++ -c especie.cc $(OPCIONS)
individu.o: individu.cc 
	g++ -c individu.cc $(OPCIONS)
cromosoma.o: cromosoma.cc
	g++ -c cromosoma.cc $(OPCIONS)
program.o: program.cc
	g++ -c program.cc $(OPCIONS)
#
# Realizad las modificaciones necesarias para gestionar las clases de la
# sesiÃ³n cuando os toque implementarlas a vosotros.
#
# Esta Ãºltima opciÃ³n sirve para limpiar el directorio de ficheros
# innecesarios; se ejecuta mediante el comando "make clean"
#

tar:
	tar -cvf practica.tar *.cc *.hh Makefile

clean:
	rm *.o
	rm *.exe
