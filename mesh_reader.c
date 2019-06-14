#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>

#include "string.h"
#include "matrix.h"
#include "draw.h"
#include "mesh_reader.h"

int read_obj_file(char *path, struct mesh *ms) {

  struct matrix *mx, *face, *vert;

  mx = ms->point;
  face = ms->face;
  vert = ms->vert;
  
  FILE *f = fopen(path, "r");
  char *line = NULL;
  size_t read, len = 0;

  if (f == NULL)
    printf("Error: No such file exists\n");

}
  
