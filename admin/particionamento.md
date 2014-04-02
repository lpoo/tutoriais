# Particionamento

## Máquinas de usuários

As máquinas de usuário normalmente possuem apenas um disco de 1TB.

+-----------+---------+-------+-------------------+
+ Volume    + Tamanho + Label + Ponto de Montagem +
+-----------+---------+-------+-------------------+
+ /dev/sda1 + 1GB     + boot  + /boot             +
+-----------+---------+-------+-------------------+
+ /dev/sda2 + 100GB   + root  + /                 +
+-----------+---------+-------+-------------------+
+ /dev/sda3 + 0.9TB   + home  + /home             +
+-----------+---------+-------+-------------------+

## Servidor

O servidor possui dois discos de 2TB que **devem** ser configurados para RAID 1
(infelizmente o servidor atual não possui suporte de hardware para RAID e é
preciso utilizar software).

+-----------+---------+-------+-------------------+
+ Volume    + Tamanho + Label + Ponto de Montagem +
+-----------+---------+-------+-------------------+
+ /dev/sda1 + 1GB     + boot  + /boot             +
+-----------+---------+-------+-------------------+
+ /dev/sda2 + 100GB   + root  + /                 +
+-----------+---------+-------+-------------------+
+ /dev/sda3 + 1.9TB   + home  + /home             +
+-----------+---------+-------+-------------------+
+ /dev/sdb1 + 1GB     + boot  + /boot             +
+-----------+---------+-------+-------------------+
+ /dev/sdb2 + 100GB   + root  + /                 +
+-----------+---------+-------+-------------------+
+ /dev/sdb3 + 1.9TB   + home  + /home             +
+-----------+---------+-------+-------------------+
