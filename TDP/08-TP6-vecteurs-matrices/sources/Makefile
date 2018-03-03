include Makefile.defs

all: $(PROGRAMS) generer_vector generer_matrix

test: $(PROGRAMS)
	@echo;echo "*** TESTS ***";echo;\
	chmod +x teste_programme; \
	for file in $^;\
	do echo -n "$$file : ";\
	   ./teste_programme $$file 2>/dev/null;\
	done

testsuite: $(PROGRAMS) $(DATAFILES)
	for file in `echo $^ | grep -v txt`;\
	do ./$$file > $$file.result;\
	done

%: %.o
	$(CC) -o $@ $^

%.o: %.c utils_memory.h
	$(CC) $(CFLAGS) -c $<



utils_memory.o: utils_memory.c
	$(CC) -Wall -Werror -c $<

clean:
	rm -f *.o $(PROGRAMS) *.output generer_matrix generer_vector

distclean: clean
	rm -f $(DATAFILES)

# dependences
utils_vector.o: utils_vector.c vector.h utils_vector.h
utils_matrix.o: utils_matrix.c matrix.h utils_matrix.h
utils_matlin.o: utils_matlin.c matlin.h utils_matlin.h

vector.o: vector.h
t11-vector:         vector.o utils_vector.o utils_memory.o
t12-vector-bounds:  vector.o utils_vector.o utils_memory.o
t13-vector-realloc: vector.o utils_vector.o utils_memory.o

t21-matrix.o:        matrix.h utils_matrix.h
t22-matrix-bounds.o: matrix.h utils_matrix.h
t23-matrix-realloc.o:matrix.h utils_matrix.h
t21-matrix:          matrix.o utils_matrix.o utils_memory.o
t22-matrix-bounds:   matrix.o utils_matrix.o utils_memory.o
t23-matrix-realloc:  matrix.o utils_matrix.o utils_memory.o

t31-matlin.o:        matlin.h utils_matlin.h
t32-matlin-bounds.o: matlin.h utils_matlin.h
t22-matlin-realloc.o:matlin.h utils_matlin.h
t31-matlin:          matlin.o utils_matlin.o utils_memory.o
t32-matlin-bounds:   matlin.o utils_matlin.o utils_memory.o
t33-matlin-realloc:  matlin.o utils_matlin.o utils_memory.o

memory.o: memory.h
t41-memory-cpy.o:       memory.h vector.h utils_vector.h
t42-memory-move.o:      memory.h vector.h utils_vector.h
t43-memory-endianess.o: memory.h
t41-memory-cpy:         memory.o utils_memory.o vector.o utils_vector.o
t42-memory-move:        memory.o utils_memory.o vector.o utils_vector.o
t43-memory-endianess:   memory.o utils_memory.o

# Regenere les donnees et les fichiers resultats correspondants
data_vector1.txt data_vector2.txt: generer_vector
	./generer_vector 1000 > $@

data_matrix1.txt data_matrix2.txt: generer_matrix
	./generer_matrix 50 100 > $@


