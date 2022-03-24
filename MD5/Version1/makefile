
Version1 : Version1.o Input.o Output.o
		g++ -g -std=c++11 -Wall -Wextra -Werror -o Version1 Version1.o Input.o Output.o -I.

Version1.o : Version1.cpp Input.h Output.h
		g++ -g -c -std=c++11 -Wall -Wextra -Werror Version1.cpp -I.

Input.o : Input.cpp Input.h 
		g++ -g -c -std=c++11 -Wall -Wextra -Werror Input.cpp -I.

Output.o : Output.cpp Output.h
		g++ -g -c -std=c++11 -Wall -Wextra -Werror Output.cpp -I.

#Utilities.o : Utilities.cpp Utilities.h Definitions.h
#		g++ -g -c -std=c++11 -Wall -Wextra -Werror Utilities.cpp -I.

zap :
		rm Version1
		rm Version1.o
		rm Input.o
		rm Output.o
#		rm Utilities.o
