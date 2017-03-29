// spatial neutrality.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include "vector.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <boost/timer.hpp>
#include "random_thijs.h"
#include <algorithm>
#include <fstream>
#include <cmath>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <string>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include "spatial neutrality.h"
#include "container.h"
#include "imageloader.h"
#include <string>
#include <iostream>
#include <windows.h> 
#include <vcclr.h>
#include <stdlib.h>
#include <boost/foreach.hpp>
#include <algorithm>

#include "Form1.h"




int window[3];
int t;
int ID_number;

extern container P;

std::vector< std::vector< species > > world;
std::vector< std::vector< int > > viable;
std::vector<species> metaCommunity;
std::vector<species> speciesList;
std::vector<int> octaveNumbers;
std::vector< std::vector< int > > reproduction;
std::vector<int> indices;

LPVOID glutFonts[7] = {
    GLUT_BITMAP_9_BY_15,
    GLUT_BITMAP_8_BY_13,
    GLUT_BITMAP_TIMES_ROMAN_10,
    GLUT_BITMAP_TIMES_ROMAN_24,
    GLUT_BITMAP_HELVETICA_10,
    GLUT_BITMAP_HELVETICA_12,
    GLUT_BITMAP_HELVETICA_18
}; 

bool sortSpeciesID(const species& Left, const species& Right) //sort from low to high
{
	if(Left.ID > Right.ID) return false;
	else if(Left.ID < Right.ID) return true;
	else return false;
}

bool sortSpeciesCount(const species& Left, const species& Right) //sort from high to low
{
	if(Left.count < Right.count) return false;
	else if(Left.count > Right.count) return true;
	else return false;
}



species newSpecies()
{
	species newS = species();
	ID_number++;
	newS.ID = ID_number;
	newS.C = color();
	speciesList.push_back(newS);
	std::sort(speciesList.begin(),speciesList.end(),sortSpeciesID);
	return newS;
}

void updateWorld2()
{
	//for(int n = 0; n < P.N; ++n)
	//{
	
	int size = world.size();
	std::vector<species> filler(size);	
	std::vector< std::vector< species > > newWorld(size,filler);

	std::vector<int> index = indices;

	std::random_shuffle(index.begin(), index.end());
	
	for(std::vector<int>::iterator i = index.begin(); i != index.end(); ++i)
	{
	  int y = (*i) % world.size();
	  int x = (int)( (*i) / world.size());
	
		//species at x,y dies and gets replaced
		//with prob 1-m it is from within the local community
		if(uniform() < P.m) //migration
		{
			species migrant = getSpeciesFromMetaCommunity();
			newWorld[x][y] = migrant;
		}
		else //no migration, local reproduction
		{
			int otherX = x; int otherY = y;
			if(P.dispersalType == "Square") findParent_Square(otherX,otherY,x,y); //square
			else if(P.dispersalType == "Circle") findParent_Circle(otherX,otherY,x,y); //circle
//			else if(P.dispersalType == "Reflect") findParent_Reflect(otherX,otherY,x,y);
			else findParent_Circle(otherX,otherY,x,y);  //default


			newWorld[x][y] = world[otherX][otherY];
			if(uniform() < P.speciationRate) newWorld[x][y] = newSpecies();
		}
	}

	world = newWorld;
}




void updateWorld()
{
	for(int n = 0; n < (0.5*P.N); ++n)
	{
		//pick a random cell
		int x = random_number(P.sizeX);
		int y = random_number(P.sizeY);
		bool picked_viable = (bool)viable[x][y];
		while(picked_viable == false)
		{
			x = random_number(P.sizeX);
			y = random_number(P.sizeY);
			picked_viable = (bool)viable[x][y];
		}


		//species at x,y dies and gets replaced
		//with prob 1-m it is from within the local community
		if(uniform() < P.m) //migration
		{
			species migrant = getSpeciesFromMetaCommunity();
			world[x][y] = migrant;
		}
		else //no migration, local reproduction
		{
			int otherX = x; int otherY = y;
			if(P.dispersalType == "Square") findParent_Square(otherX,otherY,x,y); //square
			else if(P.dispersalType == "Circle") findParent_Circle(otherX,otherY,x,y); //circle
//			else if(P.dispersalType == "Reflect") findParent_Reflect(otherX,otherY,x,y);
			else findParent_Circle(otherX,otherY,x,y);  //default


			world[x][y] = world[otherX][otherY];
			reproduction[otherX][otherY]++;
			//world[x][y] = world[otherX][otherY];


			if(uniform() < P.speciationRate) world[x][y] = newSpecies();
		}
	}
}

species getSpeciesFromMetaCommunity()
{
	double rand = uniform();

	int min = 0;
	int max = metaCommunity.size() - 1;
	int med = (int)((max+min)*0.5);
	while((max-min) > 1)
	{
		if(metaCommunity[med].fraction > rand) max = med;
		else min = med;

		med = (int)((max+min)*0.5);
	}
	if(metaCommunity[med].fraction < rand) return metaCommunity[max];
   else return metaCommunity[med];
}

int getSpeciesIndex()
{
	double rand = uniform();
	int min = 0;
	int max = metaCommunity.size() - 1;
	int med = (int)((max+min)*0.5); 
	while((max-min) > 1)
	{
		if(metaCommunity[med].fraction > rand) max = med;
		else min = med;

		med = (int)((max+min)*0.5);
	}
	if(metaCommunity[med].fraction < rand) return max;
   else return med;
	
}

void initializeMetaCommunity()
{
	int Jm = P.Jm;
	std::vector<int> abund(1,0);
	std::size_t nsp = 1;
	abund.push_back(1);
	//std::cout << "progress: " << "\t";
	(*(P.FORM))->add_systemLog("progress: \r\n");
	int disp = (int)(Jm * 0.1);
	for(int j = 1; j < Jm; ++j)
	{
		if(j % disp == 0)
		{
			int x = j / disp;

			std::ostringstream osstream;
			osstream << x;
			std::string str = osstream.str();
			str += "\r\n";
			(*(P.FORM))->add_systemLog(str);//std::cout << j / disp << "\t";
		}
		//std::cout.flush();
		double x = uniform();
		double val = P.theta / (P.theta + j -1);
		if(x < val)
		{
			nsp++;
			if(nsp > (abund.size()-1))
			{
				int dif = 1+nsp - abund.size();
				for(int k = 0; k < dif; ++k) abund.push_back(0);
				
			}
			
			abund[nsp] = 1;
		}
		else
		{
			int translate_to_abund = (int)((x * j)-1);
			//now find corresponding species
			std::size_t index = 0;
			while(index < abund.size())
			{
				translate_to_abund -= abund[index];
				if(translate_to_abund <= 0) break;

				index++;
			}

			abund[index] = abund[index] + 1;
		}
	}

	double multiply = 1.0 / (P.Jm - 1);

	for(std::size_t i = 0; i < abund.size() ;++i)
	{
		species newS = newSpecies();
		newS.fraction = abund[i] * multiply;
		newS.count = abund[i];

		metaCommunity.push_back(newS);
	}

	//remove all empty species
	std::vector<species> temp;
	for(std::vector<species>::iterator m = metaCommunity.begin(); m != metaCommunity.end(); ++m)
	{
		if((*m).count > 0) temp.push_back((*m));
	}
	metaCommunity = temp;

	std::sort(metaCommunity.begin(), metaCommunity.end(), sortSpeciesCount);
	//update fractions
	double cumsum = 0.0;
	for(std::vector<species>::iterator it = metaCommunity.begin(); it != metaCommunity.end(); ++it)
	{
		double add = 1.0 * (*it).count / Jm;
		cumsum += add;
		(*it).fraction = cumsum;		
	}
}

void Initialize()
{
	P.sizeX = viable.size();
	P.sizeY = viable[0].size();
	ID_number=0;

	for(int n = 0; n < P.N; ++n) indices.push_back(n);

		//std::cout << "starting Initialization Meta Community\n"; std::cout.flush();
	(*(P.FORM))->add_systemLog("starting Initialization Meta Community\r\n");	
	initializeMetaCommunity();
	//	std::cout << "Meta community initialized\n"; std::cout.flush();
	(*(P.FORM))->add_systemLog("Meta community initialized\r\n");

	t = 0;

	std::vector<int> holder(P.sizeY,0);
	reproduction.resize(P.sizeX,holder); //initialize the reproduction counts
	
	std::vector<species> YY;
	YY.resize(P.sizeY,species());
	world.resize(P.sizeX,YY);
	
	species empty = species();
	empty.ID = -1;
	empty.C = color(0.0,0.0,0.0);

	//std::cout << "Intializing local community\n"; std::cout.flush();
	(*(P.FORM))->add_systemLog("Intializing local community\r\n");
	species monoDom = getSpeciesFromMetaCommunity();

	for(int x = 0; x < P.sizeX; ++x)
	{
		for(int y = 0; y < P.sizeY; ++y)
		{
			if(viable[x][y] == 1) { 
				if(P.monoDominance == false) world[x][y] = getSpeciesFromMetaCommunity();
				else world[x][y] = monoDom;
			}
			else 
			{
				world[x][y] = empty;
			}
		}
	}
	//sort species list
	std::sort(speciesList.begin(), speciesList.end(), sortSpeciesID);

	//std::cout << "Initializing octave numbers\n"; std::cout.flush();
	(*(P.FORM))->add_systemLog("Initializing octave numbers\r\n");
	for(std::size_t i = 0; i < 20; ++i)
	{
		octaveNumbers.push_back( pow(2.0,(int)i));
	}
	
	//std::cout << "Initialization complete\n"; std::cout.flush();
	graphMetaCommunity();
	(*(P.FORM))->add_systemLog("Initialization complete\r\n");
}

void reset_simulation(gui::Form1^ F)
{
	//(*(P.FORM))->add_systemLog("Resetting all variables");
	metaCommunity.clear();

	t = 0;
	reproduction.clear();
	world.clear();
	viable.clear();
	speciesList.clear();
	octaveNumbers.clear();

	(*(&F))->resetCharts();
}

void closeWindow()
{
	stop_simul();
	P.isRunning = false;

	(*(P.FORM))->resetText();
	//reset_simulation(*(P.FORM));
}

int go(gui::Form1^ F)
{
	P.FORM = &F;
	P.isRunning = true;

	set_seed(P.Seed);   //331
	
	char* dummyargs;
	dummyargs = (char*) malloc(120* sizeof(char));
	int dummyargc = 1;
	strcpy(dummyargs,"Do I really need to pass arguments?!");
	glutInit(&dummyargc,&dummyargs);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,GLUT_ACTION_CONTINUE_EXECUTION);

	int notImportant = 0;
	//toArray(viable,P.FileName,notImportant);
	std::vector<int> YY(P.size,1);
	viable.resize(P.size,YY);

	int area = P.size * P.size;
	P.N = (int)(0.25 * area);
	
	Initialize();

	//F->changeMetaText();
	

	P.showGraph = true;
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(viable.size(),viable[0].size());

	window[0] = glutCreateWindow("The Neutralizer");
			glutPositionWindow(300,300);
			glutReshapeWindow(400, 400);
			glutDisplayFunc(display);
	P.createdGraphWindow = true;
	
	
	glutIdleFunc(display);
	glutCloseFunc(closeWindow);
	glutMainLoop();

	return 0;
}




bool compareSpecies(const species& s1, const species&s2)
{
	if(s1.ID != s2.ID) return false;
	else
	{
		if(s1.C.r != s2.C.r) return false;
		else
		{
			if(s1.C.b != s2.C.b) return false;
			else
			{
				if(s1.C.g != s2.C.g) return false;
			}
		}
	}

	return true;
}

int countSpecies()
{
	//std::vector<int> counted;
	//counted.resize(speciesList.size(),0);
	int outputSize = 0;
	std::vector<species> found;
	for(std::vector< std::vector< species >>::iterator X = world.begin(); X != world.end(); ++X)
	{
		for(std::vector<species>::iterator Y = (*X).begin(); Y != (*X).end(); ++Y)
		{
			bool match = false;
			for(std::vector<species>::iterator s = found.begin(); s != found.end(); ++s)
			{
				if((*Y) == (*s))
				{
					(*s).count++;
					match = true;
					break;
				}
			}

			if(match == false) //we have found no match, e.g. a "new" species
			{
				found.push_back((*Y));
				found.back().count = 1;
			}
		}
	}

	return found.size();
}

int countIndivs()
{
  int total = 0;
  for(std::vector< std::vector< species >>::iterator X = world.begin(); X != world.end(); ++X)
  {
		for(std::vector<species>::iterator Y = (*X).begin(); Y != (*X).end(); ++Y)
		{
			if((*Y).ID != -1) total++;
		}
  }
  return total;
}


void dispGraph()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//if(P.showReproduction == false)	rect();
	//else rect_repro();
	rect();
	glutSwapBuffers();
}

void updateSim()
{
	int numberSpec = -1;

	if(t%P.update == 0) 
	{
		numberSpec = countSpecies();

		(*(P.FORM))->set_time(t);
		(*(P.FORM))->set_species(numberSpec);
		

		graphLocalCommunity();
	}

	if(t%10 == 0) { 
		if(numberSpec < 0) numberSpec = countSpecies();
		(*(P.FORM))->updateSpeciesChart(t,numberSpec);
	}
	t++;
}



void rect()
{
	double stepX = 2.0f / P.sizeX;
	double stepY = 2.0f / P.sizeY;
	
	for(std::size_t X = 0; X < viable.size(); X++)
	{
		for(std::size_t Y = 0; Y < viable[X].size(); Y++)
		{				
			
			//GLfloat x1 = -1.0f + 1.0f * X * stepX;
			double x1 = -1.0f + 1.0f * X * 2.0 / P.sizeX;
			double y1 = -1.0f + 1.0f * Y * 2.0 / P.sizeY;
				//1.0f - 1.0f * X * stepX;
			//GLfloat y1 = -1.0f + 1.0f * Y * stepY;//1.0f - 1.0f * Y * stepY;
			
			float grey = 100.0f / 255;
			color C_square = color(grey,grey,grey);

			if(viable[X][Y] == 1) C_square = world[X][Y].C;
			
			glColor3f(C_square.r,C_square.g,C_square.b);
			glRectf(x1,y1,x1 + 2.0 / P.sizeX,y1+2.0 / P.sizeY);

		}
	}
}


void display() 
{	   
	if(P.isPaused == false) {
		updateWorld();
		updateSim();
	
		if(P.showGraph == true)
		{
			if(P.createdGraphWindow == false)
			{	
				window[0] = glutCreateWindow("The Neutralizer");
				glutPositionWindow(1000,500);
				glutReshapeWindow(viable.size(), viable[0].size());
				
				if(t % P.update == 0) glutDisplayFunc(display);
			}
			glutSetWindow(window[0]);
			P.createdGraphWindow = true;
			if(t % P.update == 0) dispGraph();
		}
		else
		{
			if(P.createdGraphWindow == true) 
			{
			//	glutDestroyWindow(window[0]);
			//	P.createdGraphWindow = false;
			}
		}
	}
}

color::color(const float &R, const float &G, const float &B)
{
	r = R;
	g = G;
	b = B;
}

color::color()
{
	r = (float)uniform();
	g = (float)uniform();
	b = (float)uniform();
}


species::species()
{
	ID = random_number(P.sizeX*P.sizeY);
	count = 0;
	C = color();
}

species::species(const double& f)
{
	ID = random_number(P.sizeX*P.sizeY);
	fraction = f;
	C = color();
}

void glutPrint(float x, float y, LPVOID font, char* text, float r, float g, float b, float a)
{
    if(!text || !strlen(text)) return;
    bool blending = false;
    if(glIsEnabled(GL_BLEND)) blending = true;
    glEnable(GL_BLEND);
    glColor4f(r,g,b,a);
    glRasterPos2f(x,y);
    while (*text) {
        glutBitmapCharacter(font, *text);
        text++;
    }
    if(!blending) glDisable(GL_BLEND);
} 


void findParent_Square(int& otherX, int& otherY, const int& x, const int& y)
{
	otherX = random_number(2 * P.L + 1) - P.L;
	otherY = random_number(2 * P.L + 1) - P.L;

	otherX += x;
	otherY += y;

	bool suitable = true;
	if(otherX == x && otherY == y) suitable = false;
	else if(otherX < 0) suitable = false;
	else if(otherX >= P.sizeX) suitable = false;
	else if(otherY < 0) suitable = false;
	else if(otherY >= P.sizeY) suitable = false;
	else if(viable[otherX][otherY] == 0) suitable = false;

	while(suitable == false)
	{
		otherX = x + random_number(2 * P.L + 1) - P.L;
		otherY = y + random_number(2 * P.L + 1) - P.L;
		suitable = true;

		if(otherX == x && otherY == y) suitable = false;
		else if(otherX < 0) suitable = false;
		else if(otherX >= P.sizeX) suitable = false;
		else if(otherY < 0) suitable = false;
		else if(otherY >= P.sizeY) suitable = false;
		else if(viable[otherX][otherY] == 0) suitable = false;
	}
 return;
}

void findParent_Circle(int& other_X, int& other_Y, const int& x, const int& y)
{
	double range = P.L;
	if(range > P.sizeX || range > P.sizeY) 
	{
		range = P.sizeX;
	}
	
	double distance = uniform() * range;
	double dir = uniform() * 2 * P.Pi;
	double pY = sin(dir) * distance;
	double pX = cos(dir) * distance;

	int otherX = (int)(0.5 + x + pX);
	int otherY = (int)(0.5 + y + pY);
	bool suitable = true;
	if(otherX == x && otherY == y) suitable = false;
	else if(otherX < 0) suitable = false;
	else if(otherX >= P.sizeX) suitable = false;
	else if(otherY < 0) suitable = false;
	else if(otherY >= P.sizeY) suitable = false;
	else if(viable[otherX][otherY] == 0) suitable = false;
	while(suitable == false)
	{
		distance = uniform() * range;
		dir = uniform() * 2 * P.Pi;
		pY = sin(dir) * distance;
		pX = cos(dir) * distance;
		otherX = (int)(0.5 + x + pX);
		otherY = (int)(0.5 + y + pY);

		suitable = true;
		if(otherX == x && otherY == y) suitable = false;
		else if(otherX < 0) suitable = false;
		else if(otherX >= P.sizeX) suitable = false;
		else if(otherY < 0) suitable = false;
		else if(otherY >= P.sizeY) suitable = false;
		else if(viable[otherX][otherY] == 0) suitable = false;
	}

	other_X = otherX;
	other_Y = otherY;
	return;
}

bool species::operator ==(const species &other)
{
	if(ID != other.ID) return false;
	else
	{
		if(C.r == other.C.r)
		{
			if(C.g == other.C.g)
			{
				if(C.b == other.C.b)
				{
					return true;
				}
				else return false;
			}
			else return false;
		}
		else return false;
	}
}

int octave_sort(long ab_in) //adapted from James
{
	int result;
	if(ab_in <= 0)
	{
		result = 0;
	}
	else 
	{
		long min = 1;
		long max = 2;
		result = 0;
		while(!((ab_in < max)&&(ab_in >= min)))
		{
			min = min*2;
			max = max*2;
			result ++;
		}
	}
	return result;
}

void graphMetaCommunity()
{
	if(P.graphedMeta == true) return;
	
	std::vector<int> counts;
	for(std::vector<species>::iterator s = metaCommunity.begin(); s != metaCommunity.end(); ++s)
	{
	   if((*s).count > 0) counts.push_back((*s).count);
	}

	std::vector<double> logs (40,0);
	
	BOOST_FOREACH(int i, counts)
	{
		int octave = octave_sort(i);
		logs[octave]++;
	}


	bool empty = true;
	while(empty)
	{
		if(logs.back() == 0)
		{
			empty = true;
			logs.pop_back();  //cut off all empty parts of the vector
		} 
		else
		{
			empty = false;
		}
	}
	P.graphedMeta = true;

	(*(P.FORM))->drawMetaChart(logs);
}

void graphLocalCommunity()
{
	std::vector<int> counts;
	std::vector<species> speciesCount;// = speciesList;
    for(std::vector< std::vector< species >>::iterator X = world.begin(); X != world.end(); ++X)
	{
		for(std::vector<species>::iterator Y = (*X).begin(); Y != (*X).end(); ++Y)
		{
			bool match = false;
			for(std::vector<species>::iterator s = speciesCount.begin(); s != speciesCount.end(); ++s)
			{
				if((*Y) == (*s))
				{
					(*s).count++;
					match = true;
					break;
				}
			}
			
			if(match == false)
			{
				speciesCount.push_back((*Y));
				speciesCount.back().count = 1;
			}
		}
	}
	
	for(std::vector<species>::iterator S = speciesCount.begin(); S != speciesCount.end(); ++S)
	{
	  if((*S).count > 0) counts.push_back((*S).count);
	}

	std::vector<double> logs (40,0);

	BOOST_FOREACH(int i, counts)
	{
		if(i == 1)
		{
			int a = 5;

		}
		int octave = octave_sort(i);
		logs[octave]++;
	}



	bool empty = true;
	while(empty)
	{
		if(logs.back() == 0)
		{
			empty = true;
			logs.pop_back();  //cut off all empty parts of the vector
		} 
		else
		{
			empty = false;
		}
	}

	(*(P.FORM))->drawLocalChart(logs);

	//code to make rank abundance plot
	std::vector<double> percentages;
	int max = -1;
	BOOST_FOREACH(int i, counts)
	{
		if(i > max) max = i;
	}

	for(std::size_t i = 0; i < counts.size(); ++i)
	{
		percentages.push_back(  100.0 * counts[i] / max );
	}

	std::sort(percentages.begin(), percentages.end(),std::greater<double>());

	(*(P.FORM))->drawRankChart(percentages);
}


void stop_simul()
{
	glutLeaveMainLoop();
}




/*void findParent_Reflect(int& other_X, int& other_Y, const int& x, const int& y)
{
	//first pick a random direction
	double dir = uniform() * 2 * P.Pi;
	//then a random distance
	double distance = uniform() * P.L;
	//then calculate new position:
	double pY = sin(dir) * distance;
	double pX = cos(dir) * distance;

	int otherX = (int)(0.5 + x + pX);
	int otherY = (int)(0.5 + y + pY);
	
	//then check if it lands in inviable habitat
	bool suitable = false;
	bool insidePlane_X = false;
	bool insidePlane_Y = false;

	for(;;)
	{


		if(otherX < 0) insidePlane_X = false;
		else if(otherX >= P.sizeX) insidePlane_X = false;
		else insidePlane_X = true;

		if(otherY < 0) insidePlane_Y = false;
		else if(otherY >= P.sizeY) insidePlane_Y = false;
		else insidePlane_Y = true;
		
		if(insidePlane_Y == true && insidePlane_X == true)
		{
			if(viable[otherX][otherY] == 0) suitable = false;
			else suitable = true;
		}
		else suitable = false;

		if(suitable == true)
		{
			if(insidePlane_X == true)
			{
				if(insidePlane_Y == true)
				{
					break;
				}
			}
		}


		if(insidePlane_X == false ) //the point lies outside the viewing box in the x direction, so mirror in the X direction
		{
			//calculate differnce with X barrier:
			
		}

		if(insidePlane_Y == false) //the point lies outside the viewing box in the y direction, so mirror in the y direction
		{
			//calculate differnce with Y barrier:
			
		}

		if(suitable == false) //the point lies outside somewhere, so mirror in the local reflection boundary
		{
			//then calculate the intersecting plane

			//find the intersecting point!
			vec2 disp = vec2(x,y);
			vec2 dir_disp = vec2(sin(dir),cos(dir));
			dir_disp.normalize();
			double disp_dist = distance;

			//find vector of the wall....
			//travel along the movement vector until the next point is a 0
			int wall_x,wall_y;
			for(int i = 0; i < 20; ++i)
			{
				double dist_v = i * 1.0 / 20;
				double dist_probe = dist_v * disp_dist;
				vec2 probing = disp + dir_disp * dist_probe;
				int probe_X = (int)((0.5) + probing.x);
				int probe_Y = (int)((0.5) + probing.y);

				bool living = viable[probe_X][probe_Y];
				if(living == false)
				{
					//previous one was the edge!
					double dist_v2 = 1.0 / (i-1);
					double dist_probe2 = dist_v2 * disp_dist;
					vec2 probing2 = disp + dir_disp * dist_probe2;
					wall_x = (int)((0.5) + probing2.x);
					wall_y = (int)((0.5) + probing2.y);
					break;
				}
			}

			//this point is the intersection point (wall_x,wall_Y)

			//now we can determine the vector of the wall by finding the neighbouring 1s and 0s
			
			//first calculate the X direction
			int sumUp = 0;
			int sumDown = 0;
			for(int k = 0; k < 2; ++k)
			{
				sumUp += viable[wall_x-1+k][wall_y+1];
				sumDown += viable[wall_x-1+k][wall_y-1];
			}
			double dX = abs((sumUp - sumDown)) * 2.0 / 3.0;
			//ok, now we have the change in the X direction
			//now we need the sign
			if(viable[wall_x-1][wall_y] == 0) dX *= -1;
			
			int sumLeft = 0;
			int sumRight = 0;
			for(int k = 0; k < 2; ++k)
			{
				sumLeft += viable[wall_x+1][wall_y-1+k];
				sumRight += viable[wall_x-1][wall_y-1+k];
			}
			double dY = abs((sumUp-sumDown)) * 2.0 / 3.0;
			if(viable[wall_y-1][wall_x] == 0) dY *= -1;

			   int x1 = viable[wall_x-1][wall_y-1];
				int x2 = viable[wall_x-1][wall_y];
				int x3 = viable[wall_x-1][wall_y+1];
				int x4 = viable[wall_x][wall_y-1];
				int x5 = viable[wall_x][wall_y];
				int x6 = viable[wall_x][wall_y+1];
				int x7 = viable[wall_x+1][wall_y-1];
				int x8 = viable[wall_x+1][wall_y];
				int x9 = viable[wall_x+1][wall_y+1];
			
      
			vec2 dir_wall = vec2(dX,dY);
			dir_wall.normalize();

			//left over part of the distance to be mirrored:
			double dist_taken = (disp.x - wall_x) * (disp.x - wall_x) + (disp.y - wall_y) * (disp.y - wall_y);
			dist_taken = sqrt(dist_taken);
			double remaining_dist = disp_dist - dist_taken;

			//now calculate the angle between the disperser and the wall
			//double val = dot(dir_wall,dir_disp);
			//double angle = acos(val);
			vec2 intersect = vec2(wall_x,wall_y);
			vec2 v = vec2(dir_disp.x,dir_disp.y);
			vec2 l = vec2(dir_wall.x,dir_wall.y);
			vec2 refl = 2 * (dot(v,l)) / (dot(l,l))*l - v;

			vec2 output = intersect + refl * remaining_dist;
			
			otherX = (int)(0.5 + output.x);
			otherY = (int)(0.5 + output.y);
			
		  }
		std::cout << otherX << "\t" << otherY << "\n";



		other_X = otherX;
		other_Y = otherY;
		//std::cout << otherX << "\t" << otherY << "\n";
		//std::cout.flush();
		return;

}

void findParent_Reflect(int& other_X, int& other_Y, const int& x, const int& y)
{
	vec2 start = vec2(x,y);
	double dir = uniform() * 2 * P.Pi;

	vec2 start_dir = vec2(cos(dir),sin(dir));
	//std::cout << start_dir.x << "\t"<< start_dir.y << "\n";
	start_dir.normalize();
	double distance = uniform() * P.L;    // -1 * P.L + 2 * P.L * uniform();//1 + //random_number(P.L);
	
	
	bool done = false;
	vec2 landing;

	while(done == false)
	{
		landing = start + (start_dir * distance); //this is where the offspring lands
		landing.x = floor(0.5 + landing.x);
		landing.y = floor(0.5 + landing.y);
		//now we have to check if this is allowed
		bool inside_X = true;
		bool inside_Y = true;
		bool suitable = true;

		if(landing.x < 0) inside_X = false;
		else if(landing.x >= P.sizeX) inside_X = false;
		

		if(landing.y < 0) inside_Y = false;
		else if(landing.y >= P.sizeY) inside_Y = false;

		if(inside_X == true && inside_Y == true)
		{
			if(viable[(int)landing.x][(int)landing.y] == false)
			{
				suitable = false;
			}
		}
		
		if(inside_X == false) done = false;
		else if(inside_Y == false) done = false;
		else if(suitable == false) done = false;
		else done = true;

		if(done == false) //we have to reflect!
		{
			vec2 intersect;
			//first calculate intersection point
			for(int i = 1; i < 30; ++i)
			{
				double dist_int = i * 0.05 * distance;
				vec2 probing = (start + start_dir * dist_int);

				if(inside_X == false) 
				{
					if(probing.x < 0) { intersect = vec2((start + start_dir * (i-1) * 0.05 * distance)); break;}
					if(probing.x > P.sizeX) { intersect = vec2((start + start_dir * ((i-1) * 0.05 * distance))); break;}
				}

				if(inside_Y == false)
				{
					if(probing.y < 0) {  intersect = vec2((start + start_dir * (i-1) * 0.05 * distance)); break;}
					if(probing.y > P.sizeY) { intersect = vec2((start + start_dir * (i-1) * 0.05 * distance)); break; }
				}

				if(suitable == false)
				{
					if(viable[(int)probing.x][(int)probing.y] == false) { intersect = vec2((start + start_dir * (i-1) * 0.05 * distance)); break;}
				}
			}

			//ok, we have calculated the intersection point, now lets calculate the new direction

			//first we need the vector of the wall
			vec2 wall;
			if(inside_X == false) wall = vec2(0,1);
			if(inside_Y == false) wall = vec2(1,0);

			if(inside_X == false && inside_Y == false)
			{
			   int dx = 1;
			   int dy = 1;
			   if(landing.y < 0 && landing.x < 0) dy = -1;
			   if(landing.y >= P.sizeY && landing.x >= P.sizeX) dy = -1;

			   wall = vec2(dx,dy);
			}

			if(suitable == false) //complex wall!
			{
				int dx = viable[intersect.x -1][intersect.y] - viable[intersect.x + 1][intersect.y];
				int dy = viable[intersect.x][intersect.y+1] - viable[intersect.x][intersect.y-1];

				wall = vec2(dx,dy);				
			}

			vec2 v = start_dir; v.normalize();
			vec2 l = wall; l.normalize();
			vec2 refl = 2 * l * ( (dot(v,l)) / (dot(l,l))) - v; refl.normalize();

			//distance to travel is reduced by already travelled 
			
			double traversed = (landing.x - intersect.x) * (landing.x - intersect.x) + (landing.y - intersect.y) * (landing.y - intersect.y);
			traversed = sqrt(traversed);

			
			distance -= traversed;
			start = intersect;
			start_dir = refl;
		}
		else
		{
			start = landing;
		}
	}

	other_X = start.x;
	other_Y = start.y;

	return;
}

void resetReproduction()
{
			for(std::vector< std::vector< int >>::iterator X = reproduction.begin(); X != reproduction.end(); ++X)
			{
				for(std::vector<int>::iterator Y = (*X).begin(); Y != (*X).end(); ++Y)
				{
					(*Y) = 0;
				}
			}
}

void rect_repro()
{
	int maxRepro = -1;
	int minRepro = 1e99;
	 for(std::vector< std::vector< int >>::iterator X = reproduction.begin(); X != reproduction.end(); ++X)
	{
		for(std::vector<int>::iterator Y = (*X).begin(); Y != (*X).end(); ++Y)
		{
			if((*Y) > maxRepro) maxRepro = (*Y);
			if((*Y) < minRepro) minRepro = (*Y);
		}
	}
	
	double multiply = 1.0 / (maxRepro-minRepro);

	for(int X = 0; X < P.sizeX; ++X)
	{
		for(int Y = 0; Y < P.sizeY; ++Y)
		{				
			float stepX = 2.0f / P.sizeX;
			float stepY = 2.0f / P.sizeY;
			GLfloat x1 = -1.0f + 1.0f * X * stepX;
			GLfloat y1 = 1.0f - 1.0f * Y * stepY;

			float grey = 100.0 / 255;
			color C_square = color(grey,grey,grey);
			if(viable[X][Y] == 1) 
			{
				double val = (reproduction[X][Y]-minRepro) * multiply;
				C_square = color(val,0,1.0-val);
			}

			glColor3f(C_square.r,C_square.g,C_square.b);
			glRectf(x1,y1,x1+stepX,y1-stepY);
		}
	}
}


void dispStat()
{
	   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	   //count species
	   if(t%P.update == 0)
	   {
		   std::vector<species> speciesCount;// = speciesList;
		   for(std::vector< std::vector< species >>::iterator X = world.begin(); X != world.end(); ++X)
		   {
				for(std::vector<species>::iterator Y = (*X).begin(); Y != (*X).end(); ++Y)
				{
					bool match = false;
					for(std::vector<species>::iterator s = speciesCount.begin(); s != speciesCount.end(); ++s)
					{
						if((*Y) == (*s))
						{
							(*s).count++;
							match = true;
							break;
						}
					}

					if(match == false)
					{
						speciesCount.push_back((*Y));
						speciesCount.back().count = 1;
					}
					
					
					
					/*int ID_to_match = (*Y).ID;
					//now find if the ID is in "speciesList", and record the index;
					int i = 0;
					//get the middle element
					int min = 0;
					int max = speciesList.size() - 1;
			
					for(int k = 0; k < speciesList.size(); ++k)
					{
						int middle = 0.5 * (max - min);
						int middleElement = speciesList[middle].ID;
						if(ID_to_match == middleElement) 
						{
							i = middleElement;
							counts[i]++;
							break;
						}
						if(ID_to_match > middleElement) min = middleElement;
						if(ID_to_match < middleElement) max = middleElement;
					}*//*
				}
			}
	
		   std::vector<int> counts;
		   for(std::vector<species>::iterator S = speciesCount.begin(); S != speciesCount.end(); ++S)
		   {
			   if((*S).count > 0) counts.push_back((*S).count);
		   }


		   std::vector<double> octaves(20,0);
		   for(std::size_t S = 0; S < counts.size(); ++S)
		   {
			   //find the octave
			   for(int i = 14; i > -1; --i)
			   {
				   int dif = (counts[S] - octaveNumbers[i]);
				   if (dif == 0)
				   {
					   octaves[i+1] +=0.5;
					   octaves[i]   +=0.5;
					   break;
				   }
				   else if( dif > 0)
				   {
					   octaves[i]++;
					   break;
				   }
			   }
		   }
		   int maxCat = 0;
		   for(std::size_t i = 0; i < octaves.size() - 1; ++i)
		   {
			   if(octaves[i] > 0)
			   {
				   if(octaves[i+1] <= 0)
				   {
					   maxCat = i;
				   }
			   }
		   }

		   int maxCount = 0;
		   for(std::size_t i = 0; i < octaves.size(); ++i) if(octaves[i] > maxCount) maxCount = octaves[i];
	   
		   //first draw background of the graph:
		   glColor3f(1.0f,1.0f,1.0f);
		   glRectf(-0.8f,-0.8f,0.8f,0.8f);

		   //now add scales and text
		    double lengthX = 2 * 0.8;
		   double numCats = maxCat - 0;
		   double sizePerCat = lengthX / (numCats+1);
		   double indent = sizePerCat * 0.5;
		   for(int i = 0; i <= numCats; ++i)
		   {
				if(octaveNumbers[i] > 10) indent = sizePerCat * 0.4;
				if(octaveNumbers[i] > 100) indent = sizePerCat * 0.3;
				if(octaveNumbers[i] > 1000) indent = sizePerCat * 0.2;
				if(octaveNumbers[i] > 10000) indent = sizePerCat * 0.1; 
			   
			   float x = -0.8f + (sizePerCat * i) + indent;
			   char t [20];
			   //itoa( octaveNumbers[i],t,10);
			   sprintf(t,"%d",octaveNumbers[i]);
			   glutPrint(x, -0.9,glutFonts[2],t,1.0,1.0,1.0,1.0);
		   }

		   char t[20];
		  // itoa(maxCount,t,10);
		   sprintf(t,"%d",maxCount);
		   glutPrint(-0.95f,0.75f,glutFonts[4],t,1.0f,1.0f,1.0f,1.0f);
		   glutPrint(-0.95f,-0.75f,glutFonts[4],"0",1.0f,1.0f,1.0f,1.0f);

		   //start drawing the rectangles
		   //maxCount *= 1.10; //prevent the graph from fully filling the canvas
		   float height = 1.6f;
		   for(int i = 0; i <= (numCats); ++i)
		   {
			   GLfloat minX = -0.8 + i * sizePerCat;
			   GLfloat minY = -0.8;
			   GLfloat maxX = -0.8 + (i + 1) * sizePerCat;
			   GLfloat maxY = minY + height * (1.0 * octaves[i] / maxCount);
			   if(maxY > 0.8f) maxY = 0.8;
			   glColor3f(0.0f,0.0f,1.0f);
			   glRectf(minX,minY,maxX,maxY);
		   }
		   glutSwapBuffers();
	   }
}

void dispMeta()
{
	   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	   //count species
	   if(t%P.update == 0)
	   {
		   //std::vector<species> speciesCount = speciesList;
		   std::vector<int> counts;
		   for(std::vector<species>::iterator s = metaCommunity.begin(); s != metaCommunity.end(); ++s)
		   {
			   if((*s).count > 0) counts.push_back((*s).count);
		   }
		  // std::sort(speciesCount.begin(), speciesCount.end());
		   std::vector<double> octaves(20,0);
		   for(std::size_t S = 0; S < counts.size(); ++S)
		   {
			   //find the octave
			   for(int i = 14; i > -1; --i)
			   {
				   int dif = (counts[S] - octaveNumbers[i]);
				   if (dif == 0)
				   {
					   octaves[i+1] +=0.5;
					   octaves[i]   +=0.5;
					   break;
				   }
				   else if( dif > 0)
				   {
					   octaves[i]++;
					   break;
				   }
			   }
		   }
		   int maxCat = 0;
		   for(std::size_t i = 0; i < octaves.size() - 1; ++i)
		   {
			   if(octaves[i] > 0)
			   {
				   if(octaves[i+1] <= 0)
				   {
					   maxCat = i;
				   }
			   }
		   }

		   int maxCount = 0;
		   for(int i = 0; i < octaves.size(); ++i) if(octaves[i] > maxCount) maxCount = octaves[i];
	   
		   //first draw background of the graph:
		   glColor3f(1.0f,1.0f,1.0f);
		   glRectf(-0.8f,-0.8f,0.8f,0.8f);

		   //now add scales and text
		   double lengthX = 2 * 0.8;
		   double numCats = maxCat - 0;
		   double sizePerCat = lengthX / (numCats+1);
		   double indent = sizePerCat * 0.5;
		   for(int i = 0; i <= numCats; ++i)
		   {
				if(octaveNumbers[i] > 10) indent = sizePerCat * 0.4;
				if(octaveNumbers[i] > 100) indent = sizePerCat * 0.3;
				if(octaveNumbers[i] > 1000) indent = sizePerCat * 0.2;
				if(octaveNumbers[i] > 10000) indent = sizePerCat * 0.1; 
			   
			   float x = -0.8 + (sizePerCat * i) + indent;
			   char t [20];
			   //itoa( octaveNumbers[i],t,10);
			   sprintf(t,"%d",octaveNumbers[i]);
			   glutPrint(x, -0.9,glutFonts[2],t,1.0,1.0,1.0,1.0);
		   }

		   char t[20];
		  // itoa(maxCount,t,10);
		   sprintf(t,"%d",maxCount);
		   glutPrint(-0.95f,0.75f,glutFonts[4],t,1.0f,1.0f,1.0f,1.0f);
		   glutPrint(-0.95f,-0.75f,glutFonts[4],"0",1.0f,1.0f,1.0f,1.0f);

		   //start drawing the rectangles
		   maxCount *= 1.05; //prevent the graph from fully filling the canvas
		   float height = 1.6f;
		   for(int i = 0; i <= (numCats); ++i)
		   {
			   GLfloat minX = -0.8 + i * sizePerCat;
			   GLfloat minY = -0.8;
			   GLfloat maxX = -0.8 + (i + 1) * sizePerCat;
			   GLfloat maxY = minY + height * (1.0 * octaves[i] / maxCount);
			   if(maxY > 0.8f) maxY = 0.8;
			   glColor3f(0.0f,0.0f,1.0f);
			   glRectf(minX,minY,maxX,maxY);
		   }
		   glutSwapBuffers();
	   }
}
*/