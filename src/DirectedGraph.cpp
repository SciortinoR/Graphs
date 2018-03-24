/*
 *
 *  	Due March 26th
 *      Authors: Roberto Sciortino, Alessandro Petrangelo
 *      ID: 40069658, 40061555
 *      Assignment 4 COEN 244
 */

#include<iostream>
#include <string>
#include <vector>
#include <stack>
#include "DirectedGraph.h"

using namespace std;

//default constructor
DirectedGraph::DirectedGraph() : Graph()
{
}

//destructor
DirectedGraph::~DirectedGraph()
{
}

//adds one vertex to graph
bool DirectedGraph::addVertex(Vertex& v)
{
	unsigned int size = vSet.size();
	vSet.push_back(v);

	try
	{
		if (vSet.size() != (++size))
			throw "Vertex not added correctly";
		cout<<"Vertex Added!"<<endl;
		return true;
	}
	catch(char* str)
	{
		cout<<"Exception: "<<str<<endl;
		return false;
	}
}

//adds in a set of vertices to graph
bool DirectedGraph::addVertices(vector<Vertex> v)
{
	unsigned int size = vSet.size();

	for (unsigned int i=0; i<v.size(); i++)
	{
		vSet.push_back(v[i]);
		size++;
	}

	try
	{
		if (vSet.size() != (size))
			throw "Vertices not added correctly";
		cout<<"Vertices Added!"<<endl;
		return true;
	}
	catch(char* str)
	{
		cout<<"Exception: "<<str<<endl;
		return false;
	}
}

//removes one vertex
bool DirectedGraph::removeVertex(Vertex& v)
{
	unsigned int size = vSet.size();

	//removes vertex and corresponding edges
	for (unsigned int i=0; i<vSet.size(); i++)
		if (vSet[i] == v)
		{
			vSet.erase(vSet.begin()+i);
			for (unsigned int j=0; j<eSet.size(); j++)	//removes corresponding edge
				if ((v == eSet[j].getStart()) || (v == eSet[j].getEnd()))
					eSet.erase(eSet.begin()+j);
			break;
		}
	try
	{
		if (vSet.size() != (--size))
			throw "Vertex not removed correctly";
		cout<<"Vertex Removed!"<<endl;
		return true;
	}
	catch(char* str)
	{
		cout<<"Exception: "<<str<<endl;
		return false;
	}
}

//adds one edge to graph
bool DirectedGraph::addEdge(Edge& e)
{
	unsigned int size = eSet.size();

	//checks if vertices of edge are in graph to validate addition of edge
	for (unsigned int i=0; i<vSet.size(); i++)
		if (e.getStart() == vSet[i])
		{
			for (unsigned int j=0; j<vSet.size(); j++)	//adds edge
				if (e.getEnd() == vSet[j])
				{
					eSet.push_back(e);
					break;
				}
			break;
		}
	try
	{
		if (eSet.size() != (++size))
			throw "Edge not added correctly";
		cout<<"Edge Added!"<<endl;
		return true;
	}
	catch(char* str)
	{
		cout<<"Exception: "<<str<<endl;
		return false;
	}
}

//removed multiple Edges from graph
bool DirectedGraph::removeEdges(vector<Edge> e)
{
	unsigned int size = eSet.size();

	//removes edges, corresponding nodes not removed from graph for future addition of edges
	for (unsigned int j=0; j<e.size(); j++)
		for (unsigned int i=0; i<eSet.size(); i++)
			if (eSet[i] == e[j])
			{
				eSet.erase(eSet.begin()+i);
				size--;
				break;
			}
	try
	{
		if (eSet.size() != (size))
			throw "Edges not removed correctly";
		cout<<"Edges Removed!"<<endl;
		return true;
	}
	catch(char* str)
	{
		cout<<"Exception: "<<str<<endl;
		return false;
	}
}

//removes single edge from graph
bool DirectedGraph::remove(Edge& e)
{
	try
	{
		for (unsigned int i=0; i<eSet.size(); i++)
			if (eSet[i] == e)
			{
				eSet.erase(eSet.begin()+i);
				cout<<"Edge Removed!"<<endl;
				return true;
			}
		return false;
		throw "Edge not found in graph";
	}
	catch (char* str)
	{
		cout<<"Exception: "<<str<<endl;
		return false;
	}
}

//searches for a vertex in graph
bool DirectedGraph::searchVertex(const Vertex& v)
{
	for (unsigned int i=0; i<vSet.size(); i++)
		if (vSet[i] == v)
		{
			cout<<"Vertex Found!"<<endl;
			return true;
		}
	cout<<"Vertex Not Found!"<<endl;
	return false;
}

//search edge in graph
bool DirectedGraph::searchEdge(const Edge& e)
{
	for (unsigned int i=0; i<eSet.size(); i++)
		if (eSet[i] == e)
		{
			cout<<"Edge Found!"<<endl;
			return true;
		}
	cout<<"Edge Not Found!"<<endl;
	return false;
}

//displays path starting from specific vertex
void DirectedGraph::display(const Vertex& v)
{
	string path;					//corresponding path output
	vector<int> visited;			//visited node vector
	stack<Vertex> AdjacentList;		//Adjacent node stack

	AdjacentList.push(v);

	do
	{
		unsigned int size = AdjacentList.size();			//size of stack
		static int pushCounter = 0;							//if >1 path for node, push counter increments
		static int visitCounter = 0;						//if >1 path for node, visited counter increments
		int topID = AdjacentList.top().getID();				//ID of top of stack

		for (unsigned int i=0; i<visited.size(); i++)
			if (topID == visited[i])
			{
				AdjacentList.pop();		//removes node from stack if visited
				break;
			}

		if (size == AdjacentList.size())	//if node not removed from stack
		{
			//adds node to path string
			path = path + to_string(topID);
			path.push_back('-');
			path.push_back('>');

			if (visitCounter == 0)				//if multiple paths, visitedCounter>0, then node will not be flagged as visited yet
				visited.push_back(topID);		//if one path, node flagged as visited
			else
			{
				AdjacentList.pop();				//if multiple paths, remove node from stack
				size = AdjacentList.size();
			}

			//gets adjacent nodes adds to stack
			for (unsigned int i=0; i<eSet.size(); i++)
				if (topID == eSet[i].getStart().getID())
				{
					int flag = 0;
					for (unsigned int j=0; j<visited.size(); j++)		//checks if adjacent node already visited
						if (eSet[i].getEnd().getID() == visited[j])
						{
							flag++;
							break;
						}
					if (flag == 0)
					{
						AdjacentList.push(eSet[i].getEnd());		//adds adjacent node to stack
						pushCounter++;
					}
				}

			if (size == AdjacentList.size())			//if no adjacent nodes added, then end of path
				pushCounter = 0;
			if (pushCounter>1)							//if more than one adjacent node added (multiple paths)
				visitCounter++;
		}
		else
			continue;

		if (path.length() > 3)			//prevents printing of node that has no path
			if ((pushCounter == 0)||(AdjacentList.size() == 0))
			{
				path.pop_back();
				path.pop_back();
				path.push_back(';');
				cout<<path<<endl;

				for (int i=0; i<(visitCounter+(2*visitCounter))-1; i++)		//removes pointer characters for specific path
					path.pop_back();
				visitCounter = 0;			//reset counter for next path
			}
	}
	while(AdjacentList.size() != 0);
}

//displays path starting with specific edge
void DirectedGraph::display(Edge& e)
{
	vector<int> visited;			//visited node vector
	stack<Vertex> AdjacentList;		//Adjacent node stack

	//Initializing path with edge startign vertex
	string path = to_string(e.getStart().getID());
	path.push_back('-');
	path.push_back('>');

	visited.push_back(e.getStart().getID());		//stores initial start as visited
	AdjacentList.push(e.getEnd());					//pushes back end vertex of edge in stack to start path output

	do
	{
		unsigned int size = AdjacentList.size();			//size of stack
		static int pushCounter = 0;							//if >1 path for node, push counter increments
		static int visitCounter = 0;						//if >1 path for node, visited counter increments
		int topID = AdjacentList.top().getID();				//ID of top of stack

		for (unsigned int i=0; i<visited.size(); i++)
			if (topID == visited[i])
			{
				AdjacentList.pop();		//removes node from stack if visited
				break;
			}

		if (size == AdjacentList.size())	//if node not removed from stack
		{
			//adds node to path string
			path = path + to_string(topID);
			path.push_back('-');
			path.push_back('>');

			if (visitCounter == 0)				//if multiple paths, visitedCounter>0, then node will not be flagged as visited yet
				visited.push_back(topID);		//if one path, node flagged as visited
			else
			{
				AdjacentList.pop();				//if multiple paths, remove node from stack
				size = AdjacentList.size();
			}

			//gets adjacent nodes adds to stack
			for (unsigned int i=0; i<eSet.size(); i++)
				if (topID == eSet[i].getStart().getID())
				{
					int flag = 0;
					for (unsigned int j=0; j<visited.size(); j++)		//checks if adjacent node already visited
						if (eSet[i].getEnd().getID() == visited[j])
						{
							flag++;
							break;
							}
						if (flag == 0)
						{
							AdjacentList.push(eSet[i].getEnd());		//adds adjacent node to stack
							pushCounter++;
						}
				}

			if (size == AdjacentList.size())			//if no adjacent nodes added, then end of path
				pushCounter = 0;
			if (pushCounter>1)							//if more than one adjacent node added (multiple paths)
				visitCounter++;
		}
		else
			continue;

		if (path.length() > 3)			//prevents printing of node that has no path
			if ((pushCounter == 0)||(AdjacentList.size() == 0))
			{
				path.pop_back();
				path.pop_back();
				path.push_back(';');
				cout<<path<<endl;

				for (int i=0; i<(visitCounter+(2*visitCounter))-1; i++)		//removes pointer characters for specific path
					path.pop_back();
				visitCounter = 0;			//reset counter for next path
			}
	}
	while(AdjacentList.size() != 0);
}

//displays the whole graph in terms of edges with starting/ending vertex ID and edge weight
void DirectedGraph::display() const
{
	cout<<endl<<"Graph Info: "<<endl;
	for (unsigned int i=0; i<eSet.size(); i++)
	{
		cout<<"Edge "<<eSet[i].getID()<<":"<<endl;
		cout<<"Weight: "<<eSet[i].getWeight()<<endl;
		cout<<"Starting Vertex ID - Value: "<<eSet[i].getStart().getID()<<" - "<<eSet[i].getStart().getValue()<<endl;
		cout<<"Ending Vertex ID - Value: "<<eSet[i].getEnd().getID()<<" - "<<eSet[i].getEnd().getValue()<<endl<<endl;
	}
}

//converts graph to string
void DirectedGraph::toString()
{
	cout<<"All Graph Paths: "<<endl;
	for (unsigned int i=0; i<vSet.size(); i++)
		display(vSet[i]);

}

//clears whole graph
bool DirectedGraph::clean()
{
	eSet.clear();
	vSet.clear();

	try
	{
		if ((vSet.size() != 0) && (eSet.size() != 0))
			throw "Not all vertices or edges have been removed";
		cout<<endl<<"Graph Cleared!"<<endl<<endl;
		return true;
	}
	catch (char* str)
	{
		cout<<"Exception: "<<str<<endl;
		return false;
	}
}
