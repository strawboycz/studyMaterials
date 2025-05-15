#pragma once
#include <sstream>
#include <vector>
#include <xstring>
using namespace std;
/// <summary>
/// Třída reprezentující celé bludiště
/// </summary>
class Maze
{
public:
	/// <summary>
	/// Základní konsturktor
	/// </summary>
	Maze();
	/// <summary>
	/// Konstruktor podle zadaných cols a rows
	/// </summary>
	/// <param name="rows">počet řádků bludiště</param>
	/// <param name="cols">počet sloupců bludiště</param>
	Maze(int rows, int cols);
	/// <summary>
	///	Destruktor
	/// </summary>
	~Maze();
private:
	/// <summary>
	/// počet řádků bludiště
	/// </summary>
	int rows;
	/// <summary>
	/// počet sloupců bludiště
	/// </summary>
	int cols;
	
public:
	/// <summary>
	/// Třída reprezentující buňku v bludišti
	/// </summary>
	class Cell
	{
	public:
		/// určuje index buňky v bludišti
		int id;
		/// reprezentuje jestli má buňka levou stěnu
		bool leftWall = true;
		/// reprezentuje jestli má buňka horní stěnu
		bool topWall = true;
		/// reprezentuje jestli má buňka pravou stěnu
		bool rightWall = true;
		/// reprezentuje jestli má buňka spodní stěnu
		bool bottomWall = true;
		/// seznam sousedů buňky
		vector<Cell*> neighbours;
		/// <summary>
		/// Konstruktor se seznamem sousedů
		/// </summary>
		/// <param name="id">index buňky v bludišti</param>
		/// <param name="neighbours">seznam sousedů</param>
		Cell(int id, vector<Cell*> neighbours): id(id), neighbours(neighbours)
		{
		}
		/// <summary>
		/// Konstruktor pouze s indexem
		/// </summary>
		/// <param name="id">index buňky v bludišti</param>
		Cell(int id): id(id)
		{
		}
		/// <summary>
		/// Vrací SVG zápis buňky
		/// </summary>
		/// <param name="row">Řádek bludiště, ve kterém se buňka nachází</param>
		/// <param name="col">Sloupec bludiště, ve kterém se buňka nachází</param>
		/// <returns>string s SVG zápisem buňky</returns>
		string getSVG(int row, int col)
		{
			ostringstream ss;
			int x = col * 20;
			int y = row * 20;
			if(topWall) ss << "<line x1=\"" << x << "\" y1=\"" << y << "\" x2=\"" << (x + 20) << "\" y2=\"" << y << "\" stroke=\"black\" stroke-width=\"1\"/>\n";
			if(rightWall) ss << "<line x1=\"" << (x + 20) << "\" y1=\"" << y << "\" x2=\"" << (x + 20) << "\" y2=\"" << (y + 20) << "\" stroke=\"black\" stroke-width=\"1\"/>\n";
			if(bottomWall) ss << "<line x1=\"" << (x + 20) << "\" y1=\"" << (y + 20) << "\" x2=\"" << x << "\" y2=\"" << (y + 20) << "\" stroke=\"black\" stroke-width=\"1\"/>\n";
			if(leftWall) ss << "<line x1=\"" << x << "\" y1=\"" << (y + 20) << "\" x2=\"" << x << "\" y2=\"" << y << "\" stroke=\"black\" stroke-width=\"1\"/>\n";
			return ss.str();
		}
	};
	/// <summary>
	/// seznam obsahující buňky v bludišti
	/// </summary>
	vector<Cell*> cells;
	/// <summary>
	/// Najde buňku v bludišti podle id
	/// </summary>
	/// <param name="id">id buňky</param>
	/// <returns>Cell* buňka</returns>
	Cell* findCell(int id);
	/// <summary>
	/// Naplní bludiště novými buňkami
	/// </summary>
	void fillUp();
public:
	/// <summary>
	/// Vloží novou buňku do bludiště
	/// </summary>
	/// <param name="cellId">index buňky v bludišti</param>
	void insert(int cellId);
	/// <summary>
	/// Vloží novou buňku se seznamem sousedů do bludiště 
	/// </summary>
	/// <param name="cellId">index buňky v bludišti</param>
	/// <param name="neighbourIds">indexy sousedních buněk v bludišti</param>
	void insert(int cellId, vector<int> neighbourIds);
	/// <summary>
	/// Uloží bludiště ve formátu SVG do souboru podle path
	/// </summary>
	/// <param name="path">cesta k výstupnímu souboru</param>
	void saveSVG(string path);
	/// <summary>
	/// Vrací počet buněk v bludišti
	/// </summary>
	/// <returns>int počet buněk v bludišti</returns>
	int size();
	/// <summary>
	/// Vygeneruje cestu bludištěm
	/// </summary>
	/// <param name="seed">počáteční hodnota generátoru náhodných čísel</param>
	void generatePath(unsigned int *seed);
	/// <summary>
	/// Vrací zamíchaný seznam sousedů
	/// </summary>
	/// <param name="neighbours">původní seznam sousedů</param>
	/// <returns>vector<Cell*> zamíchaný seznam sousedů</returns>
	static vector<Maze::Cell*> getShuffeledNeighbours(vector<Cell*> neighbours);
};
