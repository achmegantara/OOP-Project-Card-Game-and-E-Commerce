#ifndef PIECE_H
#define PIECE_H

#include "Employee.h"

class PieceWorker : public Employee{
	public:
		PieceWorker(const string &, const string &, const string &, double = 0.0, double = 0.0);
		
		void setWage(double);
		double getWage() const;
		
		void setPieces(double);
		double getPieces() const;
		
		virtual double earnings() const;
		virtual void print() const;
		
	private:
		double wage;
		double pieces;

};

#endif
