.PHONY: clean

paper: paper.tex intro.tex related.tex evaluation.tex design.tex implementation.tex soundness.tex overview.tex warpzone.tex citations.bib \
	trees.pdf dr-jobs.pdf dowefindbugsfaster.pdf nondet-drs-1-v2.pdf totalverifs.pdf
	pdflatex $< ; bibtex $(<:%.tex=%) ; pdflatex $< ; pdflatex $<

clean:
	-rm -f *.aux *.log *.out
