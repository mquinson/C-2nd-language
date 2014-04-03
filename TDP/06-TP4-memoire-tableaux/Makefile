include ../Makefile-TP

all:: CSH-TP4.tgz

CSH-TP4.tgz: sources/codage.c  sources/code1.c  sources/code2.c  sources/dice_poker.c
	rm -rf CSH-TP4
	mkdir CSH-TP4
	cp $^ CSH-TP4
	tar cfz CSH-TP4.tgz CSH-TP4
	rm -rf CSH-TP4

publish:: CSH-TP4.tgz
	cp CSH-TP4.tgz $(DISTDIR)


