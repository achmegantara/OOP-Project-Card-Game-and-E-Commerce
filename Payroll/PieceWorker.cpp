#include <iostream>
using namespace std;

#include "PieceWorker.h"

PieceWorker::PieceWorker(const string &first, const string &last, const string &ssn, double pieceWage, double pieceWorked)
: Employee(first, last, ssn)
{
	setWage(pieceWage);
	setPieces(pieceWorked);
}

void PieceWorker::setWage(double pieceWage)
{ wage = (pieceWage < 0.0 ? 0.0:pieceWage); }

double PieceWorker::getWage() const
{ return wage; }

void PieceWorker::setPieces(double pieceWorked)
{ pieces = (pieces < 0.0?0.0:pieceWorked); }

double PieceWorker::getPieces() const
{	return pieces; }

double PieceWorker::earnings() const
{ return getWage()*getPieces(); }

void PieceWorker::print() const
{
	cout << "Piece worker : ";
	Employee::print();
	cout << "Piece wage : " << getWage() << "; piece produced: " << getPieces() << endl;
}
