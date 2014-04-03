LATEXFILTER=/usr/share/texmf/scripts/latex-make/latexfilter.py |\
  grep -v 'Overfull .[vh]box ([^)]*) has occurred while .output is active' |\
  grep -v 'Underfull .[vh]box ([^)]*) has occurred while .output is active' |\
  grep -v 'Overfull .[vh]box ([^)]*) in paragraph at lines ' |\
  grep -v 'Overfull .[vh]box ([^)]*) detected at line ' |\
  grep -v 'hyperref[^r]*removing' | \
  grep -v 'Overfull .[vh]box ([^)]*) detected at line ' |\
  grep -v ' \\OT1/cmss/m/n/5 ' |\
  grep  '[a-zA-Z]' |\
  grep -v 'Package hyperref Warning: Token not allowed in a PDFDocEncoded string,' 

TARGET=CSH
DISTDIR?=/home/mquinson/wiki/Teaching/CSH/

VPATH=/usr/share/texmf/tex/latex/esial/:fig/

all: pdf
include LaTeX.mk

%.pdf: %.tex

dist:publish
publish: handout beamer $(TARGET)-4up.pdf
	cp $(TARGET)-handout.pdf $(TARGET)-beamer.pdf $(TARGET)-4up.pdf $(DISTDIR)
	                
prof: $(TARGET).tex
	echo \\documentclass[10pt,trans,notes=show]{beamer} >  $(TARGET)-prof.tex
	grep -v documentclass $(TARGET).tex                 >> $(TARGET)-prof.tex
	$(MAKE) $(TARGET)-prof.pdf
	rm -rf `ls $(TARGET)-prof.*|grep -v '^$(TARGET)-prof.pdf$$'`

handout: handout.stamp
handout.stamp: $(TARGET).tex
	echo \\documentclass[10pt,handout]{beamer} >         $(TARGET)-handout.tex
	grep -v documentclass $(TARGET).tex        >>        $(TARGET)-handout.tex
	$(MAKE) $(TARGET)-handout.pdf
	rm -rf `ls $(TARGET)-handout.*|grep -v '^$(TARGET)-handout.pdf$$'`
	touch handout.stamp

beamer: beamer.stamp
beamer.stamp: $(TARGET).tex
	echo \\documentclass[10pt]{beamer}         >         $(TARGET)-beamer.tex
	grep -v documentclass $(TARGET).tex        >>        $(TARGET)-beamer.tex
	$(MAKE) $(TARGET)-beamer.pdf
	rm -rf `ls $(TARGET)-beamer.*|grep -v '^$(TARGET)-beamer.pdf$$'`
	touch beamer.stamp

$(TARGET)-4up.pdf: $(TARGET).pdf
	beamer2handout $(TARGET)-handout.pdf 4up $(TARGET)-4up.pdf

.PHONY: up 4up 6up 16up 25up 
up: 4up 6up 16up 25up 
#4up: $(TARGET).4up.pdf
#6up: $(TARGET).6up.pdf
#8up: $(TARGET).8up.pdf
#16up: $(TARGET).16up.pdf
#25up: $(TARGET).25up.pdf
#
#$(TARGET).4up.pdf: $(TARGET).pdf
#
#
#$(TARGET).16up.pdf: $(TARGET).pdf
#	beamer2handout $(TARGET).pdf 16up 16up.pdf
#	
#	
#$(TARGET).8up.pdf: $(TARGET).pdf
#	beamer2handout $(TARGET).pdf 8up 8up.pdf
#	
#$(TARGET).25up.pdf: $(TARGET).pdf ~/SCRIPTS/beamer2handout
#	beamer2handout $(TARGET).pdf 25up 25up.pdf
