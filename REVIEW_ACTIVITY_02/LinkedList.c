#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void initList(List *list)
{
  (*list) = NULL;
  printf("SUCCESSFULLY INITIALIZED");
}

List newList()
{
  List list = NULL;
  
  return list;     
}

NodeType createNode(DATA data)
{
  NodeType nt;
       nt.data = data;
           
  return nt;
}

void displayList(List list)
{
     List i;
     for(i = list; i != NULL; i = i->next)
           {
               printf("%d " , i->data);
           } 
}

bool insertFront(List *list, DATA item)
{
     bool insert = false;
     NodeType nt;
     if(list == NULL)
        {
            List listNew;
            listNew = (List) malloc(sizeof(NodeType));
            
            if(listNew != NULL)
              {
                nt = createNode(item); 
                
                listNew->data = nt.data;
                listNew->next = NULL;
                (*list) = listNew;
                insert = true;
              }
        }
     else
        {
            List listNew, listPtr;
            listNew = (List) malloc(sizeof(NodeType));
            
            if(listNew != NULL)
            {
               nt = createNode(item);
               listNew->data = nt.data;
               listNew->next = NULL;
               listPtr = (*list);
               (*list) = listNew;
               (*list)->next = listPtr;
               insert = true;
             }   
        }
     return insert;
}

bool insertRear(List *list, DATA item)
{
     bool insert = false;
     NodeType nt;
     List tempList, listPtr;
     
     if(list == NULL)
        {
            List listNew;
            listNew = (List) malloc(sizeof(NodeType));
            
            if(listNew != NULL)
              {
                nt = createNode(item); 
                
                listNew->data = nt.data;
                listNew->next = NULL;
                (*list) = listNew;
                insert = true;
              }
        }
     else
        {
            for(tempList = (*list); tempList != NULL; tempList = tempList->next){}
            List listNew;
            listNew = (List) malloc(sizeof(NodeType));
            
            if(listNew != NULL)
              {
                nt = createNode(item); 
                listNew->data = nt.data;
                listNew->next = NULL;
                tempList = listNew;
                insert = true;
              }  
        }
     return insert;
}

/*bool insertAt(List *list, DATA item, int loc);
{
     bool insert = false;
     if(*list == NULL)
        {
            nt = createNode(item);
            (*list) = nt;
            insert = true;
        }
     else
         {
            
         }
     
}

bool insertSorted(List *list, DATA data); */

bool searchItem(List list, DATA key)
{
     bool search = false;
     List ptr;
     
     for(ptr = list; ptr != NULL; )
         {
             if(ptr->data == key)
                 {
                   search = true;
                   return search;
                 }
             else
                 {
                     ptr = ptr->next;
                 }
         }
     return search;
}

int getItem(List list, DATA key)
{
    List tempList;
    int data = -1;
    for(tempList = list; tempList != NULL; tempList = tempList->next)
       {
          if(tempList->data == key)
            {
               data = tempList->data;
               return data;          
            }
       }
    return data;
            
}

bool deleteFront(List *list)
{
     bool deleted = false;
     if(list != NULL)
       {
         List ptr;
         ptr = (*list);
         (*list) = (*list)->next;
         free(ptr); 
         deleted = true;
       }     
     return deleted;
}


bool deleteRear(List *list)
{
     List tempList, ptrList;
     bool deleted = false;
     if(list != NULL)
     {
        for(tempList = (*list); tempList != NULL; tempList = tempList->next)
           {
              ptrList = tempList;
           } 
         ptrList = NULL;
         free(tempList);
         deleted = true;
     }
     return deleted;
}

/*int deleteAt(List *list, int loc); */

bool deleteItem(List *list, DATA key)
{
     List tempList, tempPtr;
     bool deleted = false;
     if(list != NULL)
     {
        for(tempList = (*list); tempList != NULL; tempList = tempList->next)
          {
           if(tempList->data == key)
             {
               tempPtr = tempList;
               tempList = tempList->next;
               free(tempPtr);
               deleted = true;
               return deleted;
             }
         }         
     }
    return deleted;
}

int deleteAllItem(List *list, DATA key)
{
    List tempList, ptrList;
    int retval = 0;
    if(list != NULL)
     {
        for(tempList = (*list); tempList != NULL;)
         {
          if(tempList->data == key)
             {   
                ptrList = tempList;
                tempList = tempList->next;
                free(ptrList);  
                retval++;   
             }
          else
             {
                tempList = tempList->next;
             }
         }  
     }
    return retval;
}
