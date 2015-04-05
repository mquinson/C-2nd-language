TARGET=$(shell ls *.tex |grep -v enonce.tex|grep -v correction.tex|sed 's/\.tex$$//')
DISTDIR=/home/mquinson/wiki/Teaching/CSH/

all:pdf

publish: enonce
	@if [ -e sources ] ; then make -C sources publish ;\
	    cp -v sources/*tgz $(DISTDIR);\
	    echo "=> Archive resynchronisée sur la page web";\
	else \
	    echo "=> Pas d'archive à resynchroniser sur la page web";\
	fi
	cp $(TARGET)-enonce.pdf $(DISTDIR) 
	@echo "=> Page web prête à être resynchronisée"

enonce:
	echo \\documentclass[10pt]{article}\\usepackage{esial} > $(TARGET)-enonce.tex
	grep -v documentclass $(TARGET).tex >> $(TARGET)-enonce.tex
	$(MAKE) $(TARGET)-enonce.pdf
	rm -rf `ls $(TARGET)-enonce.*|grep -v '^$(TARGET)-enonce.pdf$$'`
	@echo "=> pdf de l'enoncé regénéré"

correction:
	echo \\documentclass[10pt]{article}\\usepackage[correction]{esial} > $(TARGET)-correction.tex
	grep -v documentclass $(TARGET).tex >> $(TARGET)-correction.tex
	$(MAKE) $(TARGET)-correction.pdf
	rm -rf `ls $(TARGET)-correction.*|grep -v '^$(TARGET)-correction.pdf$$'`
	@echo "=> pdf de la correction regénéré"

include /usr/include/LaTeX.mk
