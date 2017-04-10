all: OOP-dipoles.pdf OOP-dipoles.tar.gz
PDFLATEX_OPTIONS=-shell-escape

include LaTeX.mk

clean::
	rm -rf cpy.pdf *~ *vrb _region_.tex

OOP-dipoles.tex: OOP-dipoles.org
	emacs -batch --eval "(setq enable-local-eval t)" --eval "(setq enable-local-variables t)" $^  --funcall org-latex-export-to-latex
	mv $@ $@.bak
	echo '\\def\\raggedright{}' > $@
	echo "\PassOptionsToPackage{svgnames}{xcolor}" >> $@
	cat $@.bak >> $@
	rm $@.bak

OOP-dipoles.tar.gz: $(wildcard src/cpp/*) build.sbt killparts Makefile
	rm -rf OOP-dipoles
	mkdir OOP-dipoles
	for n in `ls src/cpp/*.cpp src/cpp/*.hpp Makefile \
	             | grep -v Inductor.[ch]pp \
		     | grep -v Capacitor.[ch]pp \
		     | grep -v CapacitorTest.cpp \
		     `; do \
	  m=`basename $$n`; \
	  ./killparts  $$n OOP-dipoles/$$m ; \
	done
	cp src/cpp/Makefile OOP-dipoles
	tar cvfz OOP-dipoles.tar.gz --exclude-backups OOP-dipoles
#	rm OOP-dipoles