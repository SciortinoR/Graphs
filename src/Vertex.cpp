/*
 *
 *  	Due March 26th
 *      Authors: Roberto Sciortino, Alessandro Petrangelo
 *      ID: 40069658, 40061555
 *      Assignment 4 COEN 244
 */

#include <iostream>
#include "Vertex.h"

//default constructor
Vertex::Vertex()
{
	ID = 0;
	value = 0;
}

//regular constrcutor
Vertex::Vertex(int id, int val)
{
	ID = id;
	value = val;
}

//copy constrcutor
Vertex::Vertex(const Vertex& v)
{
	ID = v.ID;
	value = v.value;
}

//destructor
Vertex::~Vertex()
{
}

//set ID
void Vertex::setID(int id)
{
	ID = id;
}

//set value
void Vertex::setValue(int val)
{
	value = val;
}

//get ID
int Vertex::getID() const
{
	return ID;
}

//get Value
int Vertex::getValue() const
{
	return value;
}

//overload == operaator
bool Vertex::operator==(const Vertex& v) const
{
	return (ID == v.ID);
}
