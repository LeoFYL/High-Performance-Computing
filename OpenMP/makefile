.PHONY : all
all : cell_distances 

cell_distances : cell_distances.c
	gcc -O2 -o $@ $< -lm -fopenmp

.PHONY : clean
clean :
	rm -f *.o
