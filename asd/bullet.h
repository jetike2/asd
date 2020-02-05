#include <iostream>
#include <SFML/Graphics>
#include <vector>


class bullet{
	public:
		bullet(){
			if (!bullet_texture.isLoadFromFile("bullet_test.png")){
				//Error..
			}
		}

		void draw(sf::RenderWindow& window){
			bullet.setTexture(bullet_texture);
			window.draw(bullet);

		}


	private:
		sf::sprite bullet;
		sf::texture bullet_texture;

};

