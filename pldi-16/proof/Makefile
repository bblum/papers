.PHONY: clean

proof: proof.tex di.tex assumptions.tex convergence.tex recycle.tex ../citations.bib
	pdflatex $< ; bibtex $(<:%.tex=%) ; pdflatex $< ; pdflatex $<

clean:
	-rm -f *.aux *.log *.out
