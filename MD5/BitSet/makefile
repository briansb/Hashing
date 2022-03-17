
BitSet : BitSet.o Input.o Output.o Utilities.o
		g++ -g -std=c++11 -Wall -Wextra -Werror -o BitSet BitSet.o Input.o Output.o Utilities.o -I.

BitSet.o : BitSet.cpp Input.h Output.h Utilities.h
		g++ -g -c -std=c++11 -Wall -Wextra -Werror BitSet.cpp -I.

Input.o : Input.cpp Input.h Definitions.h
		g++ -g -c -std=c++11 -Wall -Wextra -Werror Input.cpp -I.

Output.o : Output.cpp Output.h Definitions.h
		g++ -g -c -std=c++11 -Wall -Wextra -Werror Output.cpp -I.

Utilities.o : Utilities.cpp Utilities.h Definitions.h
		g++ -g -c -std=c++11 -Wall -Wextra -Werror Utilities.cpp -I.

zap :
		rm BitSet
		rm BitSet.o
		rm Input.o
		rm Output.o
		rm Utilities.o
