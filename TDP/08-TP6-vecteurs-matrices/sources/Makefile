include Makefile.defs

all: $(PROGRAMS) generer_vecteur generer_matrice

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

utils_vecteur.o: utils_vecteur.c vecteur.h utils_vecteur.h
	$(CC) $(CFLAGS) -c -include vecteur.h utils_vecteur.c

utils_matrice.o: utils_matrice.c matrice.h utils_matrice.h
	$(CC) $(CFLAGS) -c -include matrice.h utils_matrice.c

utils_matrice_lineaire.o: utils_matrice.c matrice_lineaire.h utils_matrice.h
	$(CC) $(CFLAGS) -c -o $@ -include matrice_lineaire.h utils_matrice.c

t10-matrix.o: t10-matrix.c matrice.h utils_matrice.h
	$(CC) $(CFLAGS) -c -o $@ -include matrice.h t10-matrix.c

t11-matrix-bounds.o: t11-matrix-bounds.c matrice.h utils_matrice.h
	$(CC) $(CFLAGS) -c -o $@ -include matrice.h t11-matrix-bounds.c

matrice_testdynamique.o: matrice_testdynamique.c matrice.h utils_matrice.h
	$(CC) $(CFLAGS) -c -o $@ -include matrice.h matrice_testdynamique.c

t20-matlin.o: t20-matlin.c matrice_lineaire.h utils_matrice.h
	$(CC) $(CFLAGS) -c -o $@ -include matrice_lineaire.h t20-matlin.c

matrice_lineaire_testbornes.o: t21-matlin-bounds.c matrice_lineaire.h utils_matrice.h
	$(CC) $(CFLAGS) -c -o $@ -include matrice_lineaire.h t21-matlin-bounds.c

matrice_lineaire_testdynamique.o: matrice_testdynamique.c matrice_lineaire.h utils_matrice.h
	$(CC) $(CFLAGS) -c -o $@ -include matrice_lineaire.h matrice_testdynamique.c

my_memory.o: my_memory.c
	$(CC) -Wall -Werror -c $<

clean:
	rm -f *.o $(PROGRAMS) *.output generer_matrice generer_vecteur

distclean: clean
	rm -f $(DATAFILES)

# dependences
t00-vector: vecteur.o utils_vecteur.o my_memory.o
t01-vector-bounds: vecteur.o utils_vecteur.o my_memory.o
t02-vector-realloc: vecteur.o utils_vecteur.o my_memory.o

vecteur.o: vecteur.h

t10-matrix: matrice.o utils_matrice.o my_memory.o
t11-matrix-bounds: matrice.o utils_matrice.o my_memory.o
matrice_testdynamique: matrice.o utils_matrice.o my_memory.o

t20-matlin: matrice_lineaire.o utils_matrice_lineaire.o my_memory.o
matrice_lineaire_testbornes: matrice_lineaire.o utils_matrice_lineaire.o my_memory.o
matrice_lineaire_testdynamique: matrice_lineaire.o utils_matrice_lineaire.o my_memory.o

memory_testcpy: memory_testcpy.o memory_operations.o vecteur.o utils_vecteur.o my_memory.o
memory_testmove: memory_testmove.o memory_operations.o vecteur.o utils_vecteur.o my_memory.o
memory_testendianess: memory_testendianess.o memory_operations.o my_memory.o

memory_testcpy.o: vecteur.h memory_operations.h utils_vecteur.h
memory_testmove.o: vecteur.h memory_operations.h utils_vecteur.h
memory_testendianess.o: memory_operations.h

memory_operations.o: memory_operations.h

# Regenere les donnees et les fichiers resultats correspondants
vecteur1.txt vecteur2.txt: generer_vecteur
	./generer_vecteur 1000 > $@

matrice1.txt matrice2.txt: generer_matrice
	./generer_matrice 50 100 > $@


