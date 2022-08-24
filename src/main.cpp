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
	// VECTOR TO STORE ALL CAR OBJECTS
	std::vector<Car*> carVec;



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
					carVec.push_back(new Car(0));
					break;
				case sf::Keyboard::D:	// E
					carVec.push_back(new Car(1));
					break;
				case sf::Keyboard::S:	// S
					carVec.push_back(new Car(2));
					break;
				case sf::Keyboard::A:	// W
					carVec.push_back(new Car(3));
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

		// FOR ALL ACTIVE CARS, CHECK IF IT SHOULD BE INACTIVE, AND THEN DRAW IF IT REMAINS ACTIVE
		for (Car* car : carVec)
		{
			if (car->isActive)
			{
				car->checkEnd();
				car->color(220, 30, 30);
				car->move();
				window.draw(car->shape);
			}
		}

		window.display();

	}

	return 0;
}