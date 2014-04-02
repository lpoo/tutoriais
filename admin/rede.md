# Rede do LPOO

O LPOO utiliza IP fixo de modo que para adicionar uma máquina novo você
precisará configurar as seguintes informações no seu equipamento:

- Broadcast: 143.106.118.159
- Net mask: 255.255.255.224
- DNS primário: 143.106.22.2
- DNS secundário: 143.106.7.7

## IPs

Os IPs do LPOO são da forma 143.106.118.XXX onde XXX são números no intervalo
fechado 132-152.

O primeiro número de IP, 143.106.118.132, é reservado ao servidor.

## Mapa de IPs Primários

~~~
|Janela |       |Janela |       |Janela |
+-------+-------+-------+-------+-------+
+  133  +  134  +  135  +  136  +  137  +
+-------+-------+-------+-------+-------+
+  138  +  139  +  140  +  141  +  142  +
+-------+-------+-------+-------+-------+
                                 Porta
~~~

## Mapa de IPs Secundários

~~~
|Janela |       |Janela |       |Janela |
+-------+-------+-------+-------+-------+
+  143  +  144  +  145  +  146  +  147  +
+-------+-------+-------+-------+-------+
+  148  +  149  +  150  +  151  +  152  +
+-------+-------+-------+-------+-------+
                                 Porta
~~~
