#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>

typedef unsigned long long myDataType;  // Ορίστε ένα custom data type (myDataType) τύπου unsigned long long. //


//------- initialize the functions---------

void initialize_array (myDataType*, int , myDataType);
void print_bytes(myDataType*, int);
void print_array(myDataType*, int);
int compare_arrays(myDataType*, myDataType*, int);

// Part A //


//------- This is the main function ------------

int main (int argc, char **argv) {
	/*
	b) Στη main, δημιουργήστε δύο μονοδιάστατα arrays τύπου myDataType με ίδιο μέγεθος που
	ορίζεται απο μια τιμή που δίνει ο χρήστης κατά την εκτέλεση του προγραμμάτος.
	πχ.: ./myProgram 10
	*/
	if (argc==2) { //εαν ο χρηστης δωσει ενα argument το προγραμμα θα τρεξει το πρωτο μερος
		printf("=================================== \n Here starts the first part \n=================================== \n");

		int size=atoi(argv[1]);  //size ο αριθμος γραμμων
		myDataType value=0;  // θετω τη τιμη value ιση με το μηδεν οποως οριζει η ασκηση
		myDataType array1[size], array2[size];  // δηλωνω τα 2 array τυπου myDataType
	
		initialize_array(array1, size, value);  //αρχικοποιω το πρωτο array
		initialize_array(array2, size, value);	//αρχικοποιω το δευτερο array
		printf("Printing the bytes of a random element of the array: \n");
		print_bytes(array1, size);  //καλω τη συναρτηση που εκτυπωνει ενα τυχαιο στοιχειο του πρωτου array
		printf("Printing the first array: \n");
		print_array(array1, size); //καλω τη συναρτηση για να εκτυπωσω ολο το πρωτο array στοιχειο-στοιχειο
		printf("Printing the second array: \n");
		print_array(array2, size); //καλω τη συναρτηση για να εκτυπωσω ολο το δευτερο array στοιχειο-στοιχειο
	
		if (compare_arrays(array1, array2, size)==1) {  //συγκρινω τα 2 arrays καλωντας τη συναρτηση compare_arrays
			printf("Arrays are equal \n");	
		}
		else {
			printf("Arrays are not equal \n");
		}
	}
	else {
	// Here starts the second part if given 3 arguments
	
		if (argc==4) {
			
			printf("=================================== \n Here starts the second part \n=================================== \n");
			
			int counter, rows1=atoi(argv[1]), rows2=atoi(argv[2]), columns=atoi(argv[3]), b=0, c=0, d=0,e=0;
			myDataType matrix1[rows1][columns],matrix2[rows2][columns];
		
		// αρχικοποιω τον πρωτο πινακα με διαστασεις row1 x columns
			for (b=0; b<rows1; b++) {
				initialize_array(matrix1[b], columns, b );
				//print_array(matrix1[b],10);
			}
		// αρχικοποιω τον δευτερο πινακα με διαστασεις row2 x columns
			for (c=0; c<rows2; c++) {
				initialize_array(matrix2[c], columns, c );
				//print_array(matrix2[c],columns);
			}
		// συγκρινω καθε γραμμη του πρωτο πινακα με ολες τις γραμμες του δευτερου πινακα μεσω της συναρτησης compare_arrays
			for (d=0; d<rows1; d++) {
				counter=0;
				for (e=0; e<rows2; e++) {
					if (compare_arrays(matrix1[d], matrix2[e], columns)==1) {
						counter++;	
						}
					}
				printf("Found row %d of first matrix %d times in the second matrix \n",d,counter );
		
				}
			}
		else {
			printf("This program needs 1 or 3 arguments for 1d and 2d matrices respectively \n");
		}
	
	
	}
	
	
}

//---------- function implemantation -----------

/*
c) Φτιάξτε ένα function το οποίο αρχικοποιεί ένα array μεταβλητού μεγέθους δίνοντας σε κάθε
στοιχείο του array μια τιμή την οποία δέχεται ως όρισμα.
*/

void initialize_array (myDataType* array, int size, myDataType value) {
	// This function assigns the argument "value" to an array with a specific size
	int i;
	for (i=0; i<size; i++) {
		array[i]=value;		
	}	
}

/*
δ) Δημιουργήστε ένα function το οποίο εκτυπώνει στην οθόνη το μέγεθος ενός στοιχείου
τύπου myDataType σε bytes. Kάντε κλήση της συνάρτησης για ένα τυχαίο στοιχείο σε ένα
απο τα arrays.
*/
		

void print_bytes(myDataType* array, int size) {
	//This function selects a random number between 0 and the size number and retrns the 
	//size of the element in the array on this randm position
	srand(time(NULL));
	int r = rand() % size;
	printf("The size of the element %llu in position %d is %lu bytes \n", array[r],r,sizeof(array[r]));
	
}

/*
Γράψτε ένα function το οποίο εκτυπώνει στην οθονή όλα τα στοιχεία ενός array που δέχεται
ως όρισμα. Καλέστε την και εκτυπώστε τα στοιχεία και των δύο arrays
*/

void print_array(myDataType* array, int size) {
	//This function prints an one-dimensional array with a specific size
	int q;
	for (q=0; q<size; q++) {
		printf("The element of the position %d is %llu \n",q,array[q]);	
	}	
}

/*
Τέλος, γράψτε ένα τέταρτο function το οποίο δέχεται ως ορίσματα δύο arrays, τα συγκρίνει
στοιχείο προς στοιχείο και επιστρέφει 1 αν τα arrays είναι ίδια ή 0 αν διαφέρουν. Καλέστε
το function στην main και εκτυπώστε το αποτέλεσμα στην οθόνη.
*/
		
int compare_arrays(myDataType* array1, myDataType* array2, int size) {
	int i;
	for (i=0; i<size; i++) {
		if (array1[i]!=array2[i]) {
			return 0; //the first non equal pair returns 1 since the arrays are not identical thus there is no need to continue
		}
	}
	return 1;
}
