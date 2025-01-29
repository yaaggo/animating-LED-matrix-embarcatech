<samp>
<h1 align="center"> Geração de animações em uma matriz de LEDs 5x5 </h1>
<h2 align="center"> Sobre :pencil: </h2>

<p align="justify"> &emsp;&emsp;&emsp;&emsp; Repositório colaborativo com o objetivo de desenvolver habilidades práticas com a placa BitDogLab e seus componentes, como parte de uma tarefa desenvolvida no Capítulo 3 da Unidade 4 da Embarcatech, residência de Sistemas Embarcados. 

<p align="justify"> &emsp;&emsp;&emsp;&emsp; Essa tarefa foi desenvolvida pelo subgrupo 1 do grupo 5 do estado da Bahia (CEPEDI), pelos residentes Bruno Silva, Camila Miranda, Isabela Madureira e Yago Guirra.

<h3> Descrição da tarefa </h3>

<p align="justify"> &emsp;&emsp;&emsp;&emsp; A tarefa consiste em utilizar o Raspberry Pi Pico W e um teclado matricial 4x4, com o auxílio do simulador de eletrônica Wokwi, para gerar informações visuais em uma matriz de LEDs Coloridos (5x5 WS2812), onde foi realizado e o acionamento dos 25 LEDs, de forma a criar diferentes tipos de animações de curta duração. Nela, foi necessário utilizar os seguintes componentes:

  1. Teclado matricial 4x4;
  2. Microcontrolador Raspberry Pi Pico W;
  3. Matriz de LEDs Coloridos (LED-RGB 5x5 WS2812);
  4. Buzzer Passivo Eletromagnético MLT-8530 SMD 3.6V (componente opcional).

 &emsp;&emsp;&emsp;&emsp; O programa deve:

<p align="justify">  1. Teclas de 0 a 9: o sistema deve executar algum tipo de animação na matriz de LEDs 5x5, onde serão produzidas 10 animações diferentes. Aqui, o grupo optou por utilizar a tecla 0 para emitir um som com o buzzer que intercala com uma animação; </p>
<p align="justify">  2. Cada animação deve possuir, no mínimo, 5 frames (imagens diferentes) e o FPS (quantidade de quadros por segundo) também deve ser definido pela equipe de desenvolvimento; </p>
<p align="justify">  3. Tecla A: todos os LEDs deverão ser desligados; </p>
<p align="justify">  4. Tecla B: todos os LEDs deverão ser ligados na cor azul, no nível de intensidade de 100% da luminosidade máxima; </p>
<p align="justify">  5. Tecla C: todos os LEDs deverão ser ligados na cor vermelha, no nível de intensidade de 80% da luminosidade máxima; </p>
<p align="justify">  6. Tecla D: todos os LEDs deverão ser ligados na cor verde, no nível de intensidade de 50% da luminosidade máxima; </p>
<p align="justify">  7. Tecla #: todos os LEDs deverão ser ligados na cor branca, no nível de intensidade de 20% da luminosidade máxima; </p>
<p align="justify">  8. Especificação opcional: gerar sinal sonoro para uma das animações usando o componente buzzer; </p>
<p align="justify">  9. Especificação opcional: Caso a tecla * seja acionada, o Raspberry Pi Pico W deve sair do modo de execução e habilitar o modo de gravação via software (reboot). </p>

&emsp;&emsp;&emsp;&emsp; Foi organizada uma equipe, dividida em 1 Líder (gerencia o repositório) e 3 desenvolvedores (cada um com tarefa específica). 

<p align="justify"> &emsp;&emsp;&emsp;&emsp; O projeto é composto pelos arquivos comuns a um projeto Pico W, além de uma pasta chamada 'wokwi', com os arquivos diagram.json e wokwi.toml (para a simulação no Wokwi), uma pasta chamada 'include', que possui 3 arquivos na extensão .c, que são: buzzer.c (que organiza as funções relacionadas ao buzzer), keypad.c (que organiza as funções relacionadas ao teclado matricial) e ledmatrix.c (que organiza as funções relacionadas à matriz de LEDs), 3 arquivos na extensão .h, que são: buzzer.h, keypad.h e ledmatrix.h (em que ambos possuem o cabeçalho das funções) e um arquivo ws2818b.pio, uma pasta chamada 'src', que possui animation.c (que organiza as funções de animação), animation.h (com os cabeçalhos das funções) e main.c (que gerencia todo o projeto), e o arquivo READ.ME (descrição do projeto).

<h2></h2>
<h2 align="center"> Vídeo :video_camera: </h2>
<p align="justify"> &emsp;&emsp;&emsp;&emsp; Aqui está o link para o vídeo com uma prática de simulação associada a esta tarefa: </p>
<p align="center"> https://www.youtube.com/watch?v=MXV9bTbXYNc </p>

<h2></h2>
<h2 align="center"> Como utilizar :computer_mouse: </h2>

<p align="justify"> &emsp;&emsp;&emsp;&emsp; Para utilizar o programa, o usuário deve:

- Clonar o repositório em uma pasta separada para recebê-lo;
- Abrir o projeto no VS Code, importando-o pela extensão Raspberry Pi Pico;
- Abrir o arquivo diagram.json para usar o simulador Wokwi;
- Executar a simulação.
- Caso queira usar na placa BitDogLab, comentar a definição do KEYPAD.
</samp>
