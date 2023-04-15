#include <iostream>
#include<vector>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>
#include<SFML/Config.hpp>
using namespace std;

vector<pair <double, double> >fire;


int main()
{
	int direction = 0;
	int clicked = -1, quit_anim=0;
	//WINDOW CREATE AND BACKGROUND
	sf::RenderWindow window(sf::VideoMode(1150, 680), "Bengal's air assault");// this window ratio is fixed. It will show the window with a height of 1150 and width of 680
	sf::Texture backgroundtexture1;
	if (!backgroundtexture1.loadFromFile("Image/sample.jpg"))
	{
		cout << "background 1 error!!!!\n";
	}
	sf::Sprite backgroundsprite1(backgroundtexture1);

	//VIDEO MAKING
	// Create an array of image file names
	/*std::string imageFileNames[] = { "Video/2_001.jpg", "Video/2_002.jpg", "Video/2_003.jpg", "Video/2_004.jpg", "Video/2_005.jpg", "Video/2_006.jpg", "Video/2_007.jpg", "Video/2_008.jpg", "Video/2_009.jpg", "Video/2_010.jpg", "Video/2_011.jpg", "Video/2_012.jpg", "Video/2_013.jpg", "Video/2_014.jpg", "Video/2_015.jpg", "Video/2_016.jpg", "Video/2_017.jpg", "Video/2_018.jpg", "Video/2_019.jpg", "Video/2_020.jpg", "Video/2_021.jpg", "Video/2_022.jpg", "Video/2_023.jpg", 
		"Video/2_024.jpg", "Video/2_025.jpg", "Video/2_026.jpg", "Video/2_027.jpg", "Video/2_028.jpg", "Video/2_029.jpg", "Video/2_030.jpg", "Video/2_031.jpg", "Video/2_032.jpg", "Video/2_033.jpg", "Video/2_034.jpg", "Video/2_035.jpg", "Video/2_036.jpg", "Video/2_037.jpg", "Video/2_038.jpg", "Video/2_039.jpg", "Video/2_040.jpg", "Video/2_041.jpg", "Video/2_055.jpg", "Video/2_056.jpg", "Video/2_057.jpg", "Video/2_058.jpg", "Video/2_059.jpg", "Video/2_060.jpg", "Video/2_061.jpg", 
		"Video/2_062.jpg", "Video/2_063.jpg", "Video/2_064.jpg", "Video/2_065.jpg", "Video/2_066.jpg", "Video/2_067.jpg", "Video/2_068.jpg", "Video/2_069.jpg", "Video/2_070.jpg", "Video/2_071.jpg", "Video/2_072.jpg", "Video/2_073.jpg", "Video/2_074.jpg", "Video/2_075.jpg", "Video/2_076.jpg", "Video/2_077.jpg", "Video/2_078.jpg", "Video/2_079.jpg", "Video/2_080.jpg", "Video/2_081.jpg", "Video/2_082.jpg", "Video/2_083.jpg", "Video/2_084.jpg", "Video/2_085.jpg", "Video/2_086.jpg", 
		"Video/2_087.jpg", "Video/2_088.jpg", "Video/2_089.jpg", "Video/2_090.jpg", "Video/2_091.jpg", "Video/2_092.jpg", "Video/2_093.jpg","Video/2_094.jpg", "Video/2_095.jpg", "Video/2_096.jpg", "Video/2_097.jpg", "Video/2_098.jpg", "Video/2_099.jpg", "Video/2_100.jpg", "Video/2_101.jpg", "Video/2_102.jpg", "Video/2_103.jpg", "Video/2_104.jpg", "Video/2_105.jpg", "Video/2_106.jpg", "Video/2_107.jpg", "Video/2_108.jpg", "Video/2_109.jpg", "Video/2_110.jpg", "Video/2_111.jpg", 
		"Video/2_112.jpg", "Video/2_113.jpg", "Video/2_114.jpg", "Video/2_115.jpg", "Video/2_116.jpg", "Video/2_117.jpg", "Video/2_118.jpg", "Video/2_119.jpg", "Video/2_120.jpg", "Video/2_121.jpg", "Video/2_122.jpg", "Video/2_123.jpg", "Video/2_124.jpg", "Video/2_125.jpg", "Video/2_126.jpg", "Video/2_127.jpg", "Video/2_128.jpg", "Video/2_129.jpg", "Video/2_130.jpg", "Video/2_131.jpg", "Video/2_132.jpg", "Video/2_133.jpg", "Video/2_134.jpg","Video/2_135.jpg", "Video/2_136.jpg", 
		"Video/2_137.jpg", "Video/2_138.jpg", "Video/2_139.jpg", "Video/2_140.jpg", "Video/2_141.jpg", "Video/2_142.jpg", "Video/2_143.jpg", "Video/2_144.jpg", "Video/2_145.jpg", "Video/2_146.jpg", "Video/2_147.jpg", "Video/2_148.jpg", "Video/2_149.jpg", "Video/2_150.jpg", "Video/2_151.jpg", "Video/2_152.jpg", "Video/2_153.jpg", "Video/2_154.jpg", "Video/2_155.jpg", "Video/2_156.jpg", "Video/2_157.jpg", "Video/2_158.jpg", "Video/2_159.jpg", "Video/2_160.jpg", "Video/2_161.jpg",
		"Video/2_162.jpg", "Video/2_163.jpg", "Video/2_164.jpg", "Video/2_265.jpg", "Video/2_266.jpg", "Video/2_267.jpg", "Video/2_268.jpg", "Video/2_269.jpg", "Video/2_270.jpg", "Video/2_271.jpg", "Video/2_272.jpg", "Video/2_273.jpg", "Video/2_274.jpg", "Video/2_275.jpg", "Video/2_276.jpg", "Video/2_277.jpg", "Video/2_278.jpg", "Video/2_279.jpg", "Video/2_280.jpg", "Video/2_281.jpg", "Video/2_282.jpg", "Video/2_283.jpg", "Video/2_284.jpg", "Video/2_285.jpg", "Video/2_286.jpg",
		"Video/2_287.jpg", "Video/2_288.jpg", "Video/2_289.jpg", "Video/2_290.jpg", "Video/2_291.jpg", "Video/2_292.jpg", "Video/2_293.jpg", "Video/2_294.jpg", "Video/2_295.jpg", "Video/2_296.jpg", "Video/2_297.jpg", "Video/2_298.jpg", "Video/2_299.jpg" };
	*/
	//ANIMATION MAKING 2nd option
	std::string imageFileNames[] = { "Animation/3_000.jpg", "Animation/3_001.jpg", "Animation/3_002.jpg", "Animation/3_003.jpg", "Animation/3_004.jpg", "Animation/3_005.jpg", "Animation/3_006.jpg", "Animation/3_007.jpg", "Animation/3_008.jpg", "Animation/3_009.jpg", "Animation/3_010.jpg", "Animation/3_011.jpg", "Animation/3_012.jpg", "Animation/3_013.jpg", "Animation/3_014.jpg", "Animation/3_015.jpg", "Animation/3_016.jpg", "Animation/3_017.jpg", "Animation/3_018.jpg", "Animation/3_019.jpg",
		"Animation/3_020.jpg", "Animation/3_021.jpg", "Animation/3_022.jpg", "Animation/3_023.jpg", "Animation/3_024.jpg", "Animation/3_025.jpg", "Animation/3_026.jpg", "Animation/3_027.jpg", "Animation/3_028.jpg", "Animation/3_029.jpg", "Animation/3_030.jpg", "Animation/3_031.jpg","Animation/3_032.jpg", "Animation/3_033.jpg", "Animation/3_034.jpg", "Animation/3_035.jpg", "Animation/3_036.jpg", "Animation/3_037.jpg", "Animation/3_038.jpg", "Animation/3_039.jpg", "Animation/3_040.jpg", "Animation/3_041.jpg",
		"Animation/3_042.jpg", "Animation/3_043.jpg", "Animation/3_044.jpg", "Animation/3_045.jpg", "Animation/3_046.jpg", "Animation/3_047.jpg", "Animation/3_048.jpg", "Animation/3_049.jpg", "Animation/3_050.jpg", "Animation/3_051.jpg", "Animation/3_052.jpg", "Animation/3_053.jpg", "Animation/3_054.jpg", "Animation/3_055.jpg", "Animation/3_056.jpg", "Animation/3_057.jpg", "Animation/3_058.jpg", "Animation/3_059.jpg", "Animation/3_060.jpg", "Animation/3_061.jpg", "Animation/3_062.jpg", "Animation/3_063.jpg",
		"Animation/3_064.jpg", "Animation/3_065.jpg", "Animation/3_066.jpg", "Animation/3_067.jpg", "Animation/3_068.jpg", "Animation/3_069.jpg", "Animation/3_070.jpg", "Animation/3_071.jpg", "Animation/3_072.jpg", "Animation/3_073.jpg", "Animation/3_074.jpg", "Animation/3_075.jpg", "Animation/3_076.jpg", "Animation/3_077.jpg", "Animation/3_078.jpg", "Animation/3_079.jpg", "Animation/3_080.jpg", "Animation/3_081.jpg", "Animation/3_082.jpg", "Animation/3_083.jpg", "Animation/3_084.jpg", "Animation/3_085.jpg",
		"Animation/3_086.jpg", "Animation/3_087.jpg", "Animation/3_088.jpg", "Animation/3_089.jpg", "Animation/3_090.jpg", "Animation/3_091.jpg", "Animation/3_092.jpg", "Animation/3_093.jpg", "Animation/3_094.jpg", "Animation/3_095.jpg", "Animation/3_096.jpg", "Animation/3_097.jpg", "Animation/3_098.jpg", "Animation/3_099.jpg", "Animation/3_100.jpg", "Animation/3_101.jpg", "Animation/3_102.jpg", "Animation/3_103.jpg", "Animation/3_104.jpg", "Animation/3_105.jpg", "Animation/3_106.jpg", "Animation/3_107.jpg",
		"Animation/3_108.jpg", "Animation/3_109.jpg", "Animation/3_110.jpg", "Animation/3_111.jpg", "Animation/3_112.jpg", "Animation/3_113.jpg", "Animation/3_114.jpg", "Animation/3_115.jpg", "Animation/3_116.jpg", "Animation/3_117.jpg", "Animation/3_118.jpg", "Animation/3_119.jpg" };




	//if (clicked == -1)
	//{
	//	for (int i = 0; i < 1; i++) {

	//		sf::Texture Videotexture;
	//		if (!Videotexture.loadFromFile(imageFileNames[i])) {
	//			cout << "Video images error!!!!\n";
	//		}
	//		sf::Sprite Videosprite(Videotexture);
	//		//sf::sleep(sf::seconds(0.05));
	//		window.draw(Videosprite);
	//		cout << i << endl;
	//		sf::sleep(sf::seconds(0.5));
	//	}
	//}






	//NEW GAME BACKGROUND
	sf::Texture newbackground;
	if (!newbackground.loadFromFile("Image/mainbg.jpg"))
	{
		std::cout << "NEW background error\n";
	}
	sf::Sprite newbackgroundsprite(newbackground);

	//HIGH SCORE BACKGROUND
	sf::Texture scorebackground;
	if (!scorebackground.loadFromFile("Image/hoisted_flagm.jpg"))
	{
		std::cout << "credits background error\n";
	}
	sf::Sprite scorebackgroundsprite(scorebackground);


	//KILO FLIGHT BACKGROUND
	sf::Texture kiloflightbackground;
	if (!kiloflightbackground.loadFromFile("Image/b51.jpg"))
	{
		std::cout << "kiloflight background error\n";
	}
	sf::Sprite kiloflightbackgroundsprite(kiloflightbackground);


	//CREDITS BACKGROUND
	sf::Texture creditbackground;
	if (!creditbackground.loadFromFile("Image/credit1.jpg"))
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

	//ANIMATION TEXT
	sf::Text animation;
	animation.setFont(font);
	animation.setString("BENGALS AIR ASSAULT");
	animation.setCharacterSize(60);
	animation.setFillColor(sf::Color::Black);
	animation.setPosition(493, 300);


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
	sf::RectangleShape rectangle1(sf::Vector2f(195, 50));
	rectangle1.setPosition(468, 150);
	rectangle1.setFillColor(sf::Color::Black);
	rectangle1.setOutlineColor(sf::Color::White);
	rectangle1.setOutlineThickness(4);

	//NEW GAME TEXT
	sf::Text option1;
	option1.setFont(font);
	option1.setString("NEW GAME");
	option1.setCharacterSize(43);
	option1.setFillColor(sf::Color::White);
	option1.setPosition(493, 150);


	//HIGH SCORE OPTION CREATE
	sf::RectangleShape rectangle2(sf::Vector2f(215, 50));
	rectangle2.setPosition(460, 250);
	rectangle2.setFillColor(sf::Color::Black);
	rectangle2.setOutlineColor(sf::Color::White);
	rectangle2.setOutlineThickness(4);

	//HIGH SCORE TEXT
	sf::Text option2;
	option2.setFont(font);
	option2.setString("HIGH SCORE");
	option2.setCharacterSize(43);
	option2.setFillColor(sf::Color::White);
	option2.setPosition(490, 250);

	//CREDITS OPTION CREATE
	sf::RectangleShape rectangle3(sf::Vector2f(154, 50));
	rectangle3.setPosition(480, 350);
	rectangle3.setFillColor(sf::Color::Black);
	rectangle3.setOutlineColor(sf::Color::White);
	rectangle3.setOutlineThickness(4);

	//CREDITS SCORE TEXT
	sf::Text option3;
	option3.setFont(font);
	option3.setString("CREDITS");
	option3.setCharacterSize(43);
	option3.setFillColor(sf::Color::White);
	option3.setPosition(500, 350);

	//KILO FLIGHT OPTION CREATE
	sf::RectangleShape rectangle4(sf::Vector2f(215, 50));
	rectangle4.setPosition(460, 450);
	rectangle4.setFillColor(sf::Color::Black);
	rectangle4.setOutlineColor(sf::Color::White);
	rectangle4.setOutlineThickness(4);

	//KILO FLIGHT TEXT
	sf::Text option4;
	option4.setFont(font);
	option4.setString("KILO FLIGHT");
	option4.setCharacterSize(43);
	option4.setFillColor(sf::Color::White);
	option4.setPosition(490, 450);

	//EXIT OPTION CREATE
	sf::RectangleShape rectangle5(sf::Vector2f(85, 50));
	rectangle5.setPosition(510, 550);
	rectangle5.setFillColor(sf::Color::Black);
	rectangle5.setOutlineColor(sf::Color::White);
	rectangle5.setOutlineThickness(4);

	//EXIT OPTION TEXT
	sf::Text option5;
	option5.setFont(font);
	option5.setString("EXIT");
	option5.setCharacterSize(43);
	option5.setFillColor(sf::Color::White);
	option5.setPosition(520, 550);


	//BACK OPTION CREATE
	sf::RectangleShape rectangle6(sf::Vector2f(30, 30));
	rectangle6.setPosition(5, 5);
	rectangle6.setFillColor(sf::Color::Transparent);
	rectangle6.setOutlineColor(sf::Color::Black);
	rectangle6.setOutlineThickness(2);



	//MUSIC ON/OFF OPTION
	


	//CHARACTER CREATE
	sf::Texture charactertexture;
	if (!charactertexture.loadFromFile("Image/sprite_jet.png"))
	{
		cout << "character error!!\n";
	}
	sf::Sprite charactersprite(charactertexture);
	charactersprite.setPosition(sf::Vector2f(500, 570));

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
	if (!enemy1texture.loadFromFile("Image/enemy1.png"))
	{
		cout << "enemy1 error!!\n";
	}
	sf::Sprite enemy1sprite(enemy1texture);
	enemy1sprite.setPosition(sf::Vector2f(200, 50));

	sf::Texture enemy2texture;
	if (!enemy2texture.loadFromFile("Image/enemy2.png"))
	{
		cout << "enemy2 error!!\n";
	}
	sf::Sprite enemy2sprite(enemy2texture);
	enemy2sprite.setPosition(sf::Vector2f(0, 15.f));

	sf::Texture enemy3texture;
	if (!enemy3texture.loadFromFile("Image/enemy2(destroyed).png"))
	{
		cout << "enemy3 error!!\n";
	}
	sf::Sprite enemy3sprite(enemy3texture);
	enemy3sprite.setPosition(sf::Vector2f(50, 50));

	sf::Texture fueltexture;
	if (!fueltexture.loadFromFile("Image/fuel.png"))
	{
		cout << "fuel error!!\n";
	}
	sf::Sprite fuelsprite(fueltexture);
	fuelsprite.setPosition(sf::Vector2f(400, 0));

	sf::Texture oiltexture;
	if (!oiltexture.loadFromFile("Image/oil.png"))
	{
		cout << "oil error!!\n";
	}
	sf::Sprite oilsprite(oiltexture);
	oilsprite.setPosition(sf::Vector2f(280, 0));


	//Health-bar creation
	sf::RectangleShape healthBar(sf::Vector2f(100, 10));
	healthBar.setFillColor(sf::Color::Black);
	healthBar.setPosition(enemy2sprite.getPosition().x, enemy2sprite.getPosition().y - 20);

	//healthBar.setSize(sf::Vector2f(enemy2sprite.health, 10));


	//MOUSE CURSOR APPEARANCE
	sf::Image cursorImage;
	cursorImage.loadFromFile("Image/cursor1.png");

	// Create a cursor object from the image file
	sf::Cursor cursor;
	cursor.loadFromPixels(cursorImage.getPixelsPtr(), cursorImage.getSize(), sf::Vector2u(0, 0));

	// Set the cursor for the window
	window.setMouseCursor(cursor);


	class Enemy {
	public:
		int health;

		Enemy() {
			health = 100; // Set initial health to 100
		}

		void takeDamage(int damage) {
			health -= damage;
			if (health < 0) {
				health = 0;
			}
		}
	};

	//........................................................................
	class EnemyAircraft : public sf::Sprite {
	public:
		EnemyAircraft(sf::Texture& texture, float x, float y, float vx, float vy)
			: sf::Sprite(texture), m_position(x, y), m_velocity(vx, vy)
		{
			// Set the sprite's initial position and scale
			setPosition(10, 50);
			setScale(0.5f, 0.5f);
		}

		void update(float dt)
		{
			// Update the position based on the velocity and delta time
			m_position += m_velocity * dt;
			setPosition(m_position);
		}

		// Accessors for the position and velocity
		sf::Vector2f getPosition() const { return m_position; }
		sf::Vector2f getVelocity() const { return m_velocity; }

	private:
		sf::Vector2f m_position;
		sf::Vector2f m_velocity;
	};






	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			//color changing of the options. If the mouse pointer is over any option it will change it's color
			if (event.type == sf::Event::MouseMoved)
			{
				//NEW GAME OPTION COLOR CHANGE
				if (rectangle1.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
				{
					rectangle1.setOutlineColor(sf::Color(0, 128, 255)); // Lighter shade
					option1.setFillColor(sf::Color(30, 144, 255));
				}
				else
				{
					rectangle1.setOutlineColor(sf::Color::White); // Default color
					option1.setFillColor(sf::Color::White);
				}

				//HIGH SCORE COLOR CHANGE
				if (rectangle2.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
				{
					rectangle2.setOutlineColor(sf::Color(0, 128, 255)); // Lighter shade
					option2.setFillColor(sf::Color(30, 144, 255));
				}
				else
				{
					rectangle2.setOutlineColor(sf::Color::White); // Default color
					option2.setFillColor(sf::Color::White);
				}

				//CREDITS COLOR CHANGE
			    if (rectangle3.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
				{
					rectangle3.setOutlineColor(sf::Color(0, 128, 255)); // Lighter shade
					option3.setFillColor(sf::Color(30, 144, 255));
				}
				else
				{
					rectangle3.setOutlineColor(sf::Color::White); // Default color
					option3.setFillColor(sf::Color::White);
				}

				//KILO FLIGHT COLOR CHANGE
				if (rectangle4.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
				{
					rectangle4.setOutlineColor(sf::Color(0, 128, 255)); // Lighter shade
					option4.setFillColor(sf::Color(30, 144, 255));
				}
				else
				{
					rectangle4.setOutlineColor(sf::Color::White); // Default color
					option4.setFillColor(sf::Color::White);
				}

				//EXIT COLOR CHANGE
				if (rectangle5.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
				{
					rectangle5.setOutlineColor(sf::Color(255, 0, 0)); // Lighter shade
					option5.setFillColor(sf::Color(255, 0, 0));
				}
				else
				{
					rectangle5.setOutlineColor(sf::Color::White); // Default color
					option5.setFillColor(sf::Color::White);
				}
			}
			
			//QUIT ANIMATION
			/*else if (clicked == -1 && event.type == sf::Event::MouseButtonPressed)
			{
				clicked = 0;
				window.clear();
				quit_anim = 1;
			}*/

			else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
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
				else if (clicked == 0 && rectangle2.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
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
				else if ((clicked == 2 || clicked == 3 || clicked == 4) && rectangle6.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
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
			if (charactersprite.getPosition().x <= 1100)
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
			if (charactersprite.getPosition().y <= 570)
			{
				charactersprite.move(sf::Vector2f(0, 1));
			}
		}


		//DRAW AND SHOW IN WINDOW
		window.clear();
		
		window.draw(animation);
		//BACKGROUND ANIMATION MAKING WITH IMAGES. IT WILL CONTINUE SHOWING UNTIL MOUSE IS CLICKED
		if (clicked == -1)
		{
			for (int i = 0; i <110; i++) 
			{
				window.draw(animation);
				sf::Texture Videotexture;
				if (!Videotexture.loadFromFile(imageFileNames[i])) {
					cout << "Video images error!!!!\n";
				}
				sf::Sprite Videosprite(Videotexture);
				cout << i << endl;//PRINT THE VALUE OF i
				window.draw(Videosprite);
				window.display();//DISPLAY THE ANIMATION
				sf::sleep(sf::seconds(0.04));
			}
			clicked = 0;
		}



		else if (clicked == 1)// showing new game, character,enemy. 
		{
			if (enemy2sprite.getPosition().x <= 0)
				direction = 1;
			else if ((enemy2sprite.getPosition().x + 80) >= window.getSize().x)
				direction = 0;

			if (direction == 0) {
				enemy2sprite.move(-1.f, 0);
			}
			else {
				enemy2sprite.move(1.f, 0);
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
				std::cout << "Escape pressed!!\n";
				clicked = 0;
			}
			
			window.draw(newbackgroundsprite);
			window.draw(charactersprite);
			window.draw(enemy1sprite);
			window.draw(enemy2sprite);
			window.draw(enemy3sprite);
			window.draw(fuelsprite);
			window.draw(oilsprite);
		}
		else if (clicked == 0)
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
			window.draw(kiloflightbackgroundsprite);
			window.draw(rectangle6);
		}

		else if (clicked == 5)
		{
			window.close();
		}


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

/*
using namespace sf;
int main() {
	RenderWindow window(sf::VideoMode(1200, 850), "Bengal's air assault");
	window.setFramerateLimit(60);
	int direction = 0;

	CircleShape hoop;
	hoop.setRadius(50.f);
	hoop.setFillColor(Color::Black);
	hoop.setOutlineThickness(2.f);
	hoop.setOutlineColor(Color::Blue);
	hoop.setPosition(Vector2f(0, 10.f));
	bool isShot = false;


	CircleShape ball;
	ball.setRadius(20.f);
	ball.setFillColor(Color::Red);
	ball.setOutlineThickness(2.f);
	ball.setOutlineColor(Color::Cyan);
	ball.setPosition(Vector2f(0, window.getSize().y-ball.getRadius()*3));
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
				window.close();
		}
		//Update hoop
		if (hoop.getPosition().x <= 0)
			direction = 1;
		else if (hoop.getPosition().x + hoop.getRadius() >= window.getSize().x)
			direction = 0;
		if (direction == 0) {
			hoop.move(-5.f, 0);
		}
		else {
			hoop.move(5.f, 0);
		}
		//Update ball
		if (Mouse::isButtonPressed(Mouse::Left) && !isShot) {
			isShot = true;
		}
		if(!isShot)
			ball.setPosition(Mouse::getPosition(window).x, ball.getPosition().y);
		else
			ball.move(0, -5.f);
		//Collision Test
		if (ball.getPosition().y < 0 || ball.getGlobalBounds().intersects(hoop.getGlobalBounds())) {
			isShot = false;
			ball.setPosition(ball.getPosition().x, window.getSize().y - ball.getRadius() * 3);
		}
		window.clear(Color::White);
		//Draw
		window.draw(hoop);
		window.draw(ball);
		window.display();
	}
	return 0;
}*/






