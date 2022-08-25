// ALL INCLUDES DEFINED IN CONST FILE
#include "..\headers\const.h"



int main()
{
	// INIT WINDOW AND VARIABLES FOR CALCULATING FPS
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "TESTING");
	sf::Clock clock = sf::Clock::Clock();
	sf::Time previousTime = clock.getElapsedTime();
	sf::Time currentTime;
	float fps;

	window.setFramerateLimit(20);

	// ONE DIMENSIONAL VECTOR OF CELLS, USED TO STORE MAP "PIXELS"
	std::vector<Cell> cellVec;
	// LOOP OVER SCREEN AND ADD CELLS TO VECTOR
	for (int x = 0; x < COLS; x += 1.f)
	{
		for (float y = 0; y < ROWS; y += 1.f)
		{
			Cell cell(CELL_SIZE, CELL_SIZE, x * INIT_POS + xINIT_SPACE, y * INIT_POS + yINIT_SPACE);
			
			if (x == int(COLS * 0.5f) || x == int(COLS * 0.5f - 1.f) || y == int(ROWS * 0.5f) || y == int(ROWS * 0.5f - 1.f))
				cell.color(220, 220, 220);	// NOT PATH
			else
				cell.color(120, 150, 35);	// PATH
			cellVec.push_back(cell);		// ADD TO VECTOR
		}
	}



	// OBJECT TO HOLD ALL CARS
	Cars_Container cars;



	while (window.isOpen())
	{
		// CALCULATING FPS
		currentTime = clock.getElapsedTime();
		fps = 1.0f / (currentTime.asSeconds() - previousTime.asSeconds());
		//std::cout << fps << std::endl; // PRINT FPS
		previousTime = currentTime;

		// INIT EVENTS
		sf::Event event;
		// CHECK FOR EVENTS
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
					// ADD CAR TO MAP
				case sf::Keyboard::W:	// N
					cars.addCar(0);
					break;
				case sf::Keyboard::D:	// E
					cars.addCar(1);
					break;
				case sf::Keyboard::S:	// S
					cars.addCar(2);
					break;
				case sf::Keyboard::A:	// W
					cars.addCar(3);
					break;
				case sf::Keyboard::M:	// CHANGE LIGHTS
					cars.changeLight();
					std::cout << "Changed Lights" << std::endl;
					break;
				default:
					break;
				}
			default:
				break;
			}
		}



		// CLEAR WINDOW, UPDATE ALL LOGIC, AND FINALLY DISPLAY
		window.clear(sf::Color(160, 160, 160));

		// DRAW PRE-DEFINED MAP CELLS
		for (Cell cell : cellVec)
		{
			window.draw(cell.shape);
		}

		// DRAW ALL CARS IN CONTAINER OBJECT
		cars.driveCars();
		cars.drawCars(window);
		cars.removeCar();

		// DISPLAY ALL DRAWINGS
		window.display();
	}
	return 0;
}