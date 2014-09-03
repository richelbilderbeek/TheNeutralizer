#ifndef SPATIAL_NEUTRALITY_H
#define SPATIAL_NEUTRALITY_H

namespace gui
{
  ref class Form1; //forward decleration of Form1, saying Form1 exists somewhere else
}


struct color
{
	float r,g,b;
	color(const float& R, const float& G, const float& B);
	color();
};

struct species
{
	int ID;
	int count;
	double fraction;
	color C;
	species();
	species(const double& f);
	bool operator==(const species& other);
};


void display();
void rect();
//void rect_repro();
void dispSim();
void Initialize();
species getSpeciesFromMetaCommunity();
void updateWorld();

//void dispStat();
//void dispMeta();

void findParent_Square(int& otherX, int& otherY, const int& x, const int& y);
void findParent_Circle(int& other_X, int& other_Y, const int& x, const int& y);
//void findParent_Reflect(int& other_X, int& other_Y, const int& x, const int& y);
//void resetReproduction();

void graphMetaCommunity();
void graphLocalCommunity();


int go(gui::Form1^ F);
void stop_simul();
void reset_simulation(gui::Form1^ F);

int octave_sort(long ab_in); //adapted from James






#endif