#include <iostream>
#include "bst.hpp"
#include "squidGame.hpp"

using namespace std;

SquidGame::SquidGame() {

	myTree = new BST<int,int>();
}

SquidGame::~SquidGame() {

	delete myTree;

}

bool SquidGame::addGame(int game_id) {

	if(myTree->searchNode(game_id)!=NULL)
	{
		cout << "Game already exists, cannot add" <<endl;
		return false;
	}
	else{


	myTree->insertNode(new node<int,int>(game_id,0));

	return true;
}
}

bool SquidGame::removeGame(int game_id) {

	if(myTree->searchNode(game_id)==NULL)
	{
		cout << "Game does not exist, cannot remove" << endl;
		return false;
	}
	else{

	myTree->deleteNode(game_id);
	return true;
	}
}

void SquidGame::endAllgames() {

	int i = 0;
myTree->ender(myTree->getRoot());


}


bool SquidGame::addPlayer(int game_id) {


	
	if(myTree->searchNode(game_id) == NULL)
	{
		return false;
	}
	else
	{
		myTree->searchNode(game_id)->value = myTree->searchNode(game_id)->value+1;
		return true;
	}



}

bool SquidGame::killPlayer(int game_id) {

	if(myTree->searchNode(game_id) == NULL)
	{
		return false;
	}
	else if(myTree->searchNode(game_id) == 0)
	{
		return false;
	}
	else
	{
		myTree->searchNode(game_id)->value = myTree->searchNode(game_id)->value-1;
		return true;
	}

	
}

void SquidGame::inOrderDisplay() {
	myTree->inOrderTraversal(myTree->getRoot());
	return;
}

bool SquidGame::swapGames(int game1_id, int game2_id) {

if(myTree->searchNode(game1_id) == NULL or myTree->searchNode(game2_id) == NULL )
	{
		return false;
	}
else if(myTree->searchNode(game2_id)->value == 0)
{
	return false;
}
else
	{
		addPlayer(game1_id);
		killPlayer(game2_id);
		return true;
	}
	
}


int main()
{
	// SquidGame SquidGam;

	// SquidGam.removeGame(24);
	// SquidGam.addGame(24);
	// SquidGam.addGame(24);
	// SquidGam.removeGame(24);
	// SquidGam.addGame(3);
	// SquidGam.addGame(4);
	// SquidGam.addGame(7);
	// SquidGam.addGame(42);
	// SquidGam.addGame(8);
	// SquidGam.addGame(20000);
	// SquidGam.addGame(19);
	// SquidGam.addGame(201);
	// SquidGam.addPlayer(3);
	// SquidGam.addPlayer(3);
	// SquidGam.addPlayer(7);
	// SquidGam.addPlayer(42);
	// SquidGam.inOrderDisplay();
	// // SquidGam.addPlayer(24);
	// SquidGam.endAllgames();
	
	// SquidGam.inOrderDisplay();

	return 0;
}