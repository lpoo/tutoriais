# Instalando Arch

Você encontram as imagens do Arch
[aqui](https://www.archlinux.org/download/).

## Instalação

Se estiver utilizando um teclado ABNT2 você terá que informá-lo:

~~~
# loadkeys br-abnt2
~~~

Também é recomendado modificar a fonte:

~~~
# setfont Lat2-Terminus16
~~~

Verifique se possue conexão de internet:

~~~
# ping -c 10 8.8.8.8
~~~

O modelo de particionamento encontra-se [aqui](particionamento.md). Para
realizar o particionamento utilize o `gdisk` ou o `cgdisk`.

Depois de particionado, formate as partições utilizando o `mkfs`.

Para montar as partições utilize `mount`.

Edite o arquivo `/etc/pacman.d/mirrorlist` para selecionar de onde será baixado
os arquivos.

Para instalar, utilize

~~~
# pacstrap /mnt base base-devel
~~~

Crie o arquivo `fstab`:

~~~
# genfstab -p -U /mnt >> /mnt/etc/fstab
~~~

Entre no novo sistema

~~~
# arch-chroot /mnt
~~~

e configure novamente o teclado. Para salvar a configuração do teclado, adicione
as linhas abaixo no arquivo `/etc/vconsole.conf`.

~~~
KEYMAP=br-abnt2
FONT=Lat2-Terminus16
~~~

Também configure novamente a conexão de internet e o hostname.

Crie um link simbólico para o fuso horário de Brasília.

~~~
# ls -s /usr/share/zoneinfo/America/Sao_Paulo /etc/localtime
~~~

Edite o arquivo `/etc/locale.gen` removendo o `#` das linhas

~~~
#en_US UTF-8 UTF-8
#pt_BR UTF-8 UTF-8
~~~

Depois de editar as linhas, execute

~~~
# locale-gen
# echo LANG=en_US.UTF-8 > /etc/locale.conf
# export LANG=en_US.UTF-8
~~~

Configure uma senha para o usuário `root`:

~~~
# passwd root
~~~

Instale o Syslinux:

~~~
# pacman -S syslinux
~~~

Execute

~~~
# pacman -S gptfdisk
# syslinux-install_update -i -a -m
~~~

Edite o arquivo `/boot/syslinux/syslinux.cfg` de forma a ter as seguintes
linhas:

~~~
LABEL arch
        LINUX ../vmlinuz-linux
        APPEND root=UUID=978e3e81-8048-4ae1-8a06-aa727458e8ff ro
        INITRD ../initramfs-linux.img
~~~

Por último, reinicie a máquina.

~~~
# exit
# umount /mnt/{boot,home,}
# reboot
~~~
\end{lstlisting}

## Primeiro login

Copie esse diretório para a `$HOME` do `root`.

## Programas

Atualize a lista de pacotes e os pacotes instalados:

~~~
# pacman -Syu
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
# pacman -S ruby
# gem install --no-user-install jekyll
~~~

### LaTeX

Leia [as instruções sobre o LaTeX](latex.md).

## Configuração

Para configurar alguns programas siga as instruções abaixo.

### Nginx

Leia [as instruções sobre o nginx](nginx-servidor.md).
