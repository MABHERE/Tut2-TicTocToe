
class TicTacToe
{
private:
	char currentPlayer;
	char Board[3][3];  // board
public:
	//int place; // field where the player wants to play
	TicTacToe(); // constructor
	void setPlayer(char);
	char getPlayer();
	void changePlayer();
	void restart();
	bool move();
	void print();
	bool isWon(int);
	bool validateMove(int, int);

	~TicTacToe(); // deconstructor
};

