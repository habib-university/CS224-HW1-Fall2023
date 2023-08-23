// DO NOT CHANGE THIS FILE
#include "mover.hpp"
#include "odyssey.hpp"

const int xJump=220, yJump=170;

SDL_Rect bg={0,0,800,600};
SDL_Rect bgSrc={0,369,778,586};
SDL_Rect alexSrc={779, 0, 294, 848};
SDL_Rect alexMover={510, 150, 25, 75};

//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

void moveSouth(){ 
    if (alexMover.y+yJump < SCREEN_HEIGHT)alexMover.y+=yJump;    
}
void moveNorth(){
	if (alexMover.y-yJump > 0)alexMover.y-=yJump;
	else alexMover.y = 0;
}
void moveEast(){
	if (alexMover.x+xJump < SCREEN_WIDTH)alexMover.x+=xJump;
}
void moveWest(){
	if (alexMover.x-xJump > 0)alexMover.x-=xJump;
}


void status(SDL_Renderer* gRenderer, SDL_Texture* assets){
	SDL_Rect statusSrc, statusMover;

	//Cat treats
	statusSrc.x=1075;
	statusSrc.y=315;
	statusSrc.w=687;
	statusSrc.h=363;
	statusMover.x=30;
	statusMover.y=300;
	statusMover.w=34;
	statusMover.h=18;
	for(int i=0;i<treatsLeft;i++){
		if(i%4==0){//go to new line
			statusMover.x=30;
			statusMover.y+=18;
		}
		SDL_RenderCopy( gRenderer, assets, &statusSrc, &statusMover );
		statusMover.x+=34;		
	}
	//Collars
	statusSrc.y = 0;
	statusSrc.w = 795;
	statusSrc.h = 314;
	statusMover.x = 30;
	statusMover.y = 500;
	statusMover.w = 60;
	statusMover.h = 20;
	
	for(int i=0;i<nCollarsFound; i++){
		SDL_RenderCopy( gRenderer, assets, &statusSrc, &statusMover );
		statusMover.x+=60;
	}

	if (gameState=="Running"){
		statusSrc.x=0;
		statusSrc.y=0;
		statusSrc.w=579;
		statusSrc.h=54;
		statusMover.x=300;
		statusMover.y=0;
		statusMover.w=300;
		statusMover.h=60;
		SDL_RenderCopy( gRenderer, assets, &statusSrc, &statusMover );
	} 
	else if(gameState=="Won"){
		statusSrc.x=0;
		statusSrc.y=270;
		statusSrc.w=220;
		statusSrc.h=60;
		statusMover.x=300;
		statusMover.y=0;
		statusMover.w=300;
		statusMover.h=60;
		SDL_RenderCopy( gRenderer, assets, &statusSrc, &statusMover );
		cout<<"Game Won";
	}
	else if(gameState=="Lost"){
		statusSrc.x=0;
		statusSrc.y=136;
		statusSrc.w=270;
		statusSrc.h=55;
		statusMover.x=300;
		statusMover.y=0;
		statusMover.w=300;
		statusMover.h=60;
		SDL_RenderCopy( gRenderer, assets, &statusSrc, &statusMover );
	}
}

void moveAlex(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Keycode key){
    if (key == SDLK_UP){
        makeMove("North");
    }
    else if (key == SDLK_DOWN) {
        makeMove("South");
    }
    else if (key == SDLK_RIGHT) {
        makeMove("East");
    }
    else if (key == SDLK_LEFT) {
        makeMove("West");
    }
    else {
        std::cout<<"hello";
    }
    update(gRenderer, assets);
}

void update(SDL_Renderer* gRenderer, SDL_Texture* assets){
	SDL_RenderClear( gRenderer );
	SDL_RenderCopy( gRenderer, assets, &bgSrc, &bg );
	status(gRenderer, assets);
	SDL_RenderCopy( gRenderer, assets, &alexSrc, &alexMover );
	SDL_RenderPresent( gRenderer );	
	SDL_Delay(5);	
}