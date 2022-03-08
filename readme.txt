Task1:
Pentru decodificare am creat un vector care sa retina pe fiecare pozitie bitii numarului dat.

Task2:
- trebuie sa avem un numar de operanzi egal cu numarul de semne + 1;
- cu ajutorul unei masti gasim bitii 1 ce formeaza un nou operand si il transformam din baza 2 in baza 10;
- cum dim (dimensiunea) este o putere a lui 2, putem imparti fiecare numar citit in parti egale ce formeaza noii operanzi;

Task3:
Modificari pentru obtinerea operanzilor:
- pentru a obtine operanzi de dimensiunea dim, fara a distruge variabila, cream dim2, cu aceeasi functionalitate;
- la terminarea formarii unui nou operand reinitializam dim2 si cream un nou operand in vectorul op[];
- cand terminam de verificat bitii de 1 (mask=0) dintr-un numar, trecem la urmatorul numar si reinitializam masca;

Task 4:
Calculam operatiile prioritare: * si / astfel:
- in termenul cel mai din stanga vom pune rezultatul final al unei secvente formate doar din / si *;
- ceilalti termeni vor fi 1 (elementul neutru la inmultire si impartire);
- operatiile se pot realiza la fel ca la celelalte subpuncte cu aceste modificari. 
