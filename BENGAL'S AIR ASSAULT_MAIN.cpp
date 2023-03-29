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

	//NEW GAME BACKGROUND
	sf::Texture newbackground;
	if (!newbackground.loadFromFile("Image/b2.jpg"))
	{
		std::cout << "NEW background error\n";
	}
	sf::Sprite newbackgroundsprite(newbackground);

	//HIGH SCORE BACKGROUND
	sf::Texture scorebackground;
	if (!scorebackground.loadFromFile("Image/LB1.jpg"))
	{
		std::cout << "credits background error\n";
	}
	sf::Sprite scorebackgroundsprite(scorebackground);


	//KILO FLIGHT BACKGROUND

	//CREDITS BACKGROUND
	sf::Texture creditbackground;
	if (!creditbackground.loadFromFile("Image/b4.jpg"))
	{
		std::cout << "credits background error\n";
	}
	sf::Sprite creditbackgroundsprite(creditbackground);




	//FONT
	sf::Font font;
	if (!font.loadFromFile("Fonts/Bootcamp.otf"))
	{
		cout << "Font error!!!\n";
	}

	//BACKGROUND SOUND
	sf::SoundBuffer backsoundbuffer;
	if (!backsoundbuffer.loadFromFile("AUDIO/epic-heroic-short-version-117402.wav"))
	{
		cout << "backgroundsound error!!!\n";
	}
	sf::Sound backsound;
	backsound.setBuffer(backsoundbuffer);
	backsound.play();



	//NEW GAME OPTION CREATE
	sf::RectangleShape rectangle1(sf::Vector2f(150, 50));
	rectangle1.setPosition(445, 100);
	rectangle1.setFillColor(sf::Color::Black);
	rectangle1.setOutlineColor(sf::Color::Cyan);
	rectangle1.setOutlineThickness(3);
	
	//NEW GAME TEXT
	sf::Text option1;
	option1.setFont(font);
	option1.setString("NEW GAME");
	option1.setCharacterSize(40);
	option1.setFillColor(sf::Color::Blue);
	option1.setPosition(454, 100);
	

	//HIGH SCORE OPTION CREATE
	sf::RectangleShape rectangle2(sf::Vector2f(170, 50));
	rectangle2.setPosition(440, 180);
	rectangle2.setFillColor(sf::Color::Black);
	rectangle2.setOutlineColor(sf::Color::Cyan);
	rectangle2.setOutlineThickness(3);

	//HIGH SCORE TEXT
	sf::Text option2;
	option2.setFont(font);
	option2.setString("HIGH SCORE");
	option2.setCharacterSize(40);
	option2.setFillColor(sf::Color::Blue);
	option2.setPosition(452, 180);

	//CREDITS OPTION CREATE
	sf::RectangleShape rectangle3(sf::Vector2f(120, 50));
	rectangle3.setPosition(460, 260);
	rectangle3.setFillColor(sf::Color::Black);
	rectangle3.setOutlineColor(sf::Color::Cyan);
	rectangle3.setOutlineThickness(3);

	//CREDITS SCORE TEXT
	sf::Text option3;
	option3.setFont(font);
	option3.setString("CREDITS");
	option3.setCharacterSize(40);
	option3.setFillColor(sf::Color::Blue);
	option3.setPosition(470, 260);

	//KILO FLIGHT OPTION CREATE
	sf::RectangleShape rectangle4(sf::Vector2f(170, 50));
	rectangle4.setPosition(440, 340);
	rectangle4.setFillColor(sf::Color::Black);
	rectangle4.setOutlineColor(sf::Color::Cyan);
	rectangle4.setOutlineThickness(3);

	//KILO FLIGHT TEXT
	sf::Text option4;
	option4.setFont(font);
	option4.setString("KILO FLIGHT");
	option4.setCharacterSize(40);
	option4.setFillColor(sf::Color::Blue);
	option4.setPosition(452, 340);

	//EXIT OPTION CREATE
	sf::RectangleShape rectangle5(sf::Vector2f(85, 50));
	rectangle5.setPosition(470, 420);
	rectangle5.setFillColor(sf::Color::Black);
	rectangle5.setOutlineColor(sf::Color::Cyan);
	rectangle5.setOutlineThickness(3);

	//EXIT OPTION TEXT
	sf::Text option5;
	option5.setFont(font);
	option5.setString("EXIT");
	option5.setCharacterSize(40);
	option5.setFillColor(sf::Color::Blue);
	option5.setPosition(485, 420);


	//BACK OPTION CREATE
	sf::RectangleShape rectangle6(sf::Vector2f(40, 40));
	rectangle6.setPosition(50, 50);
	rectangle6.setFillColor(sf::Color::Red);
	rectangle6.setOutlineColor(sf::Color::Cyan);
	rectangle6.setOutlineThickness(3);

	//MUSIC ON/OFF OPTION



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
	if (!firesoundbuffer.loadFromFile("AUDIO/gun1.wav"))
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


	//MOUSE CURSOR APPEARANCE
	sf::Image cursorImage;
	cursorImage.loadFromFile("Image/cursor1.png");

	// Create a cursor object from the image file
	sf::Cursor cursor;
	cursor.loadFromPixels(cursorImage.getPixelsPtr(), cursorImage.getSize(), sf::Vector2u(0, 0));

	// Set the cursor for the window
	window.setMouseCursor(cursor);




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
				sf::FloatRect rectangleBounds = rectangle1.getGlobalBounds();
				
				//NEW GAME CLICKED
				if (clicked == 0 && rectangle1.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
				{
					std::cout << "new game clicked!!\n";
					 clicked = 1;	
				}
				//HIGH SCORE CLICKED
				else if (clicked==0 && rectangle2.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
				{
					std::cout << "high score clicked!!\n";
					clicked = 2;
				}
				//CREDITS CLICKED
				else if (clicked == 0 && rectangle3.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
				{
					std::cout << "credits clicked!!\n";
					clicked = 3;
				}

				//BACK CLICKED
				else if ((clicked == 2 || clicked==3 || clicked==4) && rectangle6.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
				{
					std::cout << "back clicked!!\n";
					clicked = 0;
				}
				//KILO FLIGHT CLICKED
				else if (clicked == 0 && rectangle4.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
				{
					std::cout << "kilo flight clicked!!\n";
					clicked = 4;
				}
				//EXIT CLICKED
				else if (clicked == 0 && rectangle5.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
				{
					std::cout << "exit clicked!!\n";
					clicked = 5;
				}
			}

			if (clicked == 1)
			{
				 if (event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
				 {
					 firesound.play();

					 fire.push_back(make_pair(charactersprite.getPosition().x, charactersprite.getPosition().y));
			     }
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
			if (clicked == 0)
			{
				window.draw(backgroundsprite1);
				window.draw(rectangle1);
				window.draw(option1);
				window.draw(rectangle2);
				window.draw(option2);
				window.draw(rectangle3);
				window.draw(option3);
				window.draw(rectangle4);
				window.draw(option4);
				window.draw(rectangle5);
				window.draw(option5);
			}

			else if (clicked == 1)
			{
				window.draw(newbackgroundsprite);
				window.draw(charactersprite);
			}

			else if (clicked == 2)
			{
				window.draw(scorebackgroundsprite);
				window.draw(rectangle6);
			}

			else if (clicked == 3)
			{
				window.draw(creditbackgroundsprite);
				window.draw(rectangle6);
			}

			else if (clicked == 4)
			{
				window.draw(rectangle6);
			}

			else if (clicked == 5)
			{
				window.close();
			}
				
			
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
	






