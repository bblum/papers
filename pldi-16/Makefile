.PHONY: clean

paper.pdf: paper.tex intro.tex related.tex evaluation.tex di.tex citations.bib \
	tree0.pdf tree1.pdf tree2.pdf tree3.pdf
	pdflatex $< ; bibtex $(<:%.tex=%) ; pdflatex $< ; pdflatex $<

clean:
	-rm -f *.aux *.log *.out
