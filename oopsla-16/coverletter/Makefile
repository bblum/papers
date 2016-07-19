.PHONY: all letter
PDFLATEX=${TEXPATH}pdflatex -output-format pdf
BIBTEX=${TEXPATH}bibtex
LATEXTARGET=letter

all: letter

letter:
	${PDFLATEX} ${LATEXTARGET}.tex

bib: ../citations.bib
	${BIBTEX} letter

clean:
	rm -f *~ *.aux *.log *.bbl *.blg

cleaner: clean
	rm -f *.pdf
