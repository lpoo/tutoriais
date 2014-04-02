#!/bin/bash
export PATH=/usr/local/texlive/2013/bin/x86_64-linux:$PATH

git clone https://github.com/r-gaia-cs/modelo_tese_imecc /tmp/modelo
cd /tmp/modelo
cp -r doc/* /usr/share/nginx/www/mt/
for i in $(git branch -r | grep -v HEAD)
do
	git checkout $i
	latexmk -pdf -pdflatex="pdflatex -interaction nonstopmode" tese
	mv tese.pdf /usr/share/nginx/www/mt/${i/origin\//}.pdf
done
cd ..
rm -rf /tmp/modelo
