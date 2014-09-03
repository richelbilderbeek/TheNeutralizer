#include "stdafx.h"
#include "container.h"
#include <stdlib.h>
#include <vcclr.h>
#include <string>

container::container()
{
  sizeX = 50;
  sizeY = sizeX;
  int Seed = 1;

  m = 1e-3;
  Jm = 1000;
  theta = 5;
  N = (int)(0.1 * sizeX * sizeY);
  speciationRate = 1e-6;
  
  initIndiv = 100;
  L = 1;
  update = 1;
  showAbund = false;
  showGraph = false;
  createdAbundWindow = false;
  createdGraphWindow = false;
  FileName = "lake.bmp";

  imageChosen = false;
  imageRight = false;

  showReproduction = false;

  Pi = 3.14159265358979323846264338327950288419716939937510;
  dispersalType = "Circle";

  size = 1000;
  previousSize = 100;
  isRunning = false;
  isPaused = false;

  graphedMeta = false;

  monoDominance = false;

  turnover = N;

}

bool To_string( System::String^ source, std::string &target )
{
	pin_ptr<const wchar_t> wch = PtrToStringChars( source );
    int len = (( source->Length+1) * 2);
    char *ch = new char[ len ];
    bool result = wcstombs( ch, wch, len ) != -1;
    target = ch;
    delete ch;
    return result;
}