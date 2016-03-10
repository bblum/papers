.PHONY: clean

paper: paper.tex intro.tex related.tex evaluation.tex design.tex implementation.tex soundness.tex overview.tex warpzone.tex citations.bib \
	trees-v2-squashed.pdf dr-jobs-v2.pdf dowefindbugsfaster-squashed.pdf nondet-drs-1-v2.pdf totalverifs-squashed.pdf
	pdflatex $< ; bibtex $(<:%.tex=%) ; pdflatex $< ; pdflatex $<

clean:
	-rm -f *.aux *.log *.out
