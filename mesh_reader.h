#ifndef MESH_READER_H
#define MESH_READER_H

#include "mesh.h"

int read_mesh(char *, struct mesh *);
//Will read from obj file and convert to coordinates of the mesh struct

char *formatter(char*);

#endif
