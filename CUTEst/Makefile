# As variaveis a seguir podem ser informadas pela linha de comando.
lang=pt_br

help:
	@echo "Por favor utilize \`make <target>' onde <target> eh:"
	@echo "  pdf    para gerar o pdf."
	@echo ""
	@echo "Para alterar a lingua utilize \`make lang=<target_lang> <target>'"
	@echo "onde <target_lang> eh a sigla para a lingua desejada"
	@echo "(o valor padrão eh \`pt_br')."

pdf: 
	cd $(lang); latexmk -pdf cutest.tex; cp cutest.pdf ../cutest_$(lang).pdf

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
