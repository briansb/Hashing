
Version5 : Version5.o Input.o Output.o Utilities.o Routine.o
		g++ -g -std=c++11 -Wall -Wextra -Werror -o Version5 Version5.o Input.o Output.o Utilities.o Routine.o -I.

Version5.o : Version5.cpp Input.h Output.h Utilities.h Routine.h
		g++ -g -c -std=c++11 -Wall -Wextra -Werror Version5.cpp -I.

Input.o : Input.cpp Input.h 
		g++ -g -c -std=c++11 -Wall -Wextra -Werror Input.cpp -I.

Output.o : Output.cpp Output.h
		g++ -g -c -std=c++11 -Wall -Wextra -Werror Output.cpp -I.

Utilities.o : Utilities.cpp Utilities.h
		g++ -g -c -std=c++11 -Wall -Wextra -Werror Utilities.cpp -I.

Routine.o : Routine.cpp Routine.h
		g++ -g -c -std=c++11 -Wall -Wextra -Werror Routine.cpp -I.


zap :
		rm Version5
		rm Version5.o
		rm Input.o
		rm Output.o
