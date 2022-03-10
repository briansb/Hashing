
main : main.o input_output.o
		g++ -g -std=c++11 -Wall -Wextra -Werror -o main main.o input_output.o -I.

main.o : main.cpp 
		g++ -g -c -std=c++11 -Wall -Wextra -Werror main.cpp -I.

input_output.o : input_output.cpp
		g++ -g -c -std=c++11 -Wall -Wextra -Werror input_output.cpp -I.

zap :
		rm main
		rm main.o
		rm input_output.o
