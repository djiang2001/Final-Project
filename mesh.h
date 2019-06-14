#ifndef MESH_H
#define MESH_H

struct mesh{
  struct matrix *point;
  struct matrix *face;
  struct matrix *vert;
};

void free_mesh(struct mesh *);

#endif
