.PHONY: clean

paper: paper.tex intro.tex related.tex evaluation.tex di.tex citations.bib \
	trees.pdf dr-jobs.pdf
	pdflatex $< ; bibtex $(<:%.tex=%) ; pdflatex $< ; pdflatex $<

proof: proof.tex citations.bib
	pdflatex $< ; bibtex $(<:%.tex=%) ; pdflatex $< ; pdflatex $<

clean:
	-rm -f *.aux *.log *.out
