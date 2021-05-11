
#include "Game.h"
#include "MapGame.h"
#include "Textures.h"
#include <iostream>
#include <fstream>
#include "Utils.h"



void MapGame::LoadMap(wstring mappath)
{

	ifstream f;
	f.open(mappath);
	int data = 0;

	for (int i = 0; i < game_map.MAP_Y; i++)
	{
		for (int j = 0; j < game_map.MAP_X; j++)
		{
			f >> data;
			game_map.ArrayTile[i][j] = data;
			DebugOut(L"[ERROR] data %d not found!\n", data);
		}
	}
	f.close();
}



void MapGame::DrawTiles(int val, float x, float y)
{
	float x0, y0;

	x0 = int((val - 1) % game_map.TILE_SIZE_X) * 16;
	y0 = int((val - 1) / game_map.TILE_SIZE_X) * 16;

	CGame::GetInstance()->Draw(x, y, TileSetImg, x0, y0, x0 + 16, y0 + 16);
}




void MapGame::Render()
{
	float x0, y0;
	for (int i = 0; i < MAX_MAP_Y; i++)
	{
		for (int j = 0; j < MAX_MAP_X; j++)
		{


			x0 = j * 16;
			y0 = i * 16;
			int val = game_map.ArrayTile[i][j];
			DrawTiles(val, x0, y0);
		}
	}

}
float MapGame::getMapWidth() {
	return MAX_MAP_X * TILE_WIDTH;
}

float MapGame::getMapHeight() {
	return MAX_MAP_Y * TILE_HEIGHT;
}