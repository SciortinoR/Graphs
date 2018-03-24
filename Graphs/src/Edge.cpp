/*
 *
 *  	Due March 26th
 *      Authors: Roberto Sciortino, Alessandro Petrangelo
 *      ID: 40069658, 40061555
 *      Assignment 4 COEN 244
 */

#include <iostream>
#include "Edge.h"

//default constructor
Edge::Edge()
{
	weight = 0;
	id = 0;
}

//regular constructor
Edge::Edge(int w, int i, const Vertex& v1, const Vertex& v2) : start(v1), end(v2)
{
	weight = w;
	id = i;
}

//copy constructor
Edge::Edge(const Edge& e)
{
	weight = e.weight;
	id = e.id;
	start = e.start;
	end = e.end;
}

//destructor
Edge::~Edge()
{
}

//set weight
void Edge::setWeight(int w)
{
	weight = w;
}

//set starting vertex
void Edge::setStart(const Vertex& v1)
{
	start = v1;
}

//set ending vertex
void Edge::setEnd(const Vertex& v2)
{
	end = v2;
}

//get weight
int Edge::getWeight() const
{
	return weight;
}

//gets starting vertex
Vertex Edge::getStart() const
{
	return start;
}

//gets ending vertex
Vertex Edge::getEnd() const
{
	return end;
}

//sets id
void Edge::setID(int i)
{
	id = i;
}

//gets id
int Edge::getID() const
{
	return id;
}

//overloading == operator
bool Edge::operator==(const Edge& e) const
{
	return ((start == e.start) && (end == e.end));
}
