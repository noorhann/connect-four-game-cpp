
#include <iostream>
using namespace std;

const int N = 6;
const int M = 7;
const int n_players = 2;
char marks[n_players] = { 'X', 'O' };
char grid[N][M];
int height;
int width;


//This function prints the grid of Connect Four Game as the game progresses
void print_grid() {
	for (int i = 0; i < n_players; i++) {
		cout << "Player " << i + 1 << ": " << marks[i] << "  ";
		if (i < n_players - 1)
			cout << "vs  ";
	}
	cout << "\n";
	cout << "--";
	for (int i = 0; i < M; cout << "---", i++);
	cout << "--\n";
	for (int i = 0; i < N; i++) {
		cout << "|  ";
		for (int j = 0; j < M; j++)
			cout << grid[i][j] << "  ";
		cout << "|\n";
		cout << "--";
		for (int i = 0; i < M; cout << "---", i++);
		cout << "--\n";
	}


}


//This function checks if the game has a win state or not
bool check_win() {
	height =  N;
	width = M;
//columns
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height - 3; y++) {
			if (grid[x][y] == grid[x][y + 1] && grid[x][y] == grid[x][y + 2] && grid[x][y] == grid[x][y + 3] && grid[x][y] != '.') {
				return true;
			}
		}
	}
//rows
	for (int x = 0; x < height; x++) {
		for (int y = 0; y < width - 3; y++) {
			if (grid[x][y] == grid[x + 1][y] && grid[x][y] == grid[x + 2][y] && grid[x][y] == grid[x + 3][y] && grid[x][y] != '.') {
				return true;
			}
		}
	}
//digonal
	for (int x = 0; x < width - 3; x++) {
		for (int y = 3; y < height; y++) {
			if (grid[x][y] == grid[x + 1][y - 1] && grid[x][y] == grid[x + 2][y - 2] && grid[x][y] == grid[x + 3][y - 3] && grid[x][y] != '.'){
				return true;

			}
		}
	}

	for (int x = 0; x < width - 3; x++) {
		for (int y = 0; y < height-3; y++) {
			if (grid[x][y] == grid[x + 1][y + 1] && grid[x][y] == grid[x + 2][y + 2] && grid[x][y] == grid[x + 3][y + 3] && grid[x][y] != '.') {
				return true;

			}
		}
	}
	return false;
}

// check tie

bool check_tie()
{
    int c = 0;
    for (int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(grid[i][j] != '.'){
                c++;
            }
        }
    }
    if(c == N * M){
        return true;
    }
    else{
        return false;
    }
}


// check empty
bool check_empty(int i)
{
    if (grid[0][i] == '.'){
        return true;
    }
    else{
        return false;
    }

}

// valid column

bool check_valid_column(int i)
{
    if(-1 < i < M ){
        return true;
    }
    else{
        return false;
    }

}

// set cell
void set_cell(int i , char mark){
    int c = N-1;
	for (int x = 0; x < N; x++) {
		for (int j = 0; j < M; j++) {
			if (grid[c][i] != '.') {
				c--;
			}
			else {
				grid[c][i] = mark;
				break;
			}
		} break;
	}
}

// grid clear
void grid_clear(){
 	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			grid[i][j] = '.';
		}
	}
}

//This function reads a valid position input
void read_input(int &i) {
    cout << "Enter the column index: ";
    cin >> i;
    while (!check_valid_column(i) || !check_empty(i)) {
        cout << "Enter a valid column index: ";
        cin >> i;
    }
}

//play game
void play_game() {
    cout << "Connect Four Game!\n";
    cout << "Welcome...\n";
    cout << "============================\n";
    int player = 0;
    while (true) {
        //Prints the grid
        print_grid();
        //Read an input from the player
        cout << "Player " << marks[player] << " is playing now\n";
        int i;
		read_input(i);
        //Set the input position with the mark
        set_cell(i, marks[player]);
        //Check if the state of the grid has a win state
        if (check_win()) {
            //Prints the grid
            print_grid();
            //Announcement of the final statement
            cout << "Congrats, Player " << marks[player] << " is won!\n";
            break;
        }
        //Check if the state of the grid has a tie state
        if (check_tie()) {
            //Prints the grid
            print_grid();
            //Announcement of the final statement
            cout << "Woah! That's a tie!\n";
            break;
        }
        //Player number changes after each turn
        player = (player + 1) % n_players;
    }
}
// Main function
int main() {
    while (true) {
    	grid_clear();
    	play_game();
    	char c;
    	cout << "Play Again [Y/N] ";
    	cin >> c;
    	if (c != 'y' && c != 'Y')
    		break;
    }
}
