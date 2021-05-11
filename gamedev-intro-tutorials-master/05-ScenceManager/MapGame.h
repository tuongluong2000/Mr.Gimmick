#pragma once
#include "GameObject.h"
#include "Textures.h"


#define TILE_WIDTH 16
#define TILE_HEIGHT 16

#define TILES_ZISE_X 11
#define TILES_ZISE_Y 40

#define MAX_MAP_Y 48
#define MAX_MAP_X 128

#define MAX_LINE 2000

typedef struct Map
{
	int MAP_X, MAP_Y;
	int TILE_SIZE_X, TILE_SIZE_Y;
	int ArrayTile[500][500];
};



class MapGame : public CGameObject
{
public:
	MapGame(int TileSetID, int MapY, int MapX, int TileSizeY, int TileSizeX, wstring MapPath)
	{
		this->game_map.MAP_X = MapX;
		this->game_map.MAP_Y = MapY;
		this->game_map.TILE_SIZE_X = TileSizeX;
		this->game_map.TILE_SIZE_Y = TileSizeY;
		TileSetImg = CTextures::GetInstance()->Get(TileSetID);
		LoadMap(MapPath);
	}
	~MapGame() { ; }

	void LoadMap(wstring mappath);
	//void Update(DWORD dt, vector<LPGAMEOBJECT>* colliable_objects = NULL) ;
	void DrawTiles(int val, float x, float y);
	void Render();
	void GetBoundingBox(float& left, float& top, float& right, float& bottom) { return; }
	float getMapWidth();
	float getMapHeight();

private:
	Map game_map;
	LPDIRECT3DTEXTURE9 TileSetImg;
};
