#ifndef REPLACE_H
#define REPLACE_H
#include <iostream>
#include <fstream>
#include <string>

void errorCheck(std::ifstream &file,char **argv);
void readAndCreateFile(std::ifstream &file, char **argv);

#endif