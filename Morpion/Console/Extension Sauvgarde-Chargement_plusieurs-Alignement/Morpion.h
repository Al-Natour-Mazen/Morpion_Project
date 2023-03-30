#ifndef MORPION_H
#define MORPION_H
#include <stdbool.h>

#include "Types.h"
#include "Quintuplet.h"
#include "Affichage.h"

//=================== Initialisation ====================//
void initPlateau(Symboles jeu[TAILLEJEU][TAILLEJEU]);
TPlayer initplayer();

//==================== Vérifications ====================//
bool isEmptyCase(Symboles jeu[TAILLEJEU][TAILLEJEU], int posX, int posY);
bool checkVictory(QList l);
int checkWinQuints(QList l);
bool quitKeysAction(char action);
bool continueKeysAction(char action);
bool saveBinaryKeysAction(char action);
bool loadBinaryKeysAction(char action);
bool saveTextKeysAction(char action);
bool loadTextKeysAction(char action);
bool allKeysAction(char action);

//========= Ajout d'une position sur le plateau =========//
Position askPostionHumain(Symboles jeu[TAILLEJEU][TAILLEJEU], TPlayer p, TPlayer otherP, Position* TabPosition, char* instruction);
void askPositionBot(Symboles jeu[TAILLEJEU][TAILLEJEU], Position ChoosenPos, TPlayer p, TPlayer otherP, Position* TabPosition);

//============== Fonctions sur les listes ===============//
QList makeMainList(Position* TabPosition);
QList getAllQuints(Position pos, QList* l);
QList removeClosedQuints(QList l);

//================== Meilleur Position ==================//
Position bestPositionToPlay(QList l, Symboles symbole, int* recupValMax);

//================= Mise à jour valeurs =================//
void majValQunits(Position pos, QList l);
void majValPositions(QList list, Symboles symbole);

//===================== Tour de Jeu =====================//
void tourPlayer(TPlayer* PlayPlayer, TPlayer* WaitPlayer, QList* mainList, Symboles jeu[TAILLEJEU][TAILLEJEU], Position* tabPosition, char* instruction);

//=======================================================//
#endif
