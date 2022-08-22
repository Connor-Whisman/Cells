// ALL INCLUDES DEFINED IN CONST FILE
#include "..\headers\const.h"

Car car1;

int main()
{
	// INIT WINDOW AND VARIABLES FOR CALCULATING FPS
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "TESTING");
	sf::Clock clock = sf::Clock::Clock();
	sf::Time previousTime = clock.getElapsedTime();
	sf::Time currentTime;
	float fps;

	//window.setFramerateLimit(60);

	// DECLARE SINGLE OBJECT (ACTIVE CELL)
	Car activeCell; //CELL_SIZE, CELL_SIZE, INIT_POS + xINIT_SPACE, INIT_POS + yINIT_SPACE);
	activeCell.color(222, 30, 30);
	//std::vector<Car> carVec;
	//for (int i = 0; i < 5; i++)
	//{
	//	Car car;
	//	car.color(220, 30, 30);
	//	carVec.push_back(car);
	//}
	
	Car car2;
	car1.color(222, 30, 30);
	car2.color(222, 30, 30);


	

	// ONE DIMENSIONAL VECTOR OF CELLS
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
			//if (x % 2 == 0)
			//{
			//	cell.color(30, 160, 160);
			//}else
				cell.color(120, 150, 35);	// PATH
			cellVec.push_back(cell);		// ADD TO VECTOR
		}
	}


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
				// MOVE
				case sf::Keyboard::W:	// N
					activeCell.move(0);
					break;
				case sf::Keyboard::D:	// E
					activeCell.move(1);
					break;
				case sf::Keyboard::S:	// S
					activeCell.move(2);
					break;
				case sf::Keyboard::A:	// W
					activeCell.move(3);
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
		
		// LOOP THROUGH ONE-DIMENSIONAL VECTOR OF CELL OBJECTS
		//float iC = 0;
		for (Cell cell : cellVec)
		{
			//iC += 10;
			//cell.shape.setRotation(iC + i);
			window.draw(cell.shape);
			//cell.draw(window);
		}
		// DRAW ACTIVE CELL ON TOP OF GRID
		//activeCell.drive();
		//window.draw(activeCell.shape);
		//i += 10.f;
		// 
		//for (Car car : carVec)
		//{
		//	car.drive();
		//	window.draw(car.shape);
		//}
		car1.drive();
		window.draw(car1.shape);
		car2.drive();
		window.draw(car2.shape);


		window.display();

	}

	return 0;
}