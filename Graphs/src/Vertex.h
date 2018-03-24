/*
 *
 *  	Due March 26th
 *      Authors: Roberto Sciortino, Alessandro Petrangelo
 *      ID: 40069658, 40061555
 *      Assignment 4 COEN 244
 */

#ifndef VERTEX_H_
#define VERTEX_H_

class Vertex
{
private:

	int ID;
	int value;

public:

	//constructors/destructors
	Vertex();
	Vertex(int, int);
	Vertex(const Vertex&);
	~Vertex();

	//set/get functions
	void setID(int);
	void setValue(int);
	int getID() const;
	int getValue() const;

	//overloaded == operator
	bool operator==(const Vertex&) const;

};

#endif /* VERTEX_H_ */
