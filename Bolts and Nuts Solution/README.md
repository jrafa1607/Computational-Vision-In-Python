# Bolts & Nuts
A <b> Bolts & Nuts </b>, fabricante de parafusos, porcas e arruelas possui uma linha de produção semi-automatizada para embalamento dos seus produtos. 
O sistema funciona da seguinte maneira: um funcionário retira os produtos de uma caixa vinda da produção, conta os produtos de acordo com as especificações e os coloca em uma esteira que leva cada conjunto à uma máquina que embala os produtos em sacos plásticos personalizados.

O problema encontrado neste sistema de embalamento é o número de pacotes com quantidades de produtos fora das especificações. Após um levantamento da área de produção, ficou constatado que o problema é causado, na maioria das vezes, por falhas humanas devido à fadiga visual, principalmente nos finais de expediente. O gerente de qualidade acredita que um sistema de inspeção visual automática possa auxiliar no controle deste processo.

A idéia é que, após o funcionário colocar o conjunto de produtos na esteira, uma imagem seja adquirida por uma câmera e analisada pelo sistema de inspeção, o qual pode ainda enviar um comando de decisão para um mecanismo que descarta os conjuntos fora das especificações.

##Objetivos

Desta forma, o objetivo é desenvolver um sistema de inspeção visual para auxiliar o processo de embalamento. Para tanto, apenas uma linha de produtos será considerada nos testes. 
- [x] Nessa linha de produtos, cada conjunto deve possuir 10 parafusos e 10 porcas.
- [x] Dada uma imagem RGB do conjunto de parafusos e porcas, o sistema de visão computacional deve analisar a imagem;
- [x] Feita a análise, o sistema deve emitir uma mensagem informando se o conjunto está aprovado ou reprovado.
- [x] Caso reprovado, o sistema deverá exibir uma mensagem informando quantos parafusos ou porcas estão sobrando ou faltando, conforme exemplos abaixo.

<img src="https://github.com/jrafa1607/Computational-Vision-In-Python/blob/main/Bolts%20and%20Nuts%20Solution/Anexos/img00.jpg">
