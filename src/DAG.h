/*
 *
 *  	Due March 26th
 *      Authors: Roberto Sciortino, Alessandro Petrangelo
 *      ID: 40069658, 40061555
 *      Assignment 4 COEN 244
 */

#ifndef DAG_H_
#define DAG_H_

#include <string>
#include <vector>
#include "Graph.h"

using namespace std;

class DAG : public Graph
{
public:

	//constructor/destructor
	DAG();
	virtual ~DAG();

	//member fucntions
	virtual bool addVertex(Vertex&);
	virtual bool addVertices(vector<Vertex>);
	virtual bool removeVertex(Vertex&);
	virtual bool addEdge(Edge&);
	virtual bool removeEdges(vector<Edge>);
	virtual bool remove(Edge&);
	virtual bool searchVertex(const Vertex&);
	virtual bool searchEdge(const Edge&);
	virtual void display(const Vertex&);
	virtual void display(Edge&);
	virtual void display() const;
	virtual void toString();
	virtual bool clean();
};

#endif
