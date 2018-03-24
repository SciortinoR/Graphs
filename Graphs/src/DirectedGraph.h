/*
 *
 *  	Due March 26th
 *      Authors: Roberto Sciortino, Alessandro Petrangelo
 *      ID: 40069658, 40061555
 *      Assignment 4 COEN 244
 */

#ifndef DIRECTEDGRAPH_H_
#define DIRECTEDGRAPH_H_

#include <string>
#include <vector>
#include "Graph.h"

using namespace std;

class DirectedGraph : public Graph
{
public:

	//constructor/destructor
	DirectedGraph();
	virtual ~DirectedGraph();

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

#endif /* DIRECTEDGRAPH_H_ */
