.PHONY: clean

paper.pdf: paper.tex citations.bib intro.tex conclusion.tex 410.tex landslide.tex \
	eval.tex threadfork/threadfork.pdf
	pdflatex $< ; bibtex $(<:%.tex=%) ; pdflatex $< ; pdflatex $<

clean:
	-rm -f *.aux *.log *.out
