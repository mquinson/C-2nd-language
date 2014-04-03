include ../Makefile-TP
include sources/Makefile.defs

all:: CSH-TP6.tgz

CSH-TP6.tgz: $(addprefix sources/,$(PRORGRAMS) $(DATAFILES))
	rm -rf CSH-TP6
	mkdir CSH-TP6
	for file in $(EXERCICES);do cat sources/$$file | ./filtre SUJET >CSH-TP6/$$file;done
	for file in $(TDP_FILES);do cp -p sources/$$file CSH-TP6;done
	tar cfz CSH-TP6.tgz CSH-TP6
	rm -rf CSH-TP6

publish:: CSH-TP6.tgz
	cp CSH-TP6.tgz $(DISTDIR)


Correction: $(EXERCICES)
	if [ ! -d Correction ];then mkdir Correction;fi
	for file in $^;do cat $$file | ./filtre SOLUTION >Correction/$$file;done
