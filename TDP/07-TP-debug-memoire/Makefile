include ../Makefile-TP

all:: CSH-TP5.tgz

CSH-TP5.tgz: sources/boom.c  sources/boucle.c  sources/fact.c
	rm -rf CSH-TP5
	mkdir CSH-TP5
	cp $^ CSH-TP5
	tar cfz CSH-TP5.tgz CSH-TP5
	rm -rf CSH-TP5

publish:: CSH-TP5.tgz
	cp CSH-TP5.tgz $(DISTDIR)


