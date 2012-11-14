lang=pt_br

all: pdf bibtex
	cd $(lang); pdflatex -interaction=nonstopmode -output-directory ../ cuter
	cd $(lang); pdflatex -interaction=nonstopmode -output-directory ../ cuter

pdf:
	cd $(lang); pdflatex -interaction=nonstopmode -output-directory ../ cuter

bibtex:
	bibtex cuter

clean:
	- rm *.acn
	- rm *.acr
	- rm *.alg
	- rm *.aux
	- rm *.bbl
	- rm *.blg
	- rm *.fdb_latexmk
	- rm *.glg
	- rm *.glo
	- rm *.gls
	- rm *.idx
	- rm *.ilg
	- rm *.ind
	- rm *.ist
	- rm *.loa
	- rm *.lol
	- rm *.lof
	- rm *.log
	- rm *.lot
	- rm *.maf
	- rm *.mtc
	- rm *.mtc0
	- rm *.nav
	- rm *.nlo
	- rm *.out
	- rm *.pdfsync
	- rm *.snm
	- rm *.synctex.gz
	- rm *.toc
	- rm *.vrb
	- rm *.xdy
	- rm *.tdo
