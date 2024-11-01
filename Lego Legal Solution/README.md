# Lego Legal
A empresa <b> Lego Legal</b>, fabricante de peças para lego, possui uma linha de produção semiautomatizada para embalamento dos seus produtos que funciona da seguinte maneira: 
- Após o processo de fabricação, as peças são colocadas em uma esteira automatizada
- Pouco mais adiante, no setor de embalagem, um funcionário as retira e as coloca em caixas de acordo com suas especificações, descritas na Tabela 1 a seguir.

<img src="https://github.com/jrafa1607/Computational-Vision-In-Python/blob/main/Lego%20Legal%20Solution/-%20Anexos/table1.jpeg">

Um problema recorrente no processo de embalagem é o número de peças colocadas erroneamente nas caixas. Após um levantamento da gerência de produção ficou constatado que tal problema é causado, na maioria das vezes, por falha humana devido à fadiga visual, principalmente nos finais de expediente. O gerente de produção acredita que um sistema de inspeção visual automática pode auxiliar no controle deste processo.

A idéia é a seguinte: Após um funcionário da área de produção colocar um conjunto de produtos na esteira, uma imagem deste conjunto é adquirida por uma câmera e processada. 
O resultado do processamento (um conjunto de dados) é então enviado para um mecanismo (braço robótico) de separação automática das peças. 
É importante ressaltar que o funcionário que antes separava as peças manualmente deverá ser treinado para operar o novo sistema.

## Objetivos

Sua missão é desenvolver um sistema de inspeção visual para atender ao objetivo proposto. Para tanto, dada uma imagem colorida (RGB) do conjunto de peças, o sistema computacional deve gerar uma saída informando, para cada peça, a localização na imagem, o tipo e a caixa que ela dever ser colocada, conforme exemplo abaixo:

<img src="https://github.com/jrafa1607/Computational-Vision-In-Python/blob/main/Lego%20Legal%20Solution/-%20Anexos/res01.jpeg">
