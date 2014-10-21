/*
 * filehandler.h
 *
 *  Created on: 20 Oct 2014
 *      Author: Alex
 */

#ifndef FILEHANDLER_H_
#define FILEHANDLER_H_

typedef int boolean;

size_t getNumberOfLinesInFile(char *fileName);
boolean ignorableCharacter(char c);
void convertFile(char *fileName);
void reverseConvertFile(char *fileName);

#endif /* FILEHANDLER_H_ */
