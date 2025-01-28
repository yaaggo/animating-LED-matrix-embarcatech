<samp>
<h1 align="center"> Geração de animações em uma matriz de LEDs 5x5 </h1>
<h2 align="center"> Sobre :pencil: </h2>

<p align="justify"> &emsp;&emsp;&emsp;&emsp; Repositório colaborativo com o objetivo de desenvolver habilidades práticas com a placa BitDogLab e seus pinos, como parte de uma tarefa desenvolvida no Capítulo 3 da Unidade 4 da Embarcatech, residência de Sistemas Embarcados. 

<p align="justify"> &emsp;&emsp;&emsp;&emsp; Essa tarefa foi desenvolvida pelo subgrupo 1 do grupo 5 do estado da Bahia (CEPEDI), pelos residentes Bruno Silva, Camila Miranda, Isabela Madureira, Matheus Nascimento e Yago Guirra.

<h3> Descrição da tarefa </h3>

<p align="justify"> &emsp;&emsp;&emsp;&emsp; A tarefa consiste em utilizar o Raspberry Pi Pico W e um teclado matricial 4x4, com o auxílio do simulador de eletrônica Wokwi, para gerar informações visuais em uma matriz de LEDs Coloridos (5x5 WS2812), onde foi realizado e o acionamento dos 25 LEDs, de forma a criar diferentes tipos de animações de curta duração. Nela, foi necessário utilizar os seguintes componentes:

  1. Teclado matricial 4x4;
  2. Microcontrolador Raspberry Pi Pico W;
  3. Matriz de LEDs Coloridos (LED-RGB 5x5 WS2812);
  4. Buzzer Passivo Eletromagnético MLT-8530 SMD 3.6V (componente opcional).

 &emsp;&emsp;&emsp;&emsp; O programa deve:

<p align="justify">  1. As teclas de 0 a 9 do teclado matricial, caso acionadas, o sistema deve executar algum tipo de animação na matriz de LEDs 5x5. Os tipos de desenho, cores (RGB) e luminosidades associados a estas imagens/animações ficam a critério dos membros da equipe de desenvolvimento. No total, serão produzidas 10 animações diferentes.</p>
<p align="justify">  2. Cada animação deve possuir, no mínimo, 5 frames (imagens diferentes) e o FPS (quantidade de quadros por segundo) também deve ser definido pela equipe de desenvolvimento. </p>
<p align="justify">  3. Caso a tecla A seja acionada, todos os LEDs deverão ser desligados. </p>
<p align="justify">  4. Caso a tecla B seja acionada, todos os LEDs deverão ser ligados na cor azul, no nível de intensidade de 100% da luminosidade máxima. </p>
<p align="justify">  5. Caso a tecla C seja acionada, todos os LEDs deverão ser ligados na cor vermelha, no nível de intensidade de 80% da luminosidade máxima. </p>
<p align="justify">  6. Caso a tecla D seja acionada, todos os LEDs deverão ser ligados na cor verde, no nível de intensidade de 50% da luminosidade máxima. </p>
<p align="justify">  7. Caso a tecla # seja acionada, todos os LEDs deverão ser ligados na cor branca, no nível de intensidade de 20% da luminosidade máxima. </p>
<p align="justify">  8. Especificação opcional: gerar sinal sonoro para uma das animações usando o componente buzzer. </p>
<p align="justify">  9. Especificação opcional: Caso a tecla * seja acionada, o Raspberry Pi Pico W deve sair do modo de execução e habilitar o modo de gravação via software (reboot). </p>

&emsp;&emsp;&emsp;&emsp; Foi organizada uma equipe, dividida em 1 Líder (gerencia o repositório) e 4 desenvolvedores (cada um com tarefa específica). 

<p align="justify"> &emsp;&emsp;&emsp;&emsp; O projeto é composto pelos arquivos comuns a um projeto Pico W, além de um READ.ME (descrição do projeto), diagram.json e wokwi.toml (para a simulação no Wokwi) e uma pasta chamada 'inc', que possui 2 arquivos na extensão .c, que são: buzzer.c (que organiza as funções relacionadas ao buzzer) e led.c (que organiza as funções relacionadas ao leds), e 2 arquivos na extensão .h, que são: buzzer.h e led.h (em que ambos possuem o cabeçalho das funções).

<h2></h2>
<h2 align="center"> Vídeo :video_camera: </h2>
<p align="justify"> &emsp;&emsp;&emsp;&emsp; Aqui está o link para o vídeo com uma prática de simulação associada a esta tarefa: </p>
<p align="center">  </p>

<h2></h2>
<h2 align="center"> Como utilizar :computer_mouse: </h2>

<p align="justify"> &emsp;&emsp;&emsp;&emsp; Para utilizar o programa, o usuário deve:

- Clonar o repositório em uma pasta separada para recebê-lo;
- Abrir o projeto no VS Code, importando-o pela extensão Raspberry Pi Pico;
- Abrir o arquivo diagram.json para usar o simulador Wokwi;
- Executar a simulação.
</samp>
