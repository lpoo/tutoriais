# Instalando Debian

Você encontram as imagens do Debina
[aqui](http://www.debian.org/CD/torrent-cd/).

## Particionamento

O modelo de particionamento encontra-se [aqui](particionamento.md).

## Primeiro login

Copie esse diretório para a `$HOME` do `root`.

## Programas

Atualize `/etc/apt/sources.list`:

~~~
# cp -r etc/apt/ /etc/
~~~

Atualize a lista de pacotes:

~~~
# apt-get update
~~~

Instale os programas listados [aqui](PROGRAMAS) e no caso do servidor também instale
[esses programas](PROGRAMAS-SERVIDOR) utilizando

~~~
# apt-get install nome-do-programa
~~~

Alguns programas precisam de um cuidado especial e maiores
informações encontram-se a seguir.

### Jekyll

~~~
# apt-get install ruby1.9.1-full gems
# gem install --no-user-install jekyll
~~~

### LaTeX

Leia [as instruções sobre o LaTeX](latex.md).

## Configuração

Para configurar alguns programas siga as instruções abaixo.

### Nginx

Leia [as instruções sobre o nginx](nginx-servidor.md).
