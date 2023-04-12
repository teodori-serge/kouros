#ifndef STORAGE_H
#define STORAGE_H

int storage_create(const char* name, int size);
int storage_delete(const char* name);
int storage_open(const char* name, void* address, int size);
//int storage_close(const char* name, void* address, int size);

#endif