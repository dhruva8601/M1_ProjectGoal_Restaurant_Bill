#Target : Dependancies
#<TAB>commands

Build : main_code.c operations.c
	gcc main_code.c operations.c  -lm -o invoice.out -o operations.out

Run : Build
	./invoice.out 
	

Clean :
	rm -rf *.o *.out *.i *.s *.exe *.txt