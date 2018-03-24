/*
 *
 *  	Due March 26th
 *      Authors: Roberto Sciortino, Alessandro Petrangelo
 *      ID: 40069658, 40061555
 *      Assignment 4 COEN 244
 */

#include <iostream>
#include <vector>
#include "DirectedGraph.h"
#include "DAG.h"
#include "UndirectedGraph.h"

using namespace std;

int main()
{
	//creating 3 Graphs
	DirectedGraph G1;
	DAG G2;
	UndirectedGraph G3;

	/*Testing Directed Graph First*/
	cout<<"Directed Graph Test:"<<endl<<endl;

	//creating vector of vertices to test addition of array
	vector<Vertex> vArray;
	vArray.push_back(Vertex(0,12));
	vArray.push_back(Vertex(1,424));
	vArray.push_back(Vertex(2,23));
	vArray.push_back(Vertex(3,31));

	//creating one vertex statically to test addition and removal
	Vertex v4(4, 13);

	//creating edges
	Edge e0(32, 0, vArray[2], vArray[0]);
	Edge e1(43, 1, vArray[0], vArray[2]);
	Edge e2(11, 2, vArray[0], vArray[1]);
	Edge e3(435, 3, vArray[1], vArray[2]);
	Edge e4(999, 4, vArray[2], vArray[3]);
	Edge e5(12, 6, vArray[3], vArray[1]);
	Edge e6(57, 7, v4, vArray[1]);

	//creating vector of edges to test removal of array
	vector<Edge> eArray;
	eArray.push_back(Edge(22, 8, vArray[3], vArray[0]));
	eArray.push_back(Edge(11, 9, vArray[3], vArray[2]));

	//adding vertex to graph
	G1.addVertex(v4);

	//add array of vertices to graph
	G1.addVertices(vArray);

	//adds edge to graph
	G1.addEdge(eArray[0]);
	G1.addEdge(eArray[1]);
	G1.addEdge(e0);
	G1.addEdge(e1);
	G1.addEdge(e2);
	G1.addEdge(e3);
	G1.addEdge(e4);
	G1.addEdge(e5);
	G1.addEdge(e6);

	//remove Vertex from graph
	G1.removeVertex(v4);		//removes vertex v4 and edge e6

	//remove multiple edges from graph
	G1.removeEdges(eArray);

	//removes one edge from graph
	G1.remove(e5);

	//searches for vertex
	G1.searchVertex(vArray[0]);
	G1.searchVertex(v4);          //vertex already removed, returns false

	//searches for edge
	G1.searchEdge(e0);
	G1.searchEdge(eArray[0]);    //edge already removed, returns false

	//Displays path from a certain vertex
	cout<<endl<<"Paths from Vertex: "<<vArray[2].getID()<<endl;
	G1.display(vArray[2]);

	//Displays path from a certain edge
	cout<<endl<<"Paths from Edge: "<<e2.getID()<<endl;
	G1.display(e2);

	//displays whole graph in terms of vertex/edge info
	G1.display();

	//prints all graph paths
	G1.toString();

	//clear graph
	G1.clean();

	/*Testing DAG graph second */
	cout<<"Directed Acyclic Graph Test:"<<endl<<endl;

	//Extra vertices for DAG
	Vertex v5(5, 1234);
	Vertex v6(6, 234);
	Vertex v7(7, 122);

	//creating edges for DAG
	Edge e7(32, 0, vArray[0], vArray[2]);
	Edge e8(43, 1, vArray[1], vArray[2]);
	Edge e9(11, 2, vArray[2], vArray[3]);
	Edge e10(435, 3, vArray[2], v4);
	Edge e11(999, 4, vArray[3], v4);
	Edge e12(123, 5, vArray[3], v5);
	Edge e13(1212, 6, vArray[3], vArray[0]);

	//creating vector of edges to test removal of array
	vector<Edge> dagArray;
	dagArray.push_back(Edge(22, 8, v4, v6));
	dagArray.push_back(Edge(11, 9, v7, v4));

	//Add Vertex to DAG
	G2.addVertex(v4);
	G2.addVertex(v5);
	G2.addVertex(v6);
	G2.addVertex(v7);

	//Add vertices to test addition of array to DAG
	G2.addVertices(vArray);

	//Add edges to DAG
	G2.addEdge(dagArray[0]);
	G2.addEdge(dagArray[1]);
	G2.addEdge(e7);
	G2.addEdge(e8);
	G2.addEdge(e9);
	G2.addEdge(e10);
	G2.addEdge(e11);
	G2.addEdge(e12);
	G2.addEdge(e13);		//cant because creates loop in DAG

	//removes vertex
	G2.removeVertex(v5);		//also removes edge e12

	//remove multiple edges from DAG
	G2.removeEdges(dagArray);

	//remove one edge from DAG
	G2.remove(e11);

	//searches for vertex
	G2.searchVertex(vArray[0]);
	G2.searchVertex(v5);          //vertex already removed, returns false

	//searches for edge
	G2.searchEdge(e7);
	G2.searchEdge(e12);    //edge already removed, returns false

	//Displays path from a certain vertex
	cout<<endl<<"Paths from Vertex: "<<vArray[0].getID()<<endl;
	G2.display(vArray[0]);

	//Displays path from a certain edge
	cout<<endl<<"Paths from Edge: "<<e8.getID()<<endl;
	G2.display(e8);

	//displays whole graph in terms of vertex/edge info
	G2.display();

	//prints all graph paths
	G2.toString();

	//clear graph
	G2.clean();

	/*Testing Undirected Graph (UG) Third, with same graph as DAG but with bidirectional edges */
	cout<<"Undirected Graph Test:"<<endl<<endl;

	//Add Vertex to UG
	G3.addVertex(v4);
	G3.addVertex(v5);
	G3.addVertex(v6);
	G3.addVertex(v7);

	//Add vertices to test addition of array to UG
	G3.addVertices(vArray);

	//Add edges to UG
	G3.addEdge(dagArray[0]);
	G3.addEdge(dagArray[1]);
	G3.addEdge(e7);
	G3.addEdge(e8);
	G3.addEdge(e9);
	G3.addEdge(e10);
	G3.addEdge(e11);
	G3.addEdge(e12);

	//removes vertex
	G3.removeVertex(v5);		//also removes edge e12

	//remove multiple edges from UG
	G3.removeEdges(dagArray);

	//remove one edge from UG
	G3.remove(e11);

	//searches for vertex
	G3.searchVertex(vArray[0]);
	G3.searchVertex(v5);          //vertex already removed, returns false

	//searches for edge
	G3.searchEdge(e7);
	G3.searchEdge(e12);    //edge already removed, returns false

	//Displays path from a certain vertex
	cout<<endl<<"Paths from Vertex: "<<vArray[0].getID()<<endl;
	G3.display(vArray[0]);

	//Displays path from a certain edge
	cout<<endl<<"Paths from Edge: "<<e8.getID()<<endl;
	G3.display(e8);

	//displays whole graph in terms of vertex/edge info
	G3.display();

	//prints all graph paths
	G3.toString();

	//clear graph
	G3.clean();

	return 0;
}
