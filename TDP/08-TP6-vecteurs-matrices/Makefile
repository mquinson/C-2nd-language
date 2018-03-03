include ../Makefile-TP
include sources/Makefile.defs

all:: TP-vector-matrix.tgz

TP-vector-matrix.tgz: $(addprefix sources/,$(addsuffix .c,$(PROGRAMS)) $(DATAFILES))
	rm -rf TP-vector-matrix
	mkdir TP-vector-matrix
	for file in $(EXERCICES);do cat sources/$$file | ./filtre SUJET >TP-vector-matrix/$$file;done
	for file in $(TDP_FILES);do cp -p sources/$$file TP-vector-matrix;done
	tar cfz TP-vector-matrix.tgz TP-vector-matrix
	rm -rf TP-vector-matrix

publish:: TP-vector-matrix.tgz
	cp TP-vector-matrix.tgz $(DISTDIR)


Correction: $(EXERCICES)
	if [ ! -d Correction ];then mkdir Correction;fi
	for file in $^;do cat $$file | ./filtre SOLUTION >Correction/$$file;done
