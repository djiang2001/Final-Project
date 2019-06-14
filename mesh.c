#include <stdlib.h>

#include "mesh.h"

void free_mesh(struct mesh *m){
  free(m->point);
  free(m->face);
  free(m->vert);
  free(m);
}
