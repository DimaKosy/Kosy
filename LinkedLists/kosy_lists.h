/*
Author: Dmytro Kosynskyy
Last Update: 13/01/2023

A generalised linked list library
*/

#ifndef KOSY_LIST
#define KOSY_LIST

#include <stdio.h>

void KosyList_ReadList(void * h_ptr,void * print_struct(void*), void ** return_tail(void*));

int KosyList_Insert(void ** h_ptr, void * NewNode, void ** return_tail(void *));

int KosyList_Append(void ** h_ptr, void * NewNode, void ** return_tail(void *));

void KosyList_Remove(void ** h_ptr, void Delete(void *), void ** return_tail(void *));

void ** KosyList_Search(void ** h_ptr,int Compare(void *, void *), void * Target, void ** return_tail(void *));

void ** KosyList_Reverse(void ** h_ptr, void ** return_tail(void *));
#endif