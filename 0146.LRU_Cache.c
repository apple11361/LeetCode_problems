#include <stdio.h>
#include <stdlib.h>

typedef struct kv_store
{
    int val;
    int key;
    struct kv_store *prev;
    struct kv_store *next;
} kv_store_s;

typedef struct
{
    int max_capacity;
    int now_size;
    kv_store_s *map[3001];
    kv_store_s *head; // young
    kv_store_s *tail; // old
} LRUCache;


LRUCache *lRUCacheCreate(int capacity)
{
    LRUCache *temp = (LRUCache *)calloc(1, sizeof(LRUCache));

    temp->max_capacity = capacity;
    temp->now_size = 0;

   return temp;
}

int lRUCacheGet(LRUCache *obj, int key)
{
    kv_store_s *temp = obj->map[key];

    if(temp)
    {
        if(obj->head == temp)
        {
            return temp->val;
        }
        if(obj->tail == temp)
        {
            obj->tail = temp->prev;
            obj->head = temp;
            return temp->val;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next = obj->head;
        temp->next->prev = temp;
        temp->prev = obj->tail;
        temp->prev->next = temp;
        obj->head = temp;
       
        return temp->val;
    }

    return -1;
}

void lRUCachePut(LRUCache *obj, int key, int value)
{
    kv_store_s *temp = obj->map[key];

    if(temp)
    {
        temp->val = value;

        if(obj->head == temp)
        {
            return;
        }
        if(obj->tail == temp)
        {
            obj->tail = temp->prev;
            obj->head = temp;
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next = obj->head;
        temp->next->prev = temp;
        temp->prev = obj->tail;
        temp->prev->next = temp;
        obj->head = temp;
    }
    else
    {
        if(obj->now_size == obj->max_capacity) // evict
        {
            int evict_key;

            temp = obj->tail;
            evict_key = temp->key;

            temp->key = key;
            temp->val = value;

            obj->map[evict_key] = NULL;
            obj->map[key] = temp;

            obj->tail = temp->prev;
            obj->head = temp;
        }
        else
        {
            temp = (kv_store_s *)malloc(sizeof(kv_store_s));

            temp->key = key;
            temp->val = value;

            obj->now_size++;
            obj->map[key] = temp;

            if(obj->head)
            {
                obj->head->prev = temp;
                temp->next = obj->head;
                obj->tail->next = temp;
                temp->prev = obj->tail;
            }
            else
            {
                temp->next = temp;
                temp->prev = temp;
                obj->tail = temp;
            }
            obj->head = temp;
        }
    }
}

void lRUCacheFree(LRUCache *obj)
{
    
}

int main(int argc, char *argv[])
{
    LRUCache *cache = lRUCacheCreate(2);
    int temp;

    lRUCachePut(cache, 1, 1);
    lRUCachePut(cache, 2, 2);

    temp = lRUCacheGet(cache, 1);
    printf("%d\n", temp);

    lRUCachePut(cache, 3, 3);

    temp = lRUCacheGet(cache, 2);
    printf("%d\n", temp);

    lRUCachePut(cache, 4, 4);

    temp = lRUCacheGet(cache, 1);
    printf("%d\n", temp);

    temp = lRUCacheGet(cache, 3);
    printf("%d\n", temp);

    temp = lRUCacheGet(cache, 4);
    printf("%d\n", temp);

    lRUCacheFree(cache);

    return 0;
}

