// Breadth-First search algorithm

#include <iostream>
#include <vector>
#include <deque>

using std::vector;

class Map {
public:
	const static int mapWidth{6};
	const static int mapHeight{5};
	vector<vector<int>> grid{
		{0, 1, 0, 0, 0, 0,},
		{0, 1, 0, 0, 0, 0,},
		{0, 1, 0, 0, 0, 0,},
		{0, 1, 0, 0, 0, 0,},
		{0, 0, 0, 1, 1, 0,}
	};
};

class Planner: public Map {
public:
	const int start[2]{0,0};
	const int goal[2]{mapHeight - 1, mapWidth - 1};
	const int cost{1};
	vector<vector<int>> movements{{-1,0}, {0,-1}, {1,0}, {0,1}};
	char movements_arrows[4]{'^', '<', 'v', '>'};
};

template<class T>
void print2DVector(T vec) {
	for (auto row : vec) {
		for (auto e : row)
			std::cout << e << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void print2screen(std::deque<vector<int>> frontier, int count) {
	std::cout << "Expansion #: " << count << std::endl;
	std::cout << "Open List: ";
	for (auto triplet : frontier) {
		std::cout << "[" << triplet[0] << " " << triplet[1] << " " << triplet[2] << "] ";
	}
	std::cout << std::endl;
	int n = frontier.size() - 1;
	std::cout << "Cell Picked: [" << frontier[n][0] << " " << frontier[n][1] << " " << frontier[n][2] << "]" << std::endl << std::endl;
}

void search(Map map, Planner planner)
{
	int g{0};
	int x = planner.start[0], y = planner.start[1];


	// 2D vector with all obstacles set to 0 and open space set to 1
	vector<vector<int>> path(map.mapHeight, vector<int>(map.mapWidth));
	path[x][y] = 1;

	// 2D expansion vector with all elements expanded in order, not explored cells set to -1
	vector<vector<int>> expansion(map.mapHeight, vector<int>(map.mapWidth, -1));

	// 2D vector showing direction
	vector<vector<int>> action(map.mapHeight, vector<int>(map.mapWidth, -1));

	// 2D vector storing expansions in frontier (FIFO)
	std::deque<vector<int>> frontier;
	frontier.push_front({g,x,y});

	bool at_goal = false;
	bool expandable = true;
	int count{0};
	int x2{}, y2{};

	while (!at_goal && expandable)
	{
		// check if any cells are left to expand inside the frontier
		if (frontier.size() == 0) {
			expandable = false;
			std::cout << "The problem is not complete - failed" << std::endl;
		} else {
			//print2screen(frontier, count);

			// storing triplet into next and removing it from frontier (FIFO)
			vector<int> next;
			next = frontier.back();
			frontier.pop_back();

			g = next[0];
			x = next[1];
			y = next[2];

			expansion[x][y] = count++;

			// check if arrived at goal
			if (x == planner.goal[0] && y == planner.goal[1]) {
				at_goal = true;
				std::cout << "Search algorithm is complete." << std::endl << std::endl;
			} else {

				for (size_t i = 0; i < planner.movements.size(); i++) {
					x2 = x + planner.movements[i][0];
					y2 = y + planner.movements[i][1];

					// check boundaries
					if (x2 >= 0 && x2 < map.grid.size() && y2 >= 0 && y2 < map.grid[0].size()) {

						if (map.grid[x2][y2] == 0 && path[x2][y2] == 0) {
							int g2 = g + planner.cost;
							frontier.push_front({g2,x2,y2});
							path[x2][y2] = 1;
							action[x2][y2] = i;
						}
					}
				}
			}
		}
	}
	std::cout << "BFS expansions in order:" << std::endl;
	print2DVector(expansion);
	//print2DVector(action);

	// 2D vector showing optimal path, 
	vector<vector<char>> policy(map.mapHeight, vector<char>(map.mapWidth, '-'));

	x2 = planner.goal[0];
	y2 = planner.goal[1];
	policy[x2][y2] = '*';

	while (x != planner.start[0] || y != planner.start[1]) {
		/* reverse direction of movements to find cell it was expanded from
		and therefore the shortest path, i.e. (1,0) -> (-1,0) */
		x = x2 - planner.movements[action[x2][y2]][0];
		y = y2 - planner.movements[action[x2][y2]][1];
		policy[x][y] = planner.movements_arrows[action[x2][y2]];
		x2 = x;
		y2 = y;
	}
	std::cout << "Optimal route:" << std::endl;
	print2DVector(policy);

}

int main()
{
	// instantiate map and planner objects
	Map map;
	Planner planner;

	// apply search algoritm
	search(map, planner);

	return 0;
}
