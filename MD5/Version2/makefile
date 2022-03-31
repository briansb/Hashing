
Version2 : Version2.o Input.o Output.o Utilities.o
		g++ -g -std=c++11 -Wall -Wextra -Werror -o Version2 Version2.o Input.o Output.o Utilities.o -I.

Version2.o : Version2.cpp Input.h Output.h Utilities.h
		g++ -g -c -std=c++11 -Wall -Wextra -Werror Version2.cpp -I.

Input.o : Input.cpp Input.h 
		g++ -g -c -std=c++11 -Wall -Wextra -Werror Input.cpp -I.

Output.o : Output.cpp Output.h
		g++ -g -c -std=c++11 -Wall -Wextra -Werror Output.cpp -I.

Utilities.o : Utilities.cpp Utilities.h
		g++ -g -c -std=c++11 -Wall -Wextra -Werror Utilities.cpp -I.

zap :
		rm Version2
		rm Version2.o
		rm Input.o
		rm Output.o

