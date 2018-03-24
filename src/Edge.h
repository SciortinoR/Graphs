/*
 *
 *  	Due March 26th
 *      Authors: Roberto Sciortino, Alessandro Petrangelo
 *      ID: 40069658, 40061555
 *      Assignment 4 COEN 244
 */

#ifndef EDGE_H_
#define EDGE_H_

#include "Vertex.h"

class Edge
{
private:

	int weight, id;
	Vertex start, end;

public:

	//constructors/destructor
	Edge();
	Edge(int, int, const Vertex&, const Vertex&);
	Edge (const Edge&);
	~Edge();

	//set/get functions
	void setWeight(int);
	void setStart(const Vertex&);
	void setEnd(const Vertex&);
	void setID(int);
	int getID() const;
	int getWeight() const;
	Vertex getStart() const;
	Vertex getEnd() const;

	//overload == operator
	bool operator==(const Edge&) const;
};

#endif /* EDGE_H_ */
