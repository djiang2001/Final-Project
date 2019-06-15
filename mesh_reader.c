#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>

#include "string.h"
#include "matrix.h"
#include "draw.h"
#include "mesh_reader.h"

int read_mesh(char *path, struct mesh *ms) {

  struct matrix *mx, *face, *vert;

  mx = ms->point;
  face = ms->face;
  vert = ms->vert;
  
  FILE *f = fopen(path, "r");
  char *line = NULL;
  size_t read, len = 0;

  if (f == NULL)
    printf("Error: No such file exists\n");

  double d1[4], d2[3];
  int i1[4];
  i1[3] = 0;

  int count;
  while ((read = getline(&line, &len, f)) != -1) {    
    count = 0;
    
    char *s = strtok(line, " ");

    if(strcmp(s, "v") == 0) {

      // vertex code
      while((s = strtok(NULL, " ")) != NULL)
	d1[count++] = atof(s);      
      if (mx->lastcol == mx->cols)
	grow_matrix(mx, mx->lastcol + 100);
      mx->m[0][mx->lastcol] = d1[0];
      mx->m[1][mx->lastcol] = d1[1];
      mx->m[2][mx->lastcol] = d1[2];
      mx->m[3][mx->lastcol] = d1[3];
      mx->lastcol++;
    } else if (strcmp(s, "f") == 0) {
      
      // face code
      while((s = strtok(NULL, " ")) != NULL)
	i1[count++] = atoi(s);
      if (face->lastcol == face->cols)
	grow_matrix(face, face->lastcol + 100);
      face->m[0][face->lastcol] = (double)i1[0];
      face->m[1][face->lastcol] = (double)i1[1];
      face->m[2][face->lastcol] = (double)i1[2];
      face->m[3][face->lastcol] = (double)i1[3];
      face->lastcol++;
    } else if (strcmp(s, "vn") == 0) {

      //vert
      while((s = strtok(NULL, " ")) != NULL)
	d2[count++] = atof(s);
      if (vert->lastcol == vert->cols)
	grow_matrix(vert, vert->lastcol + 100);
      vert->m[0][vert->lastcol] = d2[0];
      vert->m[1][vert->lastcol] = d2[1];
      vert->m[2][vert->lastcol] = d2[2];
      vert->lastcol++;
    } else if (strcmp(s, "g") == 0) {
      

    }
  }

  fclose(f);
  
  if(line)
    free(line);
}

//To skip spaces
char *formatter(char *s) {
  s++;
  while(s[0] == ' ' || s[0] == '\t')
    s++;
}

  
