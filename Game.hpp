#ifndef GAME_HPP
#define GAME_HPP

#include "FaseLevel1.hpp"
#include "FaseStart.hpp"
#include "FaseLevel2.hpp"
#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteAnimado.hpp"

class Game
{
public:
	Game(){}
	~Game(){}
	
	static void run()
	{
		SpriteBuffer bufferfase1e2(294,75);
		SpriteBuffer bufferstart(201,35);

		
		FaseStart start("FaseStart",Sprite("rsc/fasestart.img"));
		FaseLevel1 fase1("Fase1",Sprite("rsc/fase1.img"));
		FaseLevel2 fase2("Fase2",Sprite("rsc/fase2.img"));
		FaseStart final("FaseFinal",Sprite("rsc/fasefinal.img"));
		
		start.init();
		start.run(bufferstart);


		bufferstart.clear();
		fase1.init();
		
		int ret1 = fase1.run(bufferfase1e2);
		if ( ret1 != Fase::GAME_OVER && ret1 != Fase::END_GAME){
		
			bufferfase1e2.clear();
			fase2.init();
			int ret2 = fase2.run(bufferfase1e2);
			if ( ret2 != Fase::GAME_OVER && ret2 != Fase::END_GAME)
			{
				bufferfase1e2.clear();
				final.init();
				final.run(bufferstart);
			}

		}
		else
			std::cout << "GAME OVER" << std::endl;
		
		std::cout << "Saindo..." << std::endl;
	}

};

#endif // GAME_HPP
