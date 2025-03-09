/*
 1. Vytvoøte tøídu Student, která bude obsahovat jméno a pøíjmení studenta a dále pole
známek, kde každé místo v poli reprezentuje známku na vysvìdèení z jednoho pøedmìt.
Index 0 bude tøeba matematika, Index 1 angliètina atd. Který pøedmìt je na kterém
indexu nezáleží. Poèet pøedmìtù si urèete sami.

2. Vytvoøte tøídu Classroom, která reprezentuje tøídu studentù ve škole. Tøída Classroom
bude obsahovat pole objektù Student. Tøída bude obsahovat jednu hlavní metodu
printStudentsWithScholarship, která vypíše do konzole jména studentù, kteøí mají
nárok na stipendium. Nárok mají ti, kteøí mají prùmìrnou známku ze všech pøedmìtù
dohromady menší než 1,7 a nemají ani jednou horší známku než 2.

Dobrovolný úkol pro ty, co se nudí:
Každý pøedmìt nebude reprezentován jednou známkou, ale polem známek, ze kterých se
výsledná známka na vysvìdèení vypoèítá a poté opìt vyberte studenty se stipendiem. Poèet
známek, které student mùže maximálnì dostat za pololetí, nebo-li kapacitu pole známek, si
urèete sami. U reprezentace známek pro jeden pøedmìt se snažte uvažovat objektovì.
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
