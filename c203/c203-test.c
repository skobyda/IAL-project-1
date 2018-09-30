
/****************************** c203-test.c ************************************
 * P�edm�t: Algoritmy (IAL) - FIT VUT v Brn�
 * Z�kladn� testy pro p��klad c203.c (Fronta znak� v poli)
 * Vytvo�il: V�clav Topinka, z��� 2005
 * Upravil: Bohuslav K�ena, z��� 2012
 *******************************************************************************
 * V tomto p��kladu jsme pou�ili trochu v�ce angli�tinu ne� obvykle.
 * M�me pro to dva d�vody:
 *  
 * 1) Angli�tina je druh� mate��tina informatika! Bez n� se jako informatici
 * (a v dne�n� dob� nejenom jako informatici) asi jenom t�ko obejdete.
 * Dom�c� �lohy (alespo� z ��sti) v angli�tin� by v�m proto mohli pomoci p�i
 * za�it� tohoto jazyka. Pojmenov�vat identifik�tory anglick�mi term�ny je
 * velice dobr� zvyk - nikdy nev�te, zda V� k�d nebude pozd�ji ��st nebo
 * dokonce upravovat n�kdo, kdo �esky nerozum�. Stejn� tak je u�ite�n� ps�t
 * anglictky i koment��e.
 *  
 * 2) Na FIT p�ij�d�j� zahrani�n� studenti v r�mci projekt� ERASMUS/SOCRATES
 * Aby se podm�nky jejich studia co nejv�ce bl�ily podm�nk�m, kter� maj�
 * studenti studuj�c� v �e�tin�, m�li by zahrani�n� studenti d�lat i stejn�
 * dom�c� �lohy. Jen�e to vy�aduje m�t dom�c� �lohy p�ipraveny v angli�tin�.
 * A udr�ovat konzistenci dvou verz� dom�c�ch �loh (�esk�ch a anglick�ch) 
 * je zna�n� pracn�. P�eveden� dom�c�ch �loh do angli�tiny by tento probl�m
 * elegatn� vy�e�ilo.
 * 
 * Samotn� zad�n� nakonec z�stalo i pro tento p��klad v �e�tin�, aby se nikdo
 * nemohl c�tit po�kozen t�m, �e zad�n� nerozum�l pr�v� kv�li pou�it�
 * nemate�sk�ho jazyka.
 ******************************************************************************/

#include "c203.h"

#include <stdio.h>
#include <stdlib.h>
                                             /* variables used within testing */
tQueue* queue;
int QUEUE_SIZE;
int solved;
int err_flag;

/*******************************************************************************
 * The following functions allow us to write shorter testing code.
 * They usually call particular operation, check whether the function
 * has been implemented, and, eventualy, print a result of the function.
 ******************************************************************************/

void queuePrint ( tQueue* q ) {
/* Prints a queue with the following index meaning:
 * F = Front
 * B = Back
 * E = queue is Empty (F == B)
 */
	putchar('\n');
                                                   /* Prints a queue content. */
	for ( int i=0; i<QUEUE_SIZE; i++ )
		putchar(q->arr[i]);
	putchar('\n');
                                                 /* Prints a queue index(es). */
	for ( int i=0; i<QUEUE_SIZE; i++ ) {
		if ( ( i == q->f_index ) || ( i == q->b_index ) )
			putchar('^');
		else
			putchar(' ');
	}
	putchar('\n');
                                                 /* Prints index(es) meaning. */
	for ( int i=0; i<QUEUE_SIZE; i++ ) {
		if ( (i == q->f_index) && (i==q->b_index))
			putchar('E');
		else if ( i == q->f_index )
			putchar ('F');
		else if ( i == q->b_index )
			putchar ('B');
		else
			putchar (' ');
	}
	putchar('\n');
}

void use_queue_init ( tQueue* q ) {
    solved = 1;
	queueInit( q );
	if ( ! solved )
		printf("Function queueInit has not been implemented.\n");
}

void use_queue_empty ( tQueue* q ) {
    solved = 1;
	int i = queueEmpty( q );
	if ( ! solved )
		printf("Function queueEmpty has not been implemented.\n");
	else
		printf("Function queueEmpty returned '%s'.\n", i ? "TRUE" : "FALSE");
}

void use_queue_full ( tQueue* q ) {
	solved = 1;
	int i = queueFull( q );
	if ( ! solved )
		printf("Function queueFull has not been implemented.\n");
	else
		printf("Fucntion queueFull returned '%s'.\n", i ? "TRUE" : "FALSE");
}

void use_queue_front ( tQueue* q ) {
	solved = 1;
	err_flag = 0;
	char c;
  queueFront( q, &c );
	if ( ! solved )
		printf("Function queueFront has not been implemented.\n");
	else if ( !err_flag )
		printf("Function queueFront returned value '%c'.\n", c );
}

void use_queue_remove ( tQueue* q ) {
	solved = 1;
	queueRemove( q );
	if ( ! solved )
		printf("Function queueRemove has not been implemented.\n");
}

void use_queue_get ( tQueue* q ) {
	solved = 1;
	err_flag = 0;
	char c;
  queueGet( q, &c );
	if ( ! solved )
		printf("Function queueGet has not been implemented.\n");
	else if ( !err_flag )
		printf("Function queueGet returned value '%c'.\n", c );
}

void use_queue_up ( tQueue* q, char c ) {
    solved = 1;
    queueUp( q, c );
    if ( ! solved )
		    printf("Function queueUp has not been implemented.\n");
		return;
}

/*******************************************************************************
 * BASIC TESTS
 * -----------
 * The student earns the first part of the exercise points by passing these
 * basic tests. To earn the rest of points, it is necessary to pass advanced
 * tests which deal with margin situations. We recommend to all students to
 * improve these basic tests in order to find as much bugs in the implementation
 * as possible. Of course, if you are able to write the code without mistakes
 *  you do not need any testing.
 ******************************************************************************/

int main ( int argc, char* argv[] ) {

	printf ("******************************************\n");
	printf ("* C203: Queue implemented using an array *\n");
	printf ("* Basic testing script (c203-test.c)     *\n");
	printf ("******************************************\n");
	printf ("* The explanation:                       *\n");
	printf ("* ~~~~~~~~~~~~~~~~                       *\n");
	printf ("* * - not used yet                       *\n");
	printf ("* F - Front                              *\n");
	printf ("* B - Back                               *\n");
	printf ("* E - Empty (F == B)                     *\n");
	printf ("******************************************\n");

	QUEUE_SIZE = 9;
                                     /* We allocate the memory for the queue. */
    queue = (tQueue*)malloc(sizeof(tQueue));
    if ( queue == NULL ) {
    	printf ("\nc203-test.c: Error: There is not enough memory for the queue.\n");
        return 1;
    }

	printf ("\n[TEST01] queue initialization\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
    use_queue_init( queue );
	queuePrint( queue );

	printf ("\n[TEST02] We try queueEmpty and queueFull over the empty queue.\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_empty( queue );
	use_queue_full( queue );

	printf ("\n[TEST03] queueFront, queueGet, and queueRemove should cause handled errors.\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_front ( queue );
	use_queue_get ( queue );
	use_queue_remove ( queue );
	queuePrint( queue );

	printf ("\n[TEST04] We put 'Ciao!' into the queue using queueUp.\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_up( queue, 'C' );
	use_queue_up( queue, 'i' );
	use_queue_up( queue, 'a' );
	use_queue_up( queue, 'o' );
	use_queue_up( queue, '!' );
	queuePrint( queue );

	printf ("\n[TEST05] Functions queueEmpty as well as queueFull should return FALSE now.\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_empty( queue );
	use_queue_full( queue );
	
	printf ("\n[TEST06] Function queueFront should always return the same value.\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_front( queue );
	use_queue_front( queue );
	queuePrint( queue );
	
	printf ("\n[TEST07] Let's examine the difference between queueRemove and queueGet.\n" );
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_remove( queue );
	use_queue_get( queue );
	queuePrint( queue );
	
	printf ("\n[TEST08] After three queueGet the queue should be empty.\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_get( queue );
	use_queue_get( queue );
	use_queue_get( queue );
	use_queue_empty( queue );
	use_queue_full( queue );
	queuePrint( queue );

                   /* Back index should be at the end of array after test 09. */
	printf ("\n[TEST09] We put 1, 2, and 3 to the queue using QueueUp and check the result.\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_up( queue, '1' );
	use_queue_up( queue, '2' );
	use_queue_up( queue, '3' );
	use_queue_front ( queue );
	use_queue_empty( queue );
	use_queue_full( queue );
	queuePrint( queue );
	
	printf ("\n[TEST10] After removing three elements using queueGet, the queue should be empty.\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_get( queue );
	use_queue_get( queue );
	use_queue_get( queue );
	use_queue_front ( queue );
	use_queue_empty( queue );
	use_queue_full( queue );
	queuePrint( queue);

	printf ("\n[TEST11] Additional queueUp should move to b_index possition 0.\n" );
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_up( queue, '4' );
	use_queue_front ( queue );
	use_queue_empty( queue );
	use_queue_full( queue );
	queuePrint( queue );

	printf ("\n[TEST12] After queueGet, the indexes should be the same as after queueInit.\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_get( queue );
	use_queue_front ( queue );
	use_queue_empty( queue );
	use_queue_full( queue );
	queuePrint( queue);

	printf ("\n[TEST13] We use queueUp eight times to fill up the queue.\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	for ( int i=0; i<8; i++ )
		use_queue_up( queue, 'A'+i );
	use_queue_front ( queue );
	use_queue_empty( queue );
	use_queue_full( queue );
	queuePrint( queue );

	printf ("\n[TEST14] Addition queueUp() should cause hadled error.\n");
	printf ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	use_queue_up( queue, 'Z' );
	use_queue_front ( queue );
	use_queue_empty( queue );
	use_queue_full( queue );
	queuePrint( queue );

	printf ("\n******* The end of Basic Tests (c203-test.c) *******\n");
	free (queue);
	return 0;
}

