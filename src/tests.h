#ifndef TESTS_H
#define TESTS_H

#include <iostream>

#include "torrent/parsing/data/tbytes.h"
#include "torrent/parsing/data/tstring.h"
#include "torrent/parsing/data/tinteger.h"
#include "torrent/parsing/data/tlist.h"
#include "torrent/parsing/data/tdictionnary.h"

void testString();
std::string testString(std::string bytes);

void testInteger();
int testInteger(std::string bytes);

void testList();
std::string testList(std::string bytes);

void testDictionary();
std::string testDictionary(std::string bytes);

void testTorrentDic();
void testTorrentDic(std::string file);

#endif // TESTS_H
