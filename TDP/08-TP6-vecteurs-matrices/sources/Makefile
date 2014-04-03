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
	@for file in `echo $^ | grep -v txt`;\
	do ./$$file > $$file.result;\
	done

%: %.o
	$(CC) -o $@ $^

%.o: %.c my_memory.h
	$(CC) $(CFLAGS) -c $<

utils_vecteur.o: utils_vecteur.c vecteur.h utils_vecteur.h
	$(CC) $(CFLAGS) -c -include vecteur.h utils_vecteur.c

utils_vecteur_dynamique.o: utils_vecteur.c vecteur_dynamique.h utils_vecteur.h
	$(CC) $(CFLAGS) -c -o $@ -include vecteur_dynamique.h utils_vecteur.c

utils_matrice.o: utils_matrice.c matrice.h utils_matrice.h
	$(CC) $(CFLAGS) -c -include matrice.h utils_matrice.c

utils_matrice_dynamique.o: utils_matrice.c matrice_dynamique.h utils_matrice.h
	$(CC) $(CFLAGS) -c -o $@ -include matrice_dynamique.h utils_matrice.c

utils_matrice_lineaire.o: utils_matrice.c matrice_lineaire.h utils_matrice.h
	$(CC) $(CFLAGS) -c -o $@ -include matrice_lineaire.h utils_matrice.c

utils_matrice_lineaire_dynamique.o: utils_matrice.c matrice_lineaire_dynamique.h utils_matrice.h
	$(CC) $(CFLAGS) -c -o $@ -include matrice_lineaire_dynamique.h utils_matrice.c

matrice_testbase.o: matrice_testbase.c matrice.h utils_matrice.h
	$(CC) $(CFLAGS) -c -o $@ -include matrice.h matrice_testbase.c

matrice_testbornes.o: matrice_testbornes.c matrice.h utils_matrice.h
	$(CC) $(CFLAGS) -c -o $@ -include matrice.h matrice_testbornes.c

matrice_testdynamique.o: matrice_testdynamique.c matrice_dynamique.h utils_matrice.h
	$(CC) $(CFLAGS) -c -o $@ -include matrice_dynamique.h matrice_testdynamique.c

matrice_lineaire_testbase.o: matrice_testbase.c matrice_lineaire.h utils_matrice.h
	$(CC) $(CFLAGS) -c -o $@ -include matrice_lineaire.h matrice_testbase.c

matrice_lineaire_testbornes.o: matrice_testbornes.c matrice_lineaire.h utils_matrice.h
	$(CC) $(CFLAGS) -c -o $@ -include matrice_lineaire.h matrice_testbornes.c

matrice_lineaire_testdynamique.o: matrice_testdynamique.c matrice_lineaire_dynamique.h utils_matrice.h
	$(CC) $(CFLAGS) -c -o $@ -include matrice_lineaire_dynamique.h matrice_testdynamique.c

my_memory.o: my_memory.c
	$(CC) -Wall -Werror -c $<

clean:
	rm -f *.o $(PROGRAMS) *.output generer_matrice generer_vecteur

distclean: clean
	rm -f $(DATAFILES)

dist: *.h *.c $(DIST_FILES)
	tar cvzf TDP4_Etudiants.tgz $?

# dependences
vecteur_testbase: vecteur.o utils_vecteur.o my_memory.o
vecteur_testbornes: vecteur_verif.o utils_vecteur.o my_memory.o
vecteur_testdynamique: vecteur_dynamique.o utils_vecteur_dynamique.o my_memory.o

vecteur_testbase.o: vecteur.h utils_vecteur.h
vecteur_testbornes.o: vecteur.h utils_vecteur.h
vecteur_testdynamique.o: vecteur_dynamique.h utils_vecteur.h

vecteur.o: vecteur.h
vecteur_verif.o: vecteur.h
vecteur_dynamique.o: vecteur_dynamique.h

matrice_testbase: matrice.o utils_matrice.o my_memory.o
matrice_testbornes: matrice_verif.o utils_matrice.o my_memory.o
matrice_testdynamique: matrice_dynamique.o utils_matrice_dynamique.o my_memory.o

matrice.o: matrice.h
matrice_verif.o: matrice.h
matrice_dynamique.o: matrice_dynamique.h

matrice_lineaire_testbase: matrice_lineaire.o utils_matrice_lineaire.o my_memory.o
matrice_lineaire_testbornes: matrice_lineaire_verif.o utils_matrice_lineaire.o my_memory.o
matrice_lineaire_testdynamique: matrice_lineaire_dynamique.o utils_matrice_lineaire_dynamique.o my_memory.o

matrice_lineaire.o: matrice_lineaire.h
matrice_lineaire_verif.o: matrice_lineaire.h
matrice_lineaire_dynamique.o: matrice_lineaire_dynamique.h

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
	

