.PHONY: clean

paper.pdf: paper.tex intro.tex related.tex evaluation.tex di.tex citations.bib
	pdflatex $< ; bibtex $(<:%.tex=%) ; pdflatex $< ; pdflatex $<

clean:
	-rm -f *.aux *.log *.out
