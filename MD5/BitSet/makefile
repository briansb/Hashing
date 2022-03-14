
BitSet : BitSet.o Input.o Output.o
		g++ -g -std=c++11 -Wall -Wextra -Werror -o BitSet BitSet.o Input.o Output.o -I.

BitSet.o : BitSet.cpp Input.h Output.h
		g++ -g -c -std=c++11 -Wall -Wextra -Werror BitSet.cpp -I.

Input.o : Input.cpp Input.h Definitions.h
		g++ -g -c -std=c++11 -Wall -Wextra -Werror Input.cpp -I.

Output.o : Output.cpp Output.h Definitions.h
		g++ -g -c -std=c++11 -Wall -Wextra -Werror Output.cpp -I.


zap :
		rm BitSet
		rm BitSet.o
		rm Input.o
		rm Output.o
