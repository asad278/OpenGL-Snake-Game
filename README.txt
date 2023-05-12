COMPILE:
g++ -lglut -lGL -o snake main.cpp snake.cpp

RUN:
./snake

MOVEMENTS:
UP -> UP ARROW KEY
DOWN -> DOWN ARROW KEY
LEFT -> LEFT ARROW KEY
RIGHT -> RIGHT ARROW KEY

EXIT: F1

ABOUT:
The Snake Game is a classic arcade game where the player controls a snake that moves around on a game board. The objective of the game is to guide the snake to eat food items, which causes the snake to grow longer. However, the player must avoid collisions with the walls or the snake's own body, as this leads to game over.

In this implementation, the game is built using the OpenGL library, which provides a powerful set of functions for rendering graphics. The game board is displayed on the screen using OpenGL's rendering capabilities, allowing for a visually appealing and interactive experience.

One of the key features of this Snake Game is the ability to change the speed or level of difficulty. Different levels offer different speeds, making the game more challenging as the snake moves faster. This adds an element of excitement and keeps the game engaging for players of varying skill levels.

Additionally, the game offers two modes: one with a border and one without a border. In the mode with a border, the game board is surrounded by walls, and the snake must navigate within the confines of the border. In the mode without a border, the snake can move freely without any boundaries, providing a different gameplay experience. Players can switch between these modes based on their preference or desired level of challenge.

To enhance the competitive aspect of the game, the implementation includes a feature to store and display the top 5 scores separately. Whenever a player achieves a high score, it is recorded and added to the list of top scores. This allows players to compare their performance with others and strive to improve their ranking on the leaderboard.

Overall, this Snake Game using the OpenGL library combines the classic gameplay of the Snake Game with various customizable features. Players can adjust the speed, choose between different modes, and aim for high scores. The use of OpenGL ensures smooth and visually appealing graphics, enhancing the overall gaming experience.
