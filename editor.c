/*
 * Copyright (C) 2021 Biel A. P. - 0xbiel <biel@ugly.cat>
 * Author: Biel A. P. - 0xbiel <biel@ugly.cat>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "editor.h"

void 
editorNewFile(struct *editor ed, const char* fn) 
{
  ed -> fn = malloc(strlen(fn) + 1); 
  strncpy(ed -> fn, fn, strlen(fn) + 1);
  ed -> contents = malloc(0);
  ed -> clength = 0; 
}

void 
editorOpenFile(struct *editor ed, const char* fn) 
{
  FILE* filePath = fopen(fn, "rb"); /*opens the given file in read and binary mode "rb"*/

  if(filePath == NULL)
  {
    if(errno == ENOENT)
    {
      editorNewFile(ed, fn);
      return;
    }

    printf("Error: Could not open file.");
    exit(1);

    struct stat statBuffer; /*get file info through 'stat()'.*/
    if(stat(fn, &statBuffer) == -1)
    {
      printf("Error: Could not get file information.");
      exit(1);
    }

    /*check if the file is regular.*/
    if(!S_ISREG(statBuffer.st_mode))
    {
      fprintf(stderr, "Error: File %s is not a regular file\n", fn);
      exit(1);
    }

    char *contents;
    int contentLength = 0;

    if(statBuffer.st_size <= 0)
    {
      struct charBuffer *buffer = createCharBuffer()
      int c;
      char tempBuffer[1];
      while((c = fgetc(filePath)) != EOF)
      {
        tempBuffer[0] = (char) c;
        appendCharBuffer(buffer, tempBuffer, 1);
      }
      contents = buffer -> contents;
      contentLength = buffer -> len;
    }
    else
    {
      contents = malloc(sizeof(char) * statBuffer.st_size);
      contentLength = statBuffer.st_size;

      if(fread(contents, 1, statBuffer.st_size, filePath) < (size_t) statBuffer.st_size)
      {
        printf("Error: Unable to read file content.");
        free(contents);
        exit(1);
      }
    }

    /*duplicate string.*/
    ed -> fn = malloc(strlen(fn) + 1);
    strncpy(ed -> fn, fn, strlen(fn) + 1);
    ed -> contents = contents;
    ed -> clength = contentLength;

    /*check readonly file.*/
    if(access(fn, W_OK) == -1)
    {
      editorStatus(ed, WARNING, "\"%s\" (%d bytes) [readonly]", ed -> fn, ed -> clength);
    }
    else
    {
      editorStatus(ed, INFO, "\"%s\" (%d bytes)", ed -> fn, ed -> clength);
    }

    fclose(filePath);
  }
}

//@@@TODO: editorWrite() function.
