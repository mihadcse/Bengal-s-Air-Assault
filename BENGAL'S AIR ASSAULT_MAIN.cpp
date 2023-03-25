#include <iostream>
#include<vector>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>
#include<SFML/Config.hpp>
using namespace std;

vector<pair <double,double> >fire;


int main()
{
	    int clicked = 0;
		//WINDOW CREATE AND BACKGROUND
		sf::RenderWindow window(sf::VideoMode(1000, 600), "Bengal's air assault");
		sf::Texture backgroundtexture1;
		if (!backgroundtexture1.loadFromFile("Image/background.jpg"))
		{
			cout << "background 1 error!!!!\n";
		}
		sf::Sprite backgroundsprite1(backgroundtexture1);

	    //NEW WINDOW CREATE
		sf::Texture newbackground;
		if (!newbackground.loadFromFile("Image/b2.jpg"))
		{
			std::cout << "NEW background error\n";
		}
		sf::Sprite newbackgroundsprite(newbackground);




	//BACKGROUND SOUND
	sf::SoundBuffer backsoundbuffer;
	if (!backsoundbuffer.loadFromFile("AUDIO/epic-heroic-short-version-117402.wav"))
	{
		cout << "backgroundsound error!!!\n";
	}
	sf::Sound backsound;
	backsound.setBuffer(backsoundbuffer);
	backsound.play();



	//OPTIONS CREATE
	sf::RectangleShape rectangle(sf::Vector2f(100, 50));
	rectangle.setPosition(200, 100);
	rectangle.setFillColor(sf::Color::Red);
	rectangle.setOutlineColor(sf::Color::White);

	//NEW OPTION CREATE





	//CHARACTER CREATE
	sf::Texture charactertexture;
	if (!charactertexture.loadFromFile("Image/aircraft1.png"))
	{
		cout << "character error!!\n";
	}
	sf::Sprite charactersprite(charactertexture);
	charactersprite.setPosition(sf::Vector2f(460, 480));

	//FIRE CREATE
	sf::Texture firetexture;
	if (!firetexture.loadFromFile("Image/fire.png"))
	{
		cout << "fire error!!\n";
	}
	sf::Sprite firesprite(firetexture);

	//FIRE SOUND
	sf::SoundBuffer firesoundbuffer;
	if (!firesoundbuffer.loadFromFile("Image/fire1.WAV"))
	{
		cout << "Fire sound error!!!\n";
	}
	sf::Sound firesound;
	firesound.setBuffer(firesoundbuffer);

	//ENEMY CREATE
	sf::Texture enemy1texture;
	if (!enemy1texture.loadFromFile("Image/enemy1.jpg"))
	{
		cout << "enemy1 error!!\n";
	}
	sf::Sprite enemy1sprite(enemy1texture);
	enemy1sprite.setPosition(sf::Vector2f(200, 50));

	sf::Texture enemy2texture;
	if (!enemy2texture.loadFromFile("Image/enemy2.jpg"))
	{
		cout << "enemy2 error!!\n";
	}
	sf::Sprite enemy2sprite(enemy2texture);
	enemy2sprite.setPosition(sf::Vector2f(500, 50));





	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			else if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
			
				sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
				sf::FloatRect rectangleBounds = rectangle.getGlobalBounds();
				
				if (rectangle.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
				{
					std::cout << "you clicked!!\n";
					 clicked = 1;	
				}
			}



			else if (event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
			{
				firesound.play();

				fire.push_back(make_pair(charactersprite.getPosition().x, charactersprite.getPosition().y));
			}
		}

		
		
			//LEFT MOVEMENT
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				if (charactersprite.getPosition().x >= -20)
				{
					charactersprite.move(sf::Vector2f(-1, 0));
				}
			}

			//RIGHT MOVEMENT
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				if (charactersprite.getPosition().x <= 910)
				{
					charactersprite.move(sf::Vector2f(1, 0));
				}
			}

			//UP MOVEMENT
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				if (charactersprite.getPosition().y >= 0)
				{
					charactersprite.move(sf::Vector2f(0, -1));
				}
			}

			//DOWN MOVEMENT
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				if (charactersprite.getPosition().y <= 480)
				{
					charactersprite.move(sf::Vector2f(0, 1));
				}
			}
		



		





			//DRAW AND SHOW IN WINDOW
			window.clear();
			if(clicked==0)
			window.draw(backgroundsprite1);
			if (clicked == 1)
			{
				window.draw(newbackgroundsprite);
		
			}
			window.draw(charactersprite);
			window.draw(rectangle);
				
			
			//window.draw(enemy1sprite);
			//window.draw(enemy2sprite);

				
			if (!fire.empty())
			{
				for (int i = 0; i < fire.size(); i++)
				{

					fire[i].second -= 2;

						if (fire[i].second <= -40)
						{
							continue;
						}
						firesprite.setPosition(sf::Vector2f(fire[i].first + 45, fire[i].second + 5));
						firesprite.move(sf::Vector2f(0, -2));
						window.draw(firesprite);
				}
			}
				

			window.display();
	}

}
	






