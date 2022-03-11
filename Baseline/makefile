

main : main.o sha1.o output.o transform.o
		g++ -g -std=c++11 -Wall -Wextra -Werror -o main main.o sha1.o output.o transform.o -I.

main.o : main.cpp sha1.h
		g++ -g -c -std=c++11 -Wall -Wextra -Werror main.cpp -I.

sha1.o : sha1.cpp sha1.h output.h transform.h
		g++ -g -c -std=c++11 -Wall -Wextra -Werror sha1.cpp -I.

output.o : output.cpp output.h
		g++ -g -c -std=c++11 -Wall -Wextra -Werror output.cpp -I.
		
transform.o : transform.cpp transform.h
		g++ -g -c -std=c++11 -Wall -Wextra -Werror transform.cpp -I.

zap :
		rm main *.o




