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

TARGET?=$(shell ls *.tex |grep -v -- -beamer.tex|grep -v -- -handout.tex|grep -v '^[0-9]'|grep -v 'UNUSED'|sed 's/\.tex$$//')
DISTDIR?=/home/mquinson/public_html/Teaching/SDR/

VPATH=/usr/share/texmf/tex/latex/esial/:fig/

all: pdf
include LaTeX.mk

%.pdf: %.tex

dist:publish
publish: handout 
	cp $(TARGET)-handout.pdf $(TARGET)-8up.pdf $(DISTDIR)
	$(MAKE) -C ~/public_html publish
	                
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
	beamer2handout $(TARGET).pdf 8up $(TARGET)-8up.pdf
	touch handout.stamp

beamer: beamer.stamp
beamer.stamp: $(TARGET).tex
	echo \\documentclass[10pt]{beamer}         >         $(TARGET)-beamer.tex
	grep -v documentclass $(TARGET).tex        >>        $(TARGET)-beamer.tex
	$(MAKE) $(TARGET)-beamer.pdf
	rm -rf `ls $(TARGET)-beamer.*|grep -v '^$(TARGET)-beamer.pdf$$'`
	touch beamer.stamp

8up.pdf: DistributedSystems.pdf
	beamer2handout DistributedSystems.pdf 8up 8up.pdf
25up.pdf: DistributedSystems.pdf
	beamer2handout DistributedSystems.pdf 25up 25up.pdf
4up.pdf: DistributedSystems.pdf
	beamer2handout DistributedSystems.pdf 4up 4up.pdf

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
