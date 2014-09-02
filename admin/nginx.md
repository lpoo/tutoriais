# Nginx

## Configuração

Crie um usuário `nginx` cuja `$HOME` irá hospedar as páginas HTML.

~~~
# adduser -home /home/nginx nginx
~~~

Atualize `/etc/nginx`:

~~~
# cp -r etc/nginx/ /etc/
~~~

Habilite e inicie o nginx:

~~~
# systemctl enable nginx
# systemctl start nginx
~~~

## Homepage

Clone os arquivos no repositório
[lpoo.github.io](https://github.com/lpoo/lpoo.github.io).

~~~
# su nginx
$ git clone https://github.com/lpoo/lpoo.github.io.git
$ cd lpoo.github.io.git
$ jekyll 
$ cp -r _site/* ~/public
$ exit
~~~

Verifique se a [homepage](http://www.lpoo.ime.unicamp.br/) está correta.

## Cron

Utilizamos o cron para atualizar nossas páginas diariamente.

~~~
# crontab -u nginx cron/nginx
~~~
