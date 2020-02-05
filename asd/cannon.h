#ifndef CANNON_H
#define CANNON_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "enemy.h"

class Cannon{
	int p = 0;
	public:

		sf::CircleShape range;

		Cannon(){
			if(!cannon_texture.loadFromFile("cannon_test.png")){
				//Error..
			}
		range.setRadius(100.f);
		}	

		void draw(sf::RenderWindow& window){
			window.draw(range);
			window.draw(cannon);
			cannon.setTexture(cannon_texture);
		}
		
		void setPosition(sf::Vector2i pos){
			cannon.setPosition(pos.x - 10, pos.y - 10);
			range.setPosition(pos.x - 100, pos.y - 100);
		}

		void shoot(Enemy enemy ,sf::CircleShape r){
			sf::Vector2f e_pos = enemy.enemy.getPosition();

			if(r.getGlobalBounds().intersects(enemy.enemy.getGlobalBounds())){

				sf::Vector2f pos = r.getPosition();
				std::cout << pos.x << pos.y << std::endl;
			}
		}

		

	private:
		sf::Sprite cannon;
		sf::Texture cannon_texture;


};


#endif /*CANNON_H*/
