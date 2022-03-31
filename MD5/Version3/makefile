
Version3 : Version3.o Input.o Output.o Utilities.o
		g++ -g -std=c++11 -Wall -Wextra -Werror -o Version3 Version3.o Input.o Output.o Utilities.o -I.

Version3.o : Version3.cpp Input.h Output.h Utilities.h
		g++ -g -c -std=c++11 -Wall -Wextra -Werror Version3.cpp -I.

Input.o : Input.cpp Input.h 
		g++ -g -c -std=c++11 -Wall -Wextra -Werror Input.cpp -I.

Output.o : Output.cpp Output.h
		g++ -g -c -std=c++11 -Wall -Wextra -Werror Output.cpp -I.

Utilities.o : Utilities.cpp Utilities.h
		g++ -g -c -std=c++11 -Wall -Wextra -Werror Utilities.cpp -I.


zap :
		rm Version3
		rm Version3.o
		rm Input.o
		rm Output.o
