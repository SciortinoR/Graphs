/*
 *
 *  	Due March 26th
 *      Authors: Roberto Sciortino, Alessandro Petrangelo
 *      ID: 40069658, 40061555
 *      Assignment 4 COEN 244
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <string>
#include <vector>
#include "Vertex.h"
#include "Edge.h"

using namespace std;

class Graph
{
	protected:

		vector<Vertex> vSet;
		vector<Edge> eSet;

	public:

		Graph();
		virtual ~Graph();

		//adds one vertex; returns bool if added successfully.
		virtual bool addVertex(Vertex&)=0;

		virtual bool addVertices(vector<Vertex>) = 0;

		//removes a vertex; the edges that have connection with this vertex need to be removed;
		virtual bool removeVertex(Vertex&) = 0;

		//adds an edge; returns true if the edge is added successfully.
		virtual bool addEdge(Edge&) = 0;

		virtual bool removeEdges(vector<Edge>) = 0;

		// remove the edge
		virtual bool remove(Edge&) = 0;

		// returns bool if a vertex exists in a graph.
		virtual bool searchVertex(const Vertex&) = 0;

		// returns bool if an Edge exists in a graph.
		virtual bool searchEdge(const Edge&) = 0;

		// displays the path that contains the vertex.
		virtual void display(const Vertex&) = 0;

		// displays the path that contains the edge.
		virtual void display(Edge&) = 0;

		// displays the whole graph with your own defined format
		virtual void display() const = 0;

		// converts the whole graph to a string such as 1-2-4-5; 1-3-5; each path is separated by ';'
		virtual void toString() = 0;

		//remove all the vertices and edges;
		virtual bool clean() = 0;
};

#endif /* GRAPH_H_ */
