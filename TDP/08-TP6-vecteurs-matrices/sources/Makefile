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

%.o: %.c my_memory.h
	$(CC) $(CFLAGS) -c $<

utils_vector.o: utils_vector.c vector.h utils_vector.h
	$(CC) $(CFLAGS) -c -include vector.h utils_vector.c

utils_matrix.o: utils_matrix.c matrix.h utils_matrix.h
	$(CC) $(CFLAGS) -c -include matrix.h utils_matrix.c

utils_matlin.o: utils_matrix.c matlin.h utils_matlin.h
	$(CC) $(CFLAGS) -c -o $@ -include matlin.h utils_matlin.c

t10-matrix.o: t10-matrix.c matrix.h utils_matrix.h
	$(CC) $(CFLAGS) -c -o $@ -include matrix.h t10-matrix.c

t11-matrix-bounds.o: t11-matrix-bounds.c matrix.h utils_matrix.h
	$(CC) $(CFLAGS) -c -o $@ -include matrix.h t11-matrix-bounds.c

t12-matrix-realloc.o: t12-matrix-realloc.c matrix.h utils_matrix.h
	$(CC) $(CFLAGS) -c -o $@ -include matrix.h t12-matrix-realloc.c

t20-matlin.o: t20-matlin.c matlin.h utils_matlin.h
	$(CC) $(CFLAGS) -c -o $@ -include matlin.h t20-matlin.c

t21-matlin-bounds.o: t21-matlin-bounds.c matlin.h utils_matlin.h
	$(CC) $(CFLAGS) -c -o $@ -include matlin.h t21-matlin-bounds.c

t22-matlin-realloc.o: t22-matlin-realloc.c matlin.h utils_matlin.h
	$(CC) $(CFLAGS) -c -o $@ -include matlin.h t22-matlin-realloc.c

my_memory.o: my_memory.c
	$(CC) -Wall -Werror -c $<

clean:
	rm -f *.o $(PROGRAMS) *.output generer_matrix generer_vector

distclean: clean
	rm -f $(DATAFILES)

# dependences
t00-vector: vector.o utils_vector.o my_memory.o
t01-vector-bounds: vector.o utils_vector.o my_memory.o
t02-vector-realloc: vector.o utils_vector.o my_memory.o

vector.o: vector.h

t10-matrix: matrix.o utils_matrix.o my_memory.o
t11-matrix-bounds: matrix.o utils_matrix.o my_memory.o
t12-matrix-realloc: matrix.o utils_matrix.o my_memory.o

t20-matlin: matlin.o utils_matlin.o my_memory.o
t21-matlin-bounds: matlin.o utils_matlin.o my_memory.o
t22-matlin-realloc: matlin.o utils_matlin.o my_memory.o

memory_testcpy: memory_testcpy.o memory_operations.o vector.o utils_vector.o my_memory.o
memory_testmove: memory_testmove.o memory_operations.o vector.o utils_vector.o my_memory.o
memory_testendianess: memory_testendianess.o memory_operations.o my_memory.o

memory_testcpy.o: vector.h memory_operations.h utils_vector.h
memory_testmove.o: vector.h memory_operations.h utils_vector.h
memory_testendianess.o: memory_operations.h

memory_operations.o: memory_operations.h

# Regenere les donnees et les fichiers resultats correspondants
vector1.txt vector2.txt: generer_vector
	./generer_vector 1000 > $@

matrix1.txt matrix2.txt: generer_matrix
	./generer_matrix 50 100 > $@


