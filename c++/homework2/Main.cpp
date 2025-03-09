/*
 1. Vytvo�te t��du Student, kter� bude obsahovat jm�no a p��jmen� studenta a d�le pole
zn�mek, kde ka�d� m�sto v poli reprezentuje zn�mku na vysv�d�en� z jednoho p�edm�t.
Index 0 bude t�eba matematika, Index 1 angli�tina atd. Kter� p�edm�t je na kter�m
indexu nez�le��. Po�et p�edm�t� si ur�ete sami.

2. Vytvo�te t��du Classroom, kter� reprezentuje t��du student� ve �kole. T��da Classroom
bude obsahovat pole objekt� Student. T��da bude obsahovat jednu hlavn� metodu
printStudentsWithScholarship, kter� vyp�e do konzole jm�na student�, kte�� maj�
n�rok na stipendium. N�rok maj� ti, kte�� maj� pr�m�rnou zn�mku ze v�ech p�edm�t�
dohromady men�� ne� 1,7 a nemaj� ani jednou hor�� zn�mku ne� 2.

Dobrovoln� �kol pro ty, co se nud�:
Ka�d� p�edm�t nebude reprezentov�n jednou zn�mkou, ale polem zn�mek, ze kter�ch se
v�sledn� zn�mka na vysv�d�en� vypo��t� a pot� op�t vyberte studenty se stipendiem. Po�et
zn�mek, kter� student m��e maxim�ln� dostat za pololet�, nebo-li kapacitu pole zn�mek, si
ur�ete sami. U reprezentace zn�mek pro jeden p�edm�t se sna�te uva�ovat objektov�.
 *
 * 
 */


#include "Classroom.h"
using namespace std;
const static double minimalAvg = 1.7;
const static double gradeBound = 2.0;
int main(int argc, char* argv[])
{
	Classroom classroom;

  classroom.addStudent(Student("Student", "Hranicni", {
    {"Matematika", {1, 2, 1, 2, 2, 1, 2}}, 
    {"Programovani", {1, 1, 2, 2, 1}},     
    {"Anglictina", {2, 2, 2, 1, 2, 2, 1}}  
    }));
  classroom.addStudent(Student("Student", "Blbecek", {
      {"Matematika", {5, 5, 5, 5, 5, 5, 5, 5}},
      {"Programovani", {5, 5, 5, 5, 5, 5, 5, 5}},
      {"Anglictina", {5, 5, 5, 5, 5, 5, 5, 5}}
    }));
  classroom.addStudent(Student("Student", "S trojikou", {
      {"Matematika", {1}},
      {"Programovani", {3}},
      {"Anglictina", {1}}
    }));
  classroom.addStudent(Student("Student", "Dokonaly", {
     {"Matematika", {1, 1, 1, 1, 1, 1, 1, 1}},
     {"Programovani", {1, 1, 1, 1, 1, 1}},
     {"Anglictina", {1, 1, 1, 1, 1}}
    }));
  classroom.printStudentsWithScholarship(minimalAvg, gradeBound);
}
