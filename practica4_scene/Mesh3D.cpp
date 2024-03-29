#include <vcl.h>
#pragma hdrstop
#include "Mesh3D.h"
#pragma package(smart_init)


Mesh3D::Mesh3D() {
        showNormals = false;
        filled = true;
        color = NULL;
        mode = 2;
        vertices = new list<Vertex3D*>();
        faces = new list<Face3D*>();
        textura = -1;
}

Mesh3D::~Mesh3D() {
        if (color != NULL)
                delete color;

        clearLists();
        delete faces;
        delete vertices;
}

void Mesh3D::clearLists() {
        // Borramos faces
        list<Face3D*>::iterator it_face;
        Face3D *face;
        for (it_face = faces->begin(); it_face != faces->end(); it_face++) {
                face = *it_face;
                delete face;
        }

        // Borramos vertices
        list<Vertex3D*>::iterator it_vertex;
        Vertex3D *vertex;
        for (it_vertex = vertices->begin(); it_vertex != vertices->end(); it_vertex++) {
                vertex = *it_vertex;
                delete vertex;
        }
        delete faces;
        delete vertices;

        vertices = new list<Vertex3D*>();
        faces = new list<Face3D*>();
}


void Mesh3D::RecalculateNormals() {

        
        // TODO: completar

        list<Face3D*>::iterator it_f;
        Face3D *f;
        for(it_f = faces->begin(); it_f != faces->end(); it_f++) {
                f = *it_f;
                double nx = 0, ny = 0, nz = 0; //Componentes del vector normal

                list<Vertex3D*>::iterator it;
                Vertex3D* v3d, *suc_v3d;
                //for(int j = 0; j < 3; j++) {  //3 deber�a ser el n�mero de v�rtices - 1 de la cara
                for(it = f->vertices->begin(); it != f->vertices->end(); it++) {
                        v3d = *it;
                        if(++it != f->vertices->end()) {
                                suc_v3d = *(it); //Le doy el siguiente
                                it--; //Pero una vez lo tengo, vuelvo a dejar donde estaba
                        }
                        else {
                                it--;
                                suc_v3d = *(f->vertices->begin());
                        }
                        nx += (v3d->y - suc_v3d->y)*(v3d->z + suc_v3d->z);
                        ny += (v3d->z - suc_v3d->z)*(v3d->x + suc_v3d->x);
                        nz += (v3d->x - suc_v3d->x)*(v3d->y + suc_v3d->y);
                }

                f->normal->x = nx;
                f->normal->y = ny;
                f->normal->z = nz;
                f->normal->t = 0;
                f->normal->normalize();

        } 
}

void Mesh3D::drawNormals() {

        list<Face3D*>::iterator it;
        Face3D* f;
        for(it = faces->begin(); it != faces->end(); it++) {
                f = *it;
                //Obtenemos el tama�o de la lista de v�rtices
                //Deber�a ser menor que 200, �no?
                int tam = (int)f->vertices->size();
                //Creamos la lista de los v�rtices
                Vertex3D** aux = new Vertex3D*[tam];
                int i = 0;

                double posX = 0, posY = 0, posZ = 0;



                list<Vertex3D*>::iterator it_v;
                for(it_v = f->vertices->begin(); it_v != f->vertices->end(); it_v++) {
                        aux[i] = *it_v;
                        posX = posX + aux[i]->x;
                        posY = posY + aux[i]->y;
                        posZ = posZ + aux[i]->z;
                        i++;
                }

                //C�lculo del punto medio de la cara
                posX /= tam;
                posY /= tam;
                posZ /= tam;

                delete[] aux;

                //Dibujo del vector normal
                glBegin(GL_LINES);
                glVertex3f(posX, posY, posZ);
                glVertex3f(posX + 20*f->normal->x,
                           posY + 20*f->normal->y,
                           posZ + 20*f->normal->z);
                glEnd();
        }

}


/*
void Mesh3D::Repaint() {
        // TODO: completar esto

        PV3D min(99999999,99999999,99999999);
        PV3D max(-99999999,-99999999,-99999999);





        glPushMatrix();

        glTranslated(translation->x, translation->y, translation->z);

        glRotated(rotation->x, 1,0,0);
        glRotated(rotation->y, 0,1,0);
        glRotated(rotation->z, 0,0,1);

        glScaled(scale->x, scale->y, scale->z);


        if(this->textura != -1){
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, this->textura);
        }


        list<Face3D*>::iterator it;
        Face3D *face;

        int i=0;
        for (it=faces->begin(); it != faces->end(); it++) {
                face = *it;
                if(filled) {
                        glBegin(GL_POLYGON);
                }
                else {
                        glBegin(GL_LINE_LOOP);
                }
                if (color != NULL)
                        glColor3f(color->r, color->g, color->b);

                list<Vertex3D*>::iterator itp;
                Vertex3D *vertex;
                int j=0;
                for (itp = face->vertices->begin(); itp != face->vertices->end(); itp++) {
                        vertex = *itp;
                        glNormal3f(face->normal->x, face->normal->y, face->normal->z);
                        if(((this->textura == 1))
                           || (i == 0 && (this->textura == 2))
                           || ((i >= 64 && i <= 79) && (this->textura == 3))){
                                switch(j) {
                                        case 0: glTexCoord2f(0.0,0.0);
                                                break;
                                        case 1: glTexCoord2f(1.0,0.0);
                                                break;
                                        case 2: glTexCoord2f(1.0,1.0);
                                                break;
                                        case 3: glTexCoord2f(0.0,1.0);
                                                break;
                                }
                        }
                        glVertex3f(vertex->x, vertex->y, vertex->z);
                        if (selected) {
                                if (min.x>vertex->x) min.x = vertex->x;
                                if (min.y>vertex->y) min.y = vertex->y;
                                if (min.z>vertex->z) min.z = vertex->z;
                                if (max.x<vertex->x) max.x = vertex->x;
                                if (max.y<vertex->y) max.y = vertex->y;
                                if (max.z<vertex->z) max.z = vertex->z;
                        }
                        j++;
                }
                i++;
                glEnd();
        }

        if(textura != -1)
                    glDisable(GL_TEXTURE_2D);


        if (selected) {
                double m = 1;
                min.x -= m;     min.y -= m;     min.z -= m;
                max.x += m;     max.y += m;     max.z += m;

                glBegin(GL_LINES);
                        glColor3f(0,1,0);
                        glVertex3f(min.x, min.y, min.z);
                        glVertex3f(max.x, min.y, min.z);
                        glVertex3f(min.x, min.y, min.z);
                        glVertex3f(min.x, max.y, min.z);
                        glVertex3f(min.x, min.y, min.z);
                        glVertex3f(min.x, min.y, max.z);

                        glVertex3f(max.x, max.y, max.z);
                        glVertex3f(min.x, max.y, max.z);
                        glVertex3f(max.x, max.y, max.z);
                        glVertex3f(max.x, min.y, max.z);
                        glVertex3f(max.x, max.y, max.z);
                        glVertex3f(max.x, max.y, min.z);

                        glVertex3f(max.x, max.y, min.z);
                        glVertex3f(min.x, max.y, min.z);
                        glVertex3f(max.x, max.y, min.z);
                        glVertex3f(max.x, min.y, min.z);

                        glVertex3f(min.x, min.y, max.z);
                        glVertex3f(max.x, min.y, max.z);
                        glVertex3f(min.x, min.y, max.z);
                        glVertex3f(min.x, max.y, max.z);

                        glVertex3f(max.x, min.y, min.z);
                        glVertex3f(max.x, min.y, max.z);

                        glVertex3f(min.x, max.y, min.z);
                        glVertex3f(min.x, max.y, max.z);



                glEnd();
        }

        if(showNormals) {
                drawNormals();
        }


        glPopMatrix();

}
*/




void Mesh3D::Repaint() {
        // TODO: completar esto

        PV3D min(99999999,99999999,99999999);
        PV3D max(-99999999,-99999999,-99999999);





        glPushMatrix();

        glTranslated(translation->x, translation->y, translation->z);

        glRotated(rotation->x, 1,0,0);
        glRotated(rotation->y, 0,1,0);
        glRotated(rotation->z, 0,0,1);

        glScaled(scale->x, scale->y, scale->z);


        list<Face3D*>::iterator it;
        Face3D *face;

        if(this->textura != -1){
                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D, this->textura);
        }

        int i = 0;
        for (it=faces->begin(); it != faces->end(); it++) {
                face = *it;
                if(filled) {
                        glBegin(GL_POLYGON);
                }
                else {
                        glBegin(GL_LINE_LOOP);
                }
                if (color != NULL)
                        glColor3f(color->r, color->g, color->b);

                list<Vertex3D*>::iterator itp;
                Vertex3D *vertex;
                int j = 0;
                for (itp = face->vertices->begin(); itp != face->vertices->end(); itp++) {
                        vertex = *itp;
                        glNormal3f(face->normal->x, face->normal->y, face->normal->z);
                        if((/*i == 1 && */(this->textura == 1))
                           || (i == 0 && (this->textura == 2))
                           || ((i >= 64 && i <= 79) && (this->textura == 3))){
                                switch(j) {
                                        case 0: glTexCoord2f(0.0,0.0);
                                                break;
                                        case 1: glTexCoord2f(1.0,0.0);
                                                break;
                                        case 2: glTexCoord2f(1.0,1.0);
                                                break;
                                        case 3: glTexCoord2f(0.0,1.0);
                                                break;
                                }
                        }
                        glVertex3f(vertex->x, vertex->y, vertex->z);
                        if (selected) {
                                if (min.x>vertex->x) min.x = vertex->x;
                                if (min.y>vertex->y) min.y = vertex->y;
                                if (min.z>vertex->z) min.z = vertex->z;
                                if (max.x<vertex->x) max.x = vertex->x;
                                if (max.y<vertex->y) max.y = vertex->y;
                                if (max.z<vertex->z) max.z = vertex->z;
                        }
                        j++;
                }
                i++;
                glEnd();
        }
        if(textura != -1) {
                    glDisable(GL_TEXTURE_2D);
                }

        if (selected) {
                double m = 1;
                min.x -= m;     min.y -= m;     min.z -= m;
                max.x += m;     max.y += m;     max.z += m;

                glBegin(GL_LINES);
                        glColor3f(0,1,0);
                        glVertex3f(min.x, min.y, min.z);
                        glVertex3f(max.x, min.y, min.z);
                        glVertex3f(min.x, min.y, min.z);
                        glVertex3f(min.x, max.y, min.z);
                        glVertex3f(min.x, min.y, min.z);
                        glVertex3f(min.x, min.y, max.z);

                        glVertex3f(max.x, max.y, max.z);
                        glVertex3f(min.x, max.y, max.z);
                        glVertex3f(max.x, max.y, max.z);
                        glVertex3f(max.x, min.y, max.z);
                        glVertex3f(max.x, max.y, max.z);
                        glVertex3f(max.x, max.y, min.z);

                        glVertex3f(max.x, max.y, min.z);
                        glVertex3f(min.x, max.y, min.z);
                        glVertex3f(max.x, max.y, min.z);
                        glVertex3f(max.x, min.y, min.z);

                        glVertex3f(min.x, min.y, max.z);
                        glVertex3f(max.x, min.y, max.z);
                        glVertex3f(min.x, min.y, max.z);
                        glVertex3f(min.x, max.y, max.z);

                        glVertex3f(max.x, min.y, min.z);
                        glVertex3f(max.x, min.y, max.z);

                        glVertex3f(min.x, max.y, min.z);
                        glVertex3f(min.x, max.y, max.z);



                glEnd();
        }

        if(showNormals) {
                drawNormals();
        }


        glPopMatrix();

}


String Mesh3D::getName() {
        return "Mesh";
}

