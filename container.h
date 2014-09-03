
#ifndef CONTAINER_H
#define CONTAINER_H

#include <string>
#include "spatial neutrality.h"

struct container
{
public:
  int sizeX;
  int sizeY;
  int Seed;

  double m;
  int Jm;
  double theta;
  double speciationRate;
  int N;
  int initIndiv;
  int L;
  int update;
  char* FileName;
  int size;
  int previousSize;

  bool imageChosen;
  bool imageRight;

  bool showAbund;
  bool showGraph;
  bool showMeta;
  bool createdAbundWindow;
  bool createdGraphWindow;
  bool createdMetaWindow;

  bool graphedMeta;
  bool isRunning;
  bool isPaused;

  int turnover;

  bool showReproduction;
  bool monoDominance;
  double Pi;
  std::string dispersalType;

  gui::Form1^ *FORM;
  
  container();
};


bool To_string( System::String^ source, std::string &target );


#endif