#ifndef FASELEVEL2_HPP
#define FASELEVEL2_HPP

//#include "ASCII_Engine"

#include "ASCII_Engine/Fase.hpp"
#include <string>
#include <list>

#include "Fogo.hpp"
#include "Morador.hpp"
#include "Bombeiro.hpp"


class FaseLevel2 : public Fase
{
public:
	FaseLevel2(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
	FaseLevel2(std::string name, const SpriteAnimado &bkg) : Fase(name,bkg) {}
	virtual ~FaseLevel2() {}
	
	
	virtual void init();
	virtual unsigned run(SpriteBuffer &screen);
	
private:

	
	Fogo *fogos[3];
	Bombeiro *bombeiro;
	Morador *moradores[10];
    
	ObjetoDeJogo *extintor;
    ObjetoDeJogo *grade;
    

	ObjetoDeJogo *sim;
	TextSprite *life;

	
};

#endif // FASELEVEL2_HPP
