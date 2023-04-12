using namespace std;
#include <iostream>
#include "../include/State.h"
#define INCLUDE_SDL
#include "../include/SDL_include.h"

// O construtor de State inicializa quitRequested e instancia o Sprite, que
// será definido na seção 3. Consulte o Apoio de C++ se tiver dúvidas sobre
// como chamar construtores de membros.
State::State() {
    bool quitRequested = false;
    Sprite* new_sprite = new Sprite();
    bg = *new_sprite;
    Music* new_music = new Music();
    music = *new_music;
}

// O LoadAssets é uma método que cuida de pré-carregar os assets do
// state do jogo para que não haja problemas futuros como, por exemplo, o jogo
// tentar tocar a música antes dela terminar de ser carregada para a memória.
// Deixe para carregar imagens/fontes/músicas às suas variáveis aqui sempre
// que for possível.
void State::LoadAssets() {
    bg.Open("../img/ocean.jpg");
    music.Open("../audio/stageState.ogg");
}

// Update trata da etapa 3 que discutimos em Game::Run. Até o fim do
// semestre, ela tratará da atualização do estado das entidades, testes de
// colisões e a checagem relativa ao encerramento do jogo. Como não temos
// entidades ainda, para esse trabalho, faremos só a última coisa.
// 
// Nesse trabalho, as condições de saída do programa são o usuário clicar
// no “X” da janela ou apertar Alt+F4. Para saber se isso ocorreu usaremos a
// função SDL_QuitRequested(). Se o retorno dela for true, sete a flag
// quitRequested para true.
void State::Update(float dt) {
    if (SDL_QuitRequested() == true) quitRequested = true;
}

// Render, por sua vez, trata da etapa 4 de Game::Run, a renderização do
// estado do jogo. Isso inclui entidades, cenários, HUD, entre outros. Para esse
// trabalho, chame o render do fundo (bg).
void State::Render() {
    bg.Render(0, 0);
    music.Play();
}


// QuitRequested retorna o valor da flag de mesmo nome na função, que
// será usado por Game para interromper o game loop.
bool State::QuitRequested() {
    return quitRequested;
}