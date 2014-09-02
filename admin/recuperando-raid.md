# Recuperando um HD com RAID

Na verdade, este não é um tutorial, e sim um relatório do que feito para
recuperar informação de um HD que estava em RAID, com bad block, e que foi
substituído.

## Situação

O HD não falhou terminalmente. Ele estava causando reiniciamento e, após
verificação, foi constatado que ele tinha bad blocks.

Pouco tempo depois conseguimos HDs novos. Como já tinhámos guardado o backup do
servidor antigo por alguns anos, e ninguém mais procurou, decidimos não fazer um
backup para o servidor novo.

Após alguns meses, foi requerido um arquivo que estava nesse backup.

## O processo

Conectamos o HD utilizando um case para HD externo.

Primeiro verificamos sua numeração no device:

    # fdisk -l

Obtivemos a informação de que os dados estavam em /dev/sdb2 e o device RAID
correspondente era /dev/md127. Um mount foi tentado, mas não funcionou.
Examinamos o HD com o comando

    # mdadm --examine /dev/sdb

Nenhuma mensagem importante foi passada. Após alguma busca na internet,
obtivemos um comando que deveria montar/preparar o sdb2 ao md127. O comando foi
passada mas não funcionou de primeira porque o device estava ocupado. Utilizamos
o comando

    # mdadm -S /dev/md127

para parar o device, e então repetimos o comando

    # mdadm --assemble --force /dev/md127 /dev/sdb2

Que ligou o sdb2 ao md127. Daí, montamos o dispositivo com

    # mount /dev/md127 /mnt/backup

E realizamos o backup.

Após o backup, desmontamos e paramos o device

    # umount /mnt/backup
    # mdadm -S /dev/md127


