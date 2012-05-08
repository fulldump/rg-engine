#include <vcl.h>
#pragma hdrstop

#include "EventHouse.h"
#pragma package(smart_init)

EventHouse::EventHouse() {
    _encendida = false;
    _cerrada = true;
}

void EventHouse::top(ViewPort3D *_viewport, Scene3D *_scene) {
        _house = new Group3D();

        //_house->rotation->z = 180;

        // Introduzco las 6 columnas

        Color3D *color_columnas = new Color3D(0,1,1);
        Box3D *col;

        col = new Box3D(); // Columna 1
        col->color = color_columnas;
        col->x = 30;    col->y = 30;    col->z = 250;
        col->translation->x = 0;        col->translation->y = 0;
        col->RecalculateMesh();        _house->elements->push_back(col);

        col = new Box3D(); // Columna 2
        col->color = color_columnas;
        col->x = 30;    col->y = 30;    col->z = 250;
        col->translation->x = 430;        col->translation->y = 0;
        col->RecalculateMesh();        _house->elements->push_back(col);

        col = new Box3D(); // Columna 3
        col->color = color_columnas;
        col->x = 30;    col->y = 30;    col->z = 250;
        col->translation->x = 860;        col->translation->y = 0;
        col->RecalculateMesh();        _house->elements->push_back(col);

        col = new Box3D(); // Columna 4
        col->color = color_columnas;
        col->x = 30;    col->y = 30;    col->z = 250;
        col->translation->x = 0;        col->translation->y = 430;
        col->RecalculateMesh();        _house->elements->push_back(col);

        col = new Box3D(); // Columna 5
        col->color = color_columnas;
        col->x = 30;    col->y = 30;    col->z = 250;
        col->translation->x = 430;        col->translation->y = 430;
        col->RecalculateMesh();        _house->elements->push_back(col);

        col = new Box3D(); // Columna 6
        col->color = color_columnas;
        col->x = 30;    col->y = 30;    col->z = 250;
        col->translation->x = 860;        col->translation->y = 430;
        col->RecalculateMesh();        _house->elements->push_back(col);


        // Introduzco las paredes lisas

        Color3D *color_paredes = new Color3D(0,0,0.8);
        Box3D *wall;

        /*wall = new Box3D(); // Pared 1
        wall->color = color_paredes;
        wall->x = 400;  wall->y = 10; wall->z = 250;
        wall->translation->x = 30;
        wall->translation->y = 0;
        wall->RecalculateMesh();
        _house->elements->push_back(wall);*/

        wall = new Box3D(); // Pared 1  parte derecha
        wall->color = color_paredes;
        wall->x = 170;  wall->y = 10; wall->z = 250;
        wall->translation->x = 30;
        wall->translation->y = 0;
        wall->RecalculateMesh();
        _house->elements->push_back(wall);

        wall = new Box3D(); // Pared 1 parte izquierda
        wall->color = color_paredes;
        wall->x = 170;  wall->y = 10; wall->z = 250;
        wall->translation->x = 260;
        wall->translation->y = 0;
        wall->RecalculateMesh();
        _house->elements->push_back(wall);

        wall = new Box3D(); // Pared 1 parte inferior
        wall->color = color_paredes;
        wall->x = 60;  wall->y = 10; wall->z = 95;
        wall->translation->x = 200;
        wall->translation->y = 0;
        wall->RecalculateMesh();
        _house->elements->push_back(wall);

        wall = new Box3D(); // Pared 1 parte superior
        wall->color = color_paredes;
        wall->x = 60;  wall->y = 10; wall->z = 95;
        wall->translation->x = 200;
        wall->translation->z = 155;
        wall->RecalculateMesh();
        _house->elements->push_back(wall);

        /*wall = new Box3D(); // Pared 2
        wall->color = color_paredes;
        wall->x = 400;  wall->y = 10; wall->z = 250;
        wall->translation->x = 460;
        wall->translation->y = 0;
        wall->RecalculateMesh();
        _house->elements->push_back(wall);*/

        wall = new Box3D(); // Pared 2  parte izquierda
        wall->color = color_paredes;
        wall->x = 170;  wall->y = 10; wall->z = 250;
        wall->translation->x = 460;
        wall->translation->y = 0;
        wall->RecalculateMesh();
        _house->elements->push_back(wall);

        wall = new Box3D(); // Pared 2 parte derecha
        wall->color = color_paredes;
        wall->x = 170;  wall->y = 10; wall->z = 250;
        wall->translation->x = 690;
        wall->translation->y = 0;
        wall->RecalculateMesh();
        _house->elements->push_back(wall);

        wall = new Box3D(); // Pared 2  parte inferior
        wall->color = color_paredes;
        wall->x = 60;  wall->y = 10; wall->z = 95;
        wall->translation->x = 630;
        wall->translation->y = 0;
        wall->RecalculateMesh();
        _house->elements->push_back(wall);

        wall = new Box3D(); // Pared 2 derecha
        wall->color = color_paredes;
        wall->x = 60;  wall->y = 10; wall->z = 95;
        wall->translation->x = 630;
        wall->translation->z = 155;
        wall->RecalculateMesh();
        _house->elements->push_back(wall);

        wall = new Box3D(); // Pared 3
        wall->color = color_paredes;
        wall->x = 10;  wall->y = 400; wall->z = 250;
        wall->translation->x = 0;
        wall->translation->y = 30;
        wall->RecalculateMesh();
        _house->elements->push_back(wall);

        wall = new Box3D(); // Pared 4
        wall->color = color_paredes;
        wall->x = 400;  wall->y = 10; wall->z = 250;
        wall->translation->x = 30;
        wall->translation->y = 450;
        wall->RecalculateMesh();
        //_house->elements->push_back(wall);

        //Introduzco las paredes especiales
        wall = new Box3D(); // Pared 5
        wall->color = color_paredes;
        wall->x = 400;  wall->y = 10; wall->z = 250;
        wall->translation->x = 460;
        wall->translation->y = 450;
        wall->RecalculateMesh();
        //_house->elements->push_back(wall);

        wall = new Box3D(); // Pared 6
        wall->color = color_paredes;
        wall->x = 10;  wall->y = 400; wall->z = 250;
        wall->translation->x = 880;
        wall->translation->y = 30;
        wall->RecalculateMesh();
        _house->elements->push_back(wall);

        /*wall = new Box3D(); // Pared 7
        wall->color = color_paredes;
        wall->x = 10;  wall->y = 400; wall->z = 250;
        wall->translation->x = 440;
        wall->translation->y = 30;
        wall->RecalculateMesh();
        _house->elements->push_back(wall);*/

        wall = new Box3D(); // Pared 7   parte izquierda
        wall->color = color_paredes;
        wall->x = 10;  wall->y = 160; wall->z = 250;
        wall->translation->x = 440;
        wall->translation->y = 30;
        wall->RecalculateMesh();
        _house->elements->push_back(wall);

        wall = new Box3D(); // Pared 7   parte derecha
        wall->color = color_paredes;
        wall->x = 10;  wall->y = 160; wall->z = 250;
        wall->translation->x = 440;
        wall->translation->y = 270;
        wall->RecalculateMesh();
        _house->elements->push_back(wall);

        wall = new Box3D(); // Pared 7   parte superior
        wall->color = color_paredes;
        wall->x = 10;  wall->y = 80; wall->z = 70;
        wall->translation->x = 440;
        wall->translation->y = 190;
        wall->translation->z = 180;
        wall->RecalculateMesh();
        _house->elements->push_back(wall);


        ////////////////////////////////////////////////////////////////////////
        //                    HABITACI�N DE LA IZQUIERDA                      //
        //                                                                    //

        // AQU� DENTRO METE EL C�DIGO DE LA HABITACI�N DE LA IZQUIERDA
        // ESTO LO HACE RUB�N.
        // LA HABITACI�N DE LA IZQUIERDA EST� SE�ALADA CON UNA CAJA ROJA EN MEDIO

        /*Box3D *caja_roja = new Box3D();
        caja_roja->x = 100;
        caja_roja->y = 100;
        caja_roja->z = 100;
        caja_roja->RecalculateMesh();
        caja_roja->color = new Color3D(1,0,0);

        caja_roja->translation->x = 190;
        caja_roja->translation->y = 190;

        _house->elements->push_back(caja_roja);*/

        Box3D *sueloIzq = new Box3D();
        sueloIzq->color = new Color3D(0,1,0);
        sueloIzq->x = 430;
        sueloIzq->y = 430;
        sueloIzq->z = 1;
        sueloIzq->translation->z = -1;
        sueloIzq->RecalculateMesh();
        _house->elements->push_back(sueloIzq);

        LeftRoomFurn *roomFurn = new LeftRoomFurn();
        roomFurn->translation->x = 150;
        roomFurn->translation->y = 150;
        _house->elements->push_back(roomFurn);

        /*Box3D *tele = new Box3D();
        tele->color = new Color3D(0,0,0);
        tele->x = 120;
        tele->y = 12;
        tele->z = 60;
        tele->translation->x = 250;
        tele->translation->y = 11;
        tele->translation->z = 100;
        tele->RecalculateMesh();*/
        Group3D *tele = new Group3D();
            Box3D *carcasa = new Box3D();
            carcasa->color = new Color3D(0,0,0);
            carcasa->x = 120;
            carcasa->y = 12;
            carcasa->z = 60;
            carcasa->RecalculateMesh();
        tele->elements->push_back(carcasa);
            _pantalla = new Box3D();
            _pantalla->color = new Color3D(0,0,0);
            _pantalla->x = 100;
            _pantalla->y = 0;
            _pantalla->z = 40;
            _pantalla->translation->x = 10;
            _pantalla->translation->y = 12.1;
            _pantalla->translation->z = 10;
            _pantalla->RecalculateMesh();

        tele->translation->x = 50;
        tele->translation->y = 0;
        tele->translation->z = 100;
        tele->elements->push_back(_pantalla);

        _house->elements->push_back(tele);

        Cylinder3D *lamp = new Cylinder3D(30, 10, 40, true, false);
        lamp->color = new Color3D(0,1,0);
        lamp->translation->x = 200;
        lamp->translation->y = 200;
        lamp->translation->z = 250;
        lamp->RecalculateMesh();
        _house->elements->push_back(lamp);


        //                                                                    //
        //                FIN HABITACI�N DE LA IZQUIERDA FIN                  //
        ////////////////////////////////////////////////////////////////////////




        ////////////////////////////////////////////////////////////////////////
        //                    HABITACI�N DE LA DERECHA                        //
        //                                                                    //

        // AQU� DENTRO METER EL C�DIGO DE LA HABITACI�N DE LA IZQUIERDA
        // ESTO LO HACE GERARDO.
        // LA HABITACI�N DE LA DERECHA EST� SE�ALADA CON UNA CAJA VERDE EN MEDIO

        /*
        Box3D *caja_verde = new Box3D();
        caja_verde->x = 100;
        caja_verde->y = 100;
        caja_verde->z = 100;
        caja_verde->RecalculateMesh();
        caja_verde->color = new Color3D(0,1,0);

        caja_verde->translation->x = 600;
        caja_verde->translation->y = 190;

        _house->elements->push_back(caja_verde);
        */

        // Suelo ///////////////////////////////////////////////////////////////
        Box3D *suelo = new Box3D();
        suelo->color = new Color3D(0.7,0.7,0.2);
        suelo->x = 450;
        suelo->y = 460;
        suelo->z = 1;
        suelo->RecalculateMesh();
        suelo->translation->x = 440;
        suelo->translation->z = -1;
        _house->elements->push_back(suelo);


        // Estanteria //////////////////////////////////////////////////////////
        Group3D *estanteria = new Group3D();
        estanteria->human_name = "Estanter�a";
        estanteria->translation->x = 560;
        estanteria->translation->y = 50;
        estanteria->rotation->z = 180;
        _house->elements->push_back(estanteria);

        Color3D *color_tabla = new Color3D(0.98,0.98,0.98);


        Box3D *tabla;

        tabla = new Box3D();
        tabla->color = color_tabla;
        tabla->x = 80;
        tabla->y = 40;
        tabla->z = 5;
        tabla->RecalculateMesh();
        tabla->translation->x = 0;
        tabla->translation->y = 0;
        tabla->translation->z = 0;
        estanteria->elements->push_back(tabla);

        tabla = new Box3D();
        tabla->color = color_tabla;
        tabla->x = 80;
        tabla->y = 40;
        tabla->z = 5;
        tabla->RecalculateMesh();
        tabla->translation->x = 0;
        tabla->translation->y = 0;
        tabla->translation->z = 145;
        estanteria->elements->push_back(tabla);

        tabla = new Box3D();
        tabla->color = color_tabla;
        tabla->x = 5;
        tabla->y = 40;
        tabla->z = 140;
        tabla->RecalculateMesh();
        tabla->translation->x = 0;
        tabla->translation->y = 0;
        tabla->translation->z = 5;
        estanteria->elements->push_back(tabla);

        tabla = new Box3D();
        tabla->color = color_tabla;
        tabla->x = 5;
        tabla->y = 40;
        tabla->z = 140;
        tabla->RecalculateMesh();
        tabla->translation->x = 75;
        tabla->translation->y = 0;
        tabla->translation->z = 5;
        estanteria->elements->push_back(tabla);

        tabla = new Box3D();
        tabla->color = color_tabla;
        tabla->x = 2;
        tabla->y = 40;
        tabla->z = 140;
        tabla->RecalculateMesh();
        tabla->translation->x = 39;
        tabla->translation->y = 0;
        tabla->translation->z = 5;
        estanteria->elements->push_back(tabla);


        tabla = new Box3D();
        tabla->color = color_tabla;
        tabla->x = 70;
        tabla->y = 40;
        tabla->z = 2;
        tabla->RecalculateMesh();
        tabla->translation->x = 5;
        tabla->translation->y = 0;
        tabla->translation->z = 38.5;
        estanteria->elements->push_back(tabla);

        tabla = new Box3D();
        tabla->color = color_tabla;
        tabla->x = 70;
        tabla->y = 40;
        tabla->z = 2;
        tabla->RecalculateMesh();
        tabla->translation->x = 5;
        tabla->translation->y = 0;
        tabla->translation->z = 74;
        estanteria->elements->push_back(tabla);

        tabla = new Box3D();
        tabla->color = color_tabla;
        tabla->x = 70;
        tabla->y = 40;
        tabla->z = 2;
        tabla->RecalculateMesh();
        tabla->translation->x = 5;
        tabla->translation->y = 0;
        tabla->translation->z = 109.5;
        estanteria->elements->push_back(tabla);



        // Libros sobre la estanter�a

        Box3D *libro;

        libro = new Box3D();
        libro->color = new Color3D(1,0,0);
        libro->human_name = "Linux Kernel Architecture Book";
        libro->x = 24;
        libro->y = 19;
        libro->z = 6;
        libro->RecalculateMesh();
        libro->translation->x = 8;
        libro->translation->y = 0;
        libro->translation->z = 150;
        estanteria->elements->push_back(libro);

        libro = new Box3D();
        libro->color = new Color3D(1,1,1);
        libro->human_name = "Core Java 2 Vol1";
        libro->x = 24;
        libro->y = 17;
        libro->z = 5;
        libro->RecalculateMesh();
        libro->translation->x = 7;
        libro->translation->y = 0;
        libro->translation->z = 156;
        estanteria->elements->push_back(libro);

        libro = new Box3D();
        libro->color = new Color3D(0.1,0.1,0.1);
        libro->human_name = "Ecuaciones Diferenciales";
        libro->x = 24;
        libro->y = 19;
        libro->z = 4;
        libro->RecalculateMesh();
        libro->translation->x = 8;
        libro->translation->y = 0;
        libro->translation->z = 161;
        estanteria->elements->push_back(libro);

        libro = new Box3D();
        libro->color = new Color3D(0,0,.5);
        libro->human_name = "Programming in C++";
        libro->x = 24;
        libro->y = 18;
        libro->z = 6;
        libro->RecalculateMesh();
        libro->translation->x = 7;
        libro->translation->y = 0;
        libro->translation->z = 165;
        estanteria->elements->push_back(libro);

        libro = new Box3D();
        libro->color = new Color3D(0,0.8,0);
        libro->human_name = "The Green Book";
        libro->x = 6;
        libro->y = 18;
        libro->z = 24;
        libro->RecalculateMesh();
        libro->translation->x = 33;
        libro->translation->y = 0;
        libro->translation->z = 150;
        libro->rotation->y = -4;
        estanteria->elements->push_back(libro);

        libro = new Box3D();
        libro->color = new Color3D(0.9,0.9,0.4);
        libro->human_name = "The Yellow Book";
        libro->x = 6;
        libro->y = 18;
        libro->z = 24;
        libro->RecalculateMesh();
        libro->translation->x = 39;
        libro->translation->y = 0;
        libro->translation->z = 150;
        libro->rotation->y = -4;
        estanteria->elements->push_back(libro);








        // Cama ////////////////////////////////////////////////////////////////
        Group3D *cama = new Group3D();
        cama->human_name = "Cama";
        cama->translation->x = 710;
        cama->translation->y = 195;
        cama->rotation->z = 180;
        _house->elements->push_back(cama);


        Group3D *somier = new Group3D();
        somier->color = new Color3D(0.2,0.2,0.2);
        somier->human_name = "Somier";
        cama->elements->push_back(somier);

        // Patas del somier:
        Box3D *pata;

        // Pata 1
        pata = new Box3D();
        pata->x = 5;
        pata->y = 5;
        pata->z = 25;
        pata->RecalculateMesh();
        pata->translation->x = 0;
        pata->translation->y = 10;
        somier->elements->push_back(pata);

        // Pata 2
        pata = new Box3D();
        pata->x = 5;
        pata->y = 5;
        pata->z = 25;
        pata->RecalculateMesh();
        pata->translation->x = 85;
        pata->translation->y = 10;
        somier->elements->push_back(pata);

        // Pata 3
        pata = new Box3D();
        pata->x = 5;
        pata->y = 5;
        pata->z = 25;
        pata->RecalculateMesh();
        pata->translation->x = 0;
        pata->translation->y = 165;
        somier->elements->push_back(pata);

        // Pata 4
        pata = new Box3D();
        pata->x = 5;
        pata->y = 5;
        pata->z = 25;
        pata->RecalculateMesh();
        pata->translation->x = 85;
        pata->translation->y = 165;
        somier->elements->push_back(pata);

        // Esqueleto del somier:
        pata = new Box3D();
        pata->x = 90;
        pata->y = 180;
        pata->z = 5;
        pata->RecalculateMesh();
        pata->translation->x = 0;
        pata->translation->y = 0;
        pata->translation->z = 25;
        somier->elements->push_back(pata);


        Box3D *colchon = new Box3D();
        colchon->x = 86;
        colchon->y = 176;
        colchon->z = 20;
        colchon->RecalculateMesh();
        colchon->color = new Color3D(0.91,0.9,0.8);
        colchon->translation->x = 2;
        colchon->translation->y = 2;
        colchon->translation->z = 30;
        cama->elements->push_back(colchon);


        Box3D *almohada = new Box3D();
        almohada->x = 86;
        almohada->y = 25;
        almohada->z = 15;
        almohada->RecalculateMesh();
        almohada->color = new Color3D(0.8,0.8,0.9);
        almohada->translation->x = 2;
        almohada->translation->y = 153;
        almohada->translation->z = 51;
        cama->elements->push_back(almohada);


        Box3D *cabecero = new Box3D();
        cabecero->x = 110;
        cabecero->y = 5;
        cabecero->z = 80;
        cabecero->RecalculateMesh();
        cabecero->color = color_tabla;
        cabecero->translation->x = -10;
        cabecero->translation->y = 180;
        cama->elements->push_back(cabecero);

        /*
        Box3D *piecero = new Box3D();
        piecero->x = 90;
        piecero->y = 5;
        piecero->z = 60;
        piecero->RecalculateMesh();
        piecero->color = color_tabla;
        piecero->translation->y = -5;
        cama->elements->push_back(piecero);
        */







        //                                                                    //
        //                FIN HABITACI�N DE LA DERECHA FIN                    //
        ////////////////////////////////////////////////////////////////////////


        /////////////////////////// GRUPO PUERTA ///////////////////////////////
        puerta = new Group3D();
                Box3D *madero = new Box3D();
                madero->color = new Color3D(0.545, 0.27, 0.0745);
                madero->x = 10;
                madero->y = 80;
                madero->z = 180;
                //madero->translation->x = 440;
                //madero->translation->y = 190;
                madero->RecalculateMesh();
        puerta->elements->push_back(madero);
                Sphere3D *pomo_izq = new Sphere3D();
                pomo_izq->color = new Color3D(0,0,0);
                pomo_izq->radius = 5;
                pomo_izq->translation->x = 15;
                pomo_izq->translation->y = 65;
                pomo_izq->translation->z = 80;
                pomo_izq->RecalculateMesh();
        puerta->elements->push_back(pomo_izq);
                Sphere3D *pomo_der = new Sphere3D();
                pomo_der->color = new Color3D(0,0,0);
                pomo_der->radius = 5;
                pomo_der->translation->x = -5;
                pomo_der->translation->y = 65;
                pomo_der->translation->z = 80;
                pomo_der->RecalculateMesh();
        puerta->elements->push_back(pomo_der);

                puerta->translation->x = 440;
                puerta->translation->y = 190;
        _house->elements->push_back(puerta);

        _scene->main_figure->elements->push_back(_house);
        _scene->Repaint();
}

String EventHouse::getName() {
        return "house";
}

bool EventHouse::event(ViewPort3D *_viewport, Scene3D *_scene, String type, WORD key, TShiftState shift) {
        if(key == 84) {

            if(_encendida) {
                _encendida = !_encendida;
                 delete _pantalla->color;
                _pantalla->color = new Color3D(0,0,0);
                _scene->Repaint();
            }
            else{
                _encendida = !_encendida;
                delete _pantalla->color;
                _pantalla->color = new Color3D(0,0,1);
                _scene->Repaint();
            }
            return true;
        }

        if(key == 80) {
                //double pi = 4*atan(1);
                if(_cerrada) {
                        _cerrada = !_cerrada;
                        //double inc_ang = 9;
                        for(int i=0; i<=10;i++) {
                                /*double ang = i*inc_ang;
                                puerta->rotation->x *= cos(ang);
                                puerta->rotation->y *= sin(ang);*/
                                puerta->rotation->z += 9;
                                _scene->Repaint();
                        }
                }
                else {
                        _cerrada = !_cerrada;
                        //double inc_ang = 9;
                        for(int i=0; i<=10;i++) {
                                /*double ang = i*inc_ang;
                                puerta->rotation->x *= cos(ang);
                                puerta->rotation->y *= sin(ang);*/
                                puerta->rotation->z -= 9;
                                _scene->Repaint();
                        }
                }
                return true;
        }
        return false;
}
