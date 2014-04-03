# Impressora

## Servidor

Instale o samba e o cups.

Copie os arquivos de configuração em `etc/samba` e `etc/cups`.

Acesse http://143.106.118.132:631/ e adicione a impressora.

## Usuários - GUI

Adicionar a impressora em rede no endereço 143.106.118.132:631.

## Usuários - CLI

Primeiro adicione o endereço de IP da impressora em `/etc/cups/client.conf` ou
`~/.cups/client.conf`:

~~~
ServerName 143.106.118.132:631
~~~

Talvez você precise reiniciar o CUPS.

Para listar as impressoras:

~~~
$ lpstat -p -d
~~~

Para imprimir:

~~~
$ lp filename
~~~
