#ifndef MORADOR_HPP
#define MORADOR_HPP

#include "Personagem.hpp"

class Morador : public Personagem
{
public:
    // Construtor inicializando a vida do morador
    Morador(const ObjetoDeJogo &obj, int vida = 700) : 
        Personagem(obj, vida) {}

    virtual ~Morador() {}
};

#endif // MORADOR_HPP

