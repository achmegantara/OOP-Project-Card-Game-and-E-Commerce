 #include <iostream>
using namespace std;

 #include <iomanip>

 #include <vector>

 // include definitions of classes in Employee hierarchy
 #include "Employee.h"
 #include "SalariedEmployee.h"
 #include "HourlyWorker.h"
 #include "CommissionEmployee.h"
 #include "BasePlusCommissionEmployee.h"
 #include "PieceWorker.h"
 
 #include "Employee.cpp"
 #include "SalariedEmployee.cpp"
 #include "HourlyWorker.cpp"
 #include "CommissionEmploye.cpp"
 #include "BasePlusCommissionEmployee.cpp"
 #include "PieceWorker.cpp"

 void virtualViaPointer( const Employee * const ); // prototype
 void virtualViaReference( const Employee & ); // prototype

 int main()
 {
 // set floating-point output formatting
 cout << fixed << setprecision( 2 );

 // create derived-class objects
 SalariedEmployee salariedEmployee("John", "Smith", "111-11-1111", 800 );
 HourlyEmployee hourlyEmployee("Karen", "Price", "222-22-2222", 16.75, 40 );
 CommissionEmployee commissionEmployee("Sue", "Jones", "333-33-3333", 10000, .06 );
 BasePlusCommissionEmployee basePlusCommissionEmployee("Achmad", "Akbar", "444-44-4444", 5000, .04, 300 );
 PieceWorker pieceWorker("Achmad", "Megantara", "555-55-5555", 20000, 500);

 cout << endl;
 cout << "Employees processed individually using static binding: " << endl;

 // output each Employee's information and earnings using static binding
 salariedEmployee.print();
 cout << "earned $" << salariedEmployee.earnings() << " " << endl;
 cout << endl;
 
 hourlyEmployee.print();
 cout << "earned $" << hourlyEmployee.earnings() << " ";
 cout << endl;
 
 cout <<endl;
 commissionEmployee.print();
 cout << "earned $" << commissionEmployee.earnings() << " ";
 cout << endl;
 
 cout << endl;
 basePlusCommissionEmployee.print();
 cout << "earned $" << basePlusCommissionEmployee.earnings() << " ";
 cout << endl;
 
 cout << endl;
 pieceWorker.print();
 cout << "earned $" << pieceWorker.earnings() <<" ";

cout << "\n----------------------------------------------------" << endl;
 // create vector of four base-class pointers
 vector < Employee * > employees( 4 ); 

 // initialize vector with Employees 
 employees[ 0 ] = &salariedEmployee; 
 employees[ 1 ] = &hourlyEmployee; 
 employees[ 2 ] = &commissionEmployee; 
 employees[ 3 ] = &basePlusCommissionEmployee;
 employees[ 4 ] = &pieceWorker;

 cout << "Employees processed polymorphically via dynamic binding: " << endl;
 cout << "Virtual function calls made off base-class pointers: " << endl;

 for ( size_t i = 0; i < employees.size(); i++ )
  virtualViaPointer( employees[ i ] ); 

 cout << "Virtual function calls made off base-class references: ";

 for ( size_t i = 0; i < employees.size(); i++ ) 
  virtualViaReference( *employees[ i ] ); // note dereferencing

 return 0;
 } // end main

 void virtualViaPointer( const Employee * const baseClassPtr ) 
 { 
  baseClassPtr->print(); 
  cout << "earned $" << baseClassPtr->earnings() << " " <<endl;;
 } 

 void virtualViaReference( const Employee &baseClassRef ) 
 { 
  baseClassRef.print();  
  cout << "earned $" << baseClassRef.earnings() << " " << endl;
 } 
