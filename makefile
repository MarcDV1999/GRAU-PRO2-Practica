OPCIONS = -D_JUDGE_ -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe:
	g++ -o program.exe BinTreeIOint.cc Conjunto_Usuarios.cpp cluster.cpp program.cc procesador.cpp proceso.cpp sistema.cpp usuario.cpp $(OPCIONS)

documentacio: Doxyfile
	doxygen Doxyfile

practica.tar:
	tar -cvf practica.tar BinTreeIOint.cc BinTreeIOint.hh cluster.cpp cluster.hpp Conjunto_Usuarios.cpp Conjunto_Usuarios.hpp procesador.cpp procesador.hpp proceso.cpp proceso.hpp program.cc program.exe sistema.cpp sistema.hpp usuario.cpp usuario.hpp makefile 

documentacio: Doxyfile
	doxygen Doxyfile

clean:
	rm -f *.o
	rm -f *.exe
	rm -f *.tar
	rm -f *.zip
